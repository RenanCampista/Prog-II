#ifndef _LOGIN_H
#define _LOGIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constlogin.h"
#include "My tools/mytools.h"

typedef struct login {
    char userName[20], password[10];
    short int activeUser;
} tLogin;

int adminOperation ();

int usernameAvaibility (char name[20], tLogin users[CAPACITY]);

int freePosition (tLogin users[CAPACITY]);

int searchUser (char name[20], tLogin users[CAPACITY]);

void registerUser (tLogin users[CAPACITY], int pos);

void retireUser (tLogin users[CAPACITY]);

void passwordRecovey (tLogin users[CAPACITY]);

int initializeLogin (tLogin users[CAPACITY]);


#endif