#ifndef _MANBOOKS_H
#define _MANBOOKS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "mytools.h"


typedef struct library {
    char title[50], author[50];
    int pubYear, availbility;
} tLibrary;

int forceOption (int val1, int val2);

int freePositionBook (tLibrary books[CAPACITY]);

void registerBook (tLibrary books[CAPACITY]);

void removeBook (tLibrary books[CAPACITY], int pos);

int searchBook (tLibrary books[CAPACITY]);

void printBooks (tLibrary books[CAPACITY], int pos);

void loanBook (tLibrary books[CAPACITY], int pos);

void bookReturn (tLibrary books[CAPACITY], int pos);

void printAllBooks (tLibrary books[CAPACITY]);

void initializeLibrary ();

#endif