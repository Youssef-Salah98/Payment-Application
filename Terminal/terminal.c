#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "terminal.h"

float maxAmount;
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData){
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(termData->transactionDate,"%d/%d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    return OK1;

}

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData){
    uint8_t temp[4] = {0,0,NULL,NULL};
    for (int i=0; i<2; i++){
        temp[i] = cardData.cardExpirationDate[i+3];
    }
    int EXPYear = atoi(temp) +2000;
    for (int i=0; i<4; i++){
        temp[i] = termData.transactionDate[i+5];
    }
    int CurrentYear = atoi(temp);
    for (int i=0; i<4; i++){
    temp[i] = NULL;
    }
    for (int i=0; i<2; i++){
    temp[i] = cardData.cardExpirationDate[i];
    }
    int EXPmonth = atoi(temp);
    for (int i=0; i<2; i++){
    temp[i] = termData.transactionDate[i+3];
    }
    int CurrentMonth = atoi(temp);

    if(CurrentYear > EXPYear){
        return EXPIRED_CARD;
    }
    else if (CurrentYear == EXPYear && EXPmonth <= CurrentMonth){
        return EXPIRED_CARD;
    }
    else{
        return OK1;
    }

}

EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData){
    printf("\nPlease Enter The Transaction Amount..\n");
    scanf("%f", &termData->transAmount);
    if(termData->transAmount <= 0){
        return INVALID_AMOUNT;
    }
    else{
        return OK1;
    }
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData){
    printf("\nPlease Enter Your Bank`s Maximum Transaction Amount:\n");
    scanf("%f",&maxAmount);
    termData->maxTransAmount = maxAmount;
    if(termData->maxTransAmount <= 0){
        return INVALID_MAX_AMOUNT;
    }
    else{
        return OK1;
    }
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData){
    if (termData->transAmount > termData->maxTransAmount){
        return EXCEED_MAX_AMOUNT;
    }
    else{
        return OK1;
    }
}


