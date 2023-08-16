#ifndef _DATE_H
#define _DATE_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "constants.h"
#include "mytools.h"

typedef struct {
    int day, month, year;
} tDate;

tDate scanDate ();

void printDate (tDate date);

int checkLeapYear (tDate date);

int daysOfMonth (tDate date);

int distDays (tDate date1, tDate date2);

int distMonths(tDate date1, tDate date2);

int distYears (tDate date1, tDate date2);

void nameMonth (tDate date);

void compDate (tDate date1, tDate date2);

tDate incrementDay (tDate date);

void initializeDate ();


#endif