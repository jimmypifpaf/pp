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
                drow_menu_main(1);
           }
    else if( strcmp(menu_name, "example") == 0 )
           {
                drow_menu_example1(1);
           }
    else
           {
                printf("nieznane menu [%s].", menu_name);
           }
    //printf("pokaż menu: %s", menu_name);
}

/**
 ** rysuj menu :: menu glowne
 **/

void drow_menu_main(int show_headline) {

    int selected_option = 0; // wybrana opcja

    if(show_headline)
      {
            printf("\n---------------------------------------------\n");
            printf("**************** MENU GŁÓWNE ***************");
            printf("\n---------------------------------------------\n\n");

            printf("1. Przegladaj przyloty.\n"
                   "2. Zamknij program.\n");
      }

    printf("Akcja: ");
    fflush(stdout);
    fflush(stdin);

    scanf("%d", &selected_option);
    printf("wybrano: %d", selected_option);

    switch( selected_option )
          {
              case 1 : printf("przegladaj przyloty.");
                       show_menu("example");
              break;

              case 2 : exit_program = 1;
              break;

              default: printf("\nNieznana akcja!\n");
                       drow_menu_main(0);
              break;
          }
}

/**
 ** rysuj menu :: przykladowe menu 1
 **/

void drow_menu_example1(int show_headline) {

    int selected_option = 0; // wybrana opcja

    if(show_headline)
      {
            printf("\n---------------------------------------------\n");
            printf("*************** MENU PRZYKŁADOWE **************");
            printf("\n---------------------------------------------\n\n");

            printf("1. Przegladaj przyloty.\n"
                   "2. Powrót do menu głównego.\n");
      }

    printf("Akcja: ");
    fflush(stdout);

    scanf("%d", &selected_option);
    printf("wybrano: %d", selected_option);

    switch( selected_option )
          {
              case 1 : printf("przegladaj przyloty.");
                       show_menu("example");
              break;

              case 2 : return;
              break;

              default: printf("\nNieznana akcja!\n");
                       drow_menu_example1(0);
              break;
          }
}

/**
 ** kolejne funkcje ...
 **/

