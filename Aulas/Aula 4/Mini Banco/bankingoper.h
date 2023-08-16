#ifndef _BANKINGOPER_H
#define _BANKINGOPER_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constants.h"
#include "mytools.h"
#include "login.h"

typedef struct
{
    char socialName[60], dateBirth[12], cpf[15], telefhone[10], email[50], andress[80];
    int balance;
    unsigned short int activeAccount, accountNumber;
} tAccount;

int checkFreePosition (tAccount accounts[MAXACCOUNTS]);

int freePosition (tAccount accounts[MAXACCOUNTS]);

int generateAccNumber ();

void registerUser (tAccount accounts[MAXACCOUNTS]);

int searchAccount (tAccount accounts[MAXACCOUNTS]);

void deposit (tAccount accounts);

int checkWithdrawal (tAccount accounts, int value);

void withdraw (tAccount accounts);

void closeAccount (tAccount accounts);

void showData (tAccount account);

void initializeBank (tAccount accounts[MAXACCOUNTS]);


#endif