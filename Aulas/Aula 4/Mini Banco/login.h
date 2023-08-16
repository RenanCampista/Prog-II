#ifndef _LOGIN_H
#define _LOGIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constlogin.h"
#include "mytools.h"

typedef struct login {
    char userName[20], password[10];
    short int activeUser;
} tLogin;

int adminOperation ();

int usernameAvaibility (char name[20], tLogin users[CAPACITY]);

int freePositionLo (tLogin users[CAPACITY]);

int searchUser (char name[20], tLogin users[CAPACITY]);

void registerUserLo (tLogin users[CAPACITY], int pos);

void retireUser (tLogin users[CAPACITY]);

void passwordRecovey (tLogin users[CAPACITY]);

int initializeLogin (tLogin users[CAPACITY]);


#endif