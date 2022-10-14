#ifndef CARD_H
#define CARD_H

typedef unsigned char uint8_t;

typedef struct ST_cardData_t
{
uint8_t cardHolderName[25];
uint8_t primaryAccountNumber[20];
uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef enum EN_cardError_t
{
OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);

ST_cardData_t* Card_ERR;
ST_cardData_t CardData;
EN_cardError_t Card_check;

#endif // CARD_H
