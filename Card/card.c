#include <stdio.h>
#include <stdlib.h>
#include "card.h"



EN_cardError_t getCardHolderName(ST_cardData_t *cardData){
    printf("\nPlease Enter Your Name:\n");
    scanf("%[^\n]s",cardData->cardHolderName);
    int num =0;
    for(int i =0; i<=24; i++){
        if(cardData->cardHolderName[i] != NULL){
            num ++;
        }
        if(cardData->cardHolderName[i] == NULL){
            break;
        }
    }
    if (num<20 || num>24 )
    {
        return WRONG_NAME;
    }
    else{
        return OK;
    }
}


EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData){
    printf("\nPlease Enter Your Card`s Expiration Date (MM/YY):\n");
    scanf("%s",cardData->cardExpirationDate);
    int checkMonth = atoi(cardData->cardExpirationDate);
    if(checkMonth > 12){
        return WRONG_EXP_DATE;
    }
    int num =0;
    for(int i =0; i<=5; i++){
        if(cardData->cardExpirationDate[i] != NULL){
            num ++;
        }
        if(cardData->cardExpirationDate[i] == NULL){
            break;
        }
    }
    if (num != 5 || cardData->cardExpirationDate[2] != '/' )
    {
        return WRONG_EXP_DATE;
    }
    else{
        return OK;
    }
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData){
    printf("\nPlease Enter Your Account Number:\n");
    scanf("%s",cardData->primaryAccountNumber);
    int num =0;
    for(int i =0; i<=19; i++){
        if(cardData->primaryAccountNumber[i] != NULL){
            num ++;
        }
        if(cardData->primaryAccountNumber[i] == NULL){
            break;
        }
    }
    if (num<16 || num>19 )
    {
        return WRONG_PAN;
    }
    else{
        return OK;
    }

}


