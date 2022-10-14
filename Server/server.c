#include <stdio.h>
#include <stdlib.h>
#include "server.h"

int AccNum =0;
extern int TransNo = 0;
struct ST_accountsDB_t Accounts[255] = {
    {20000,  "1234567890123456789"},
    {7500,   "2134567890123456789"},
    {1500,   "1324567890123456789"}

};

struct ST_transaction_t Transactions[255] = {
    /*it will be automatically filled with 0s*/
};

EN_serverError_t isValidAccount(ST_cardData_t *cardData){
    for(int i=0,j=1; i<255; i++){
        j= strcmp(cardData->primaryAccountNumber, Accounts[i].primaryAccountNumber);
        if(j==0){
            AccNum = i;
            printf("\nAccount Has been Verified! Your Previous Balance = %0.2f\n",Accounts[i].balance);
            return OK2;
        }
    }
    return ACCOUNT_NOT_FOUND;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData){
    if(termData->transAmount <= Accounts[AccNum].balance){
        Accounts[AccNum].balance -= termData->transAmount;
        printf("\nTransaction Approved! \n\nYour New Balance is : %0.2f L.E", Accounts[AccNum].balance);
        return OK2;
    }
    else{
        return LOW_BALANCE;
    }
}



EN_serverError_t saveTransaction(ST_transaction_t *transData){
    if(TransNo > 254){
        return SAVING_FAILED;
    }
    else {
    Transactions[TransNo].cardHolderData = CardData;
    Transactions[TransNo].terminalData = TerminalData;
    Transactions[TransNo].transState = Server_check;
    Transactions[TransNo].transactionSequenceNumber = TransNo;
    TransNo ++;
    return OK2;
    }
}

EN_transState_t recieveTransactionData(ST_transaction_t *transData){
    if(TransNo > 254){
            return INTERNAL_SERVER_ERROR;
    }
    Card_check = isValidAccount(Card_ERR);
    if (Card_check == ACCOUNT_NOT_FOUND){
        return DECLINED_STOLEN_CARD;
    }
    Terminal_check = isAmountAvailable(Terminal_ERR);
    if (Terminal_check == LOW_BALANCE){
        return DECLINED_INSUFFECIENT_FUND;
    }
    return APPROVED;
}
