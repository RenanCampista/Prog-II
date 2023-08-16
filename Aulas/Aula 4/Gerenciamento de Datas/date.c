#include "date.h"

tDate scanDate () {
    tDate date;

    printf("Informa a data no formato dd/mm/aaaa: ");
    scanf("%d/%d/%d", &date.day, &date.month, &date.year);
    cleanBuffer();
    return date;
}

void printDate (tDate date) {
    if (date.day < 10) {
        if (date.month < 10) 
            printf("\n0%d/0%d/%d\n", date.day, date.month, date.year);
        else
            printf("\n0%d/%d/%d\n", date.day, date.month, date.year);
    } else if (date.month < 10) 
        printf("\n%d/0%d/%d\n", date.day, date.month, date.year);
    else
        printf("\n%d/%d/%d\n", date.day, date.month, date.year);
}

int checkLeapYear (tDate date) {
    if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0) {
        return TRUE;
    }
    return FALSE;
}

int daysOfMonth (tDate date) {
    if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12 ) 
        return 31;
    else if (date.month == 2) {
        if (checkLeapYear(date) == TRUE) 
            return 29;
        else
            return 28;

    } else 
        return 30;
}

int distDays (tDate date1, tDate date2) {
    int yearToDays1, yearToDays2, monthToDays1 = 0, monthToDays2 = 0, i, totalDays1, totalDays2;
    yearToDays1 = (date1.year - 1) * 365;
    yearToDays2 = (date2.year - 1) * 365;
    
    if (date1.month > 1) {
        tDate aux;
        for (i = 1; i < date1.month - 1; i++) {
            aux.month = i;
            monthToDays1 += daysOfMonth(aux);
        }
    }

    if (date2.month > 1) {
        tDate aux;
        for (i = 1; i < date2.month - 1; i++) {
            aux.month = i;
            monthToDays2 += daysOfMonth(aux);
        }
    }

    totalDays1 = yearToDays1 + monthToDays1 + date1.day;
    totalDays2 = yearToDays2 + monthToDays2 + date2.day;
    return abs(totalDays1 - totalDays2);
}

int distMonths (tDate date1, tDate date2) {
    return abs(((date1.year - 1) * 12 + (date1.month)) - ((date2.year - 1) * 12 + (date2.month)));
}

int distYears (tDate date1, tDate date2) {
    return abs(date1.year - date2.year);
}

void nameMonth (tDate date) {
    switch (date.month) {
    case 1:
        printf("\nJaneiro\n");
        break;
    case 2:
        printf("\nFeveiro\n");
        break;
    case 3:
        printf("\nMarco\n");
        break;
    case 4:
        printf("\nAbril\n");
        break;
    case 5:
        printf("\nMaio\n");
        break;
    case 6:
        printf("\nJunho\n");
        break;
    case 7:
        printf("\nJulho\n");
        break;
    case 8:
        printf("\nAgosto\n");
        break;
    case 9:
        printf("\nSetembro\n");
        break;
    case 10:
        printf("\nOutubro\n");
        break;
    case 11:
        printf("\nNovembro\n");
        break;
    case 12:
        printf("\nDezembro\n");
        break;
    default:
        break;
    }
}

void compDate (tDate date1, tDate date2) {
    if (date1.day == date2.day  && date1.month == date2.month && date1.year == date2.year) 
        printf("\nAs datas informadas sao iguais\n");
    else
        printf("\nAs datas informadas sao diferentes\n");
}

tDate incrementDay  (tDate date) {
    if (date.day + 1 > daysOfMonth(date)) {
        if (date.month + 1 > 12) {
            date.day = 1;
            date.month = 1;
            date.year++;
        } else {
            date.day = 1;
            date.month++;
        }
    } else
        date.day++;
    
    return date;
}

void initializeDate () {
    //tDate date1, date2;
    int option;

    printf("\n\tBEM VINDO AO MINI GERENCIADOR DE DATAS\n");
    while (1) {
        printf("Escolha a opcao deseja:\n");
        printf("1 - Saber quantos dias tem determinado mes\n");
        printf("2 - Intervalo de dias entre duas datas\n");
        printf("3 - Intervalo de meses entre duas datas\n");
        printf("4 - Intervalo de anos entre duas datas\n");
        printf("5 - Nome do mes de acordo com numero dele\n");
        printf("6 - Comparar se duas datas sao iguais\n");
        printf("7 - Incrementar 1 dia a uma determinada data\n");
        printf("8 - Sair do programa\n");
        
        printf("Sua opcao: ");
        while (1) {
            scanf("%d", &option);
            cleanBuffer();

            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6 || option == 7 || option == 8) {
                break;
            }

            printf("\nPor favor, digite uma opcao valida: ");
        }

        if (option == 1) {
            printf("\nEsse mes tem %d dias\n", daysOfMonth(scanDate()));
        } else if (option == 2) {
            printf("\nA distancia e de %d dias\n", distDays(scanDate(), scanDate()));
        } else if (option == 3) {
            printf("\nA distancia e de %d meses\n", distMonths(scanDate(), scanDate()));
        } else if (option == 4) {
            printf("\nA distancia e de %d anos\n", distYears(scanDate(), scanDate()));
        } else if (option == 5) {
            printf("\nEsse mes corresponde a: ");
            nameMonth(scanDate());
        } else if (option == 6) {
            compDate(scanDate(), scanDate());
        } else if (option == 7) {
            printf("\nA nova data sera: ");
            printDate(incrementDay(scanDate()));
        } else break;
    }
}