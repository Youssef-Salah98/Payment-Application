#include <stdio.h>
#include <stdlib.h>
#include "app.h"

extern float maxAmount = 10000;
int TransNo;
void appStart(void){
    char Confirm;
    Card_ERR= &CardData;
    Terminal_ERR= &TerminalData;
    Server_ERR = &Transactions[TransNo];
    Terminal_check = getTransactionDate(Terminal_ERR);
    printf("Today is: %s \n",Terminal_ERR->transactionDate);
    Card_check = getCardHolderName(Card_ERR);
    if(Card_check == WRONG_NAME){
            printf("\nThe Name You Have Entered is WRONG, Please Try Again!");
            return 0;
    }
    Card_check = getCardExpiryDate(Card_ERR);
    if(Card_check == WRONG_EXP_DATE){
            printf("\nYour Card`s Expiration Data is WRONG, Please Try Again!");
            return 0;
    }
    Card_check = getCardPAN(Card_ERR);
    if(Card_check == WRONG_PAN){
            printf("\nWrong Permanent Account Number, Please Try Again!");
            return 0;
    }
    Terminal_check = isCardExpired(CardData, TerminalData);
    if(Terminal_check == EXPIRED_CARD){
        printf("Your Card Has Been Expired, Please Contact Your Bank!");
        return 0;
    }

    Terminal_check = getTransactionAmount(Terminal_ERR);
    if(Terminal_check == INVALID_AMOUNT)
    {
        printf("\nYour Transaction Amount is Invalid, Please Try Again!");
        return 0;
    }
    else{
        printf("\nProcessing ...\n");
    }
    Terminal_check = setMaxAmount(Terminal_ERR);
    if(Terminal_check == INVALID_MAX_AMOUNT){
        printf("\nMachine`s Maximum Amount is Invalid, Please Contact Your System Administrator!");
        return 0;
    }

    Terminal_check = isBelowMaxAmount(Terminal_ERR);
    if(Terminal_check == EXCEED_MAX_AMOUNT){
        printf("\nYour Amount Has Exceeded The Maximum Amount, Please Try Again!");
        return 0;
    }

    Server_check = recieveTransactionData(Server_ERR);
    if(Server_check == INTERNAL_SERVER_ERROR){
        printf("\nInternal Server Error, Please Try Again Later!");
        return 0;
    }
    else if(Server_check == DECLINED_STOLEN_CARD){
        printf("\nThis Account is Not Found, Please Try Again!");
        return 0;
    }
    else if(Server_check == DECLINED_INSUFFECIENT_FUND){
        printf("\nYou Don`t Have Sufficient Balance, Transaction Declined!");
        return 0;
    }

    Save_check = saveTransaction(Server_ERR);
    if(Save_check == SAVING_FAILED){
        printf("Transaction Saving Process Has been Failed, Please Contact Your Bank!");
        return 0;
    }
    else{
        printf("\n\nTransaction Saved!\n");
    }


    return 0;
}
