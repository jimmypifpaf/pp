/**
 ** Definicje funkcji
 ** Autor pliku : Bartłomiej Strzeboński
 **
 **/

#include <stdio.h>
#include <string.h>

#include "functions_bstrzebonski.h"
#include "../ppiechowicz/functions_ppiechowicz.h"
#include "../jpieniazek/functions_jpieniazek.h"
#include "../kzemczak/functions_kzemczak.h"

/**
 ** Logowanie do systemu
 **/

void login()
{
    char username[15], password[25], pass[25], usr[15];
    int bingo = 0;

    FILE *passcode;
    if ((passcode = fopen( DB_PATH "passcode.txt","r")) == NULL)
    {
        printf ("plik porównawczy nie znaleziony");
        fflush(stdout);
        exit_program = 1;
    }
    else
    {
            printf("login :    \n");
            fflush(stdout);

            scanf ("%14s", username);
            fflush(stdin);

            printf ("hasło :    \n");
            fflush(stdout);

            scanf ("%24s", password);
            fflush(stdin);

            while (fscanf(passcode, "%14s %24s", usr, pass) != EOF)
            {
                if(strcmp(usr, username) == 0 && strcmp(pass, password) == 0)
                {
                    bingo = 1;
                    break;
                }
            }
            if (bingo != 1)
            {
               printf("niepoprawny login lub haslo\n");
               fflush(stdout);
               login();
            }
    }
    fclose(passcode);
}

/**
 ** Wyswietlenie ekranu powitalnego
 **/

void show_msg_welcome(void) {
    printf("Witamy w systemie Airline! \n\nAby kontynuować prosimy podać hasło dostępu:\n");
}

/**
 ** Wyswietlenie ekranu pozegnalnego
 **/

void show_msg_exit(void) {
    printf("\nBye, bye! :)");
}

/**
 ** kolejne funkcje ...
 **/

