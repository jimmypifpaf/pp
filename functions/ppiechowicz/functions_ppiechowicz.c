/**
 ** Definicje funkcji
 ** Autor pliku : Piotr Piechowicz
 **
 **/

#include <stdio.h>
#include <string.h>

#include "functions_ppiechowicz.h"
#include "../bstrzebonski/functions_bstrzebonski.h"
#include "../jpieniazek/functions_jpieniazek.h"
#include "../kzemczak/functions_kzemczak.h"

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
 ** Logowanie do systemu
 **/

void login(void) {
    printf("funkcja logowania.\n");
}

/**
 ** wyswietlanie odpowiedniego menu
 **/

void show_menu(char *menu_name) {

    if( strcmp(menu_name, "main") == 0 )
           {
                drow_menu_main();
           }
    else if( strcmp(menu_name, "example") == 0 )
           {
                drow_menu_example1();
           }
    else
           {
                printf("nieznane menu [%s].", menu_name);
           }
    //printf("pokaż menu: %s", menu_name);
}

/**
 ** Oczekiwanie na wybranie pozycji menu
 ** - walidacja wprowadzonej cyfry
 **
 ** Funkcja zwraca wprowadzoną, sprawdzoną cyfrę [int]
 **/

int select_menu_option(int *possibility_vals, int posibility_vals_size) {
    int result, operation, c, i;

    do {
            result = scanf("%d", &operation);

            if( result )
              {
                  result = 0;
                  for( i = 0; i < posibility_vals_size; i++ )
                     {
                          if( operation == possibility_vals[i] )
                              result = 1;
                     }
              }

            if( !result )
              {
                  printf("Nieznana akcja! Prosze wpisać cyfrę podaną w menu.");
                  fflush(stdout);

                  // czyszczenie bufora znak po znaku
                  while( (c = getchar()) != '\n' && c != EOF );
              }
        } while( result != 1 );

    return operation;
}

/**
 ** rysuj menu :: menu glowne
 **/

void drow_menu_main(void) {

    int possibility_vals[] = { 1, 2 }, // tablica poprawnych wartosci, ktore moga zostac wprowadzone
            selected_option; // wybrana opcja

    printf("\n---------------------------------------------\n");
    printf("**************** MENU GŁÓWNE ***************");
    printf("\n---------------------------------------------\n\n");

    printf("1. Przegladaj przyloty.\n"
           "2. Zamknij program.\n");

    printf("Akcja: ");
    fflush(stdout);

    selected_option = select_menu_option(possibility_vals, sizeof(possibility_vals)); // oczekiwanie na wybranie opcji
    printf("wybrano: %d", selected_option); // tutaj zamiast printfa switch, który bedzie wywolywal odpowiednie funkcje, np. :

    switch( selected_option )
          {
              case 1 : printf("przegladaj przyloty.");
                       show_menu("example");
              break;

              case 2 : exit_program = 1;
              break;
          }
}

/**
 ** rysuj menu :: przykladowe menu 1
 **/

void drow_menu_example1(void) {

    int possibility_vals[] = { 1, 2 }, // tablica poprawnych wartosci, ktore moga zostac wprowadzone
        selected_option;               // wybrana opcja

    printf("\n---------------------------------------------\n");
    printf("************** PRZYKŁADOWE MENU **************");
    printf("\n---------------------------------------------\n\n");

    printf("1. Opcja 1.\n"
           "2. Opcja 2.\n");

    printf("Akcja: ");
    fflush(stdout);

    selected_option = select_menu_option(possibility_vals, sizeof(possibility_vals)); // oczekiwanie na wybranie opcji
    printf("wybrano: %d", selected_option); // tutaj zamiast printfa switch, który bedzie wywolywal odpowiednie funkcje.
}

/**
 ** kolejne funkcje ...
 **/

