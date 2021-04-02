#include <SD.h>

#include "dataLog.h"

#include <stdio.h>

#include <ChRt.h>



// #include <string>
// #include <cstring>
// #include <sstream>

#define THREAD_DEBUG

MUTEX_DECL(SD_Card_Mutex);
static THD_FUNCTION(dataLogger_THD, arg){
  struct datalogger_THD *datalogger_struct = (struct datalogger_THD *)arg;
  while(true){
    #ifdef THREAD_DEBUG
        Serial.println("Data Logging thread entrance");
        Serial.println(datalogger_struct->sensor_type);
    #endif
    chSemWait(&datalogger_struct->fifoData);
    chMtxLock(&datalogger_struct->dataMutex);

    sensorDataStruct_t current_data = datalogger_struct->fifoArray[datalogger_struct->fifoTail];
    sensors sensorType = datalogger_struct->sensor_type;

    datalogger_struct->fifoTail = datalogger_struct->fifoTail < (FIFO_SIZE - 1) ? datalogger_struct->fifoTail + 1 : 0;
    chSemSignal(&datalogger_struct->fifoSpace);
    chMtxUnlock(&datalogger_struct->dataMutex);
    
    chMtxLock(&SD_Card_Mutex);
    logData(&datalogger_struct->dataFile, &current_data, sensorType);
    chMtxUnlock(&SD_Card_Mutex);

    #ifdef THREAD_DEBUG
        Serial.println(datalogger_struct->sensor_type);
        Serial.println("Data Logging thread exit");
    #endif

    chThdSleepMilliseconds(6);
  }
}



/**
 * @brief Creates the name for a file to be written to SD card.
 * 
 * @param fileName Pointer to char[] containing intended name of file. Do not include number or file extension at end of name. Make sure this is longer than it needs to be.
 * @param fileExtension Pointer to char[] containing the file extension for the file.
 * @return char* Pointer to inputted char[]. It now contains number (if duplicate file existed) and .csv file extension.
 */
char* sd_file_namer(char* fileName, char* fileExtensionParam) {
    
    char fileExtension[strlen(fileExtensionParam)+1];
    strcpy(fileExtension, fileExtensionParam);
    
    char inputName[strlen(fileName)+1];
    strcpy(inputName,fileName);
    
    strcat(fileName,fileExtension);    

    //checks to see if file already exists and adds 1 to filename if it does.
    if (SD.exists(fileName)){
        bool fileExists = false;
        int i = 1;
        while(fileExists==false){
            if(i > 999){
                //max number of files reached. Don't want to overflow fileName[]. Will write new data to already existing data999.csv
                strcpy(fileName, inputName);
                strcat(fileName, "999");
                strcat(fileName, fileExtension);
                break;
            }

            //converts int i to char[]
            char iStr[16];
            __itoa(i, iStr, 10);

            //writes "(sensor)_data(number).csv to fileNameTemp"
            char fileNameTemp[strlen(inputName)+strlen(iStr)+6];
            strcpy(fileNameTemp, inputName);
            strcat(fileNameTemp,iStr);
            strcat(fileNameTemp, fileExtension);

            if(!SD.exists(fileNameTemp)){
                strcpy(fileName, fileNameTemp);
                fileExists = true;
            }

            i++;
        }
    }

    // Serial.println(fileName);
    return fileName;
}


/**
 * @brief Logs data to 1 line of a specified .csv file on SD card.
 * 
 * @param dataFile File on SD card. Object from SD library.
 * @param data Data structure to be logged.
 * @param sensorType Enum containing the type of sensor. Controls which fields are logged.
 */
void logData(File* dataFile, sensorDataStruct_t* data, sensors sensorType) {
    // Write raw bytes to SD card.
    dataFile->write((const uint8_t *)data,sizeof(*data));

    // TODO: make it flush periodically as opposed to every time.
    dataFile->flush();
}