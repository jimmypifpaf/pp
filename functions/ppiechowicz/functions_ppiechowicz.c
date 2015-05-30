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
 ** wyswietlanie menu :: menu glowne
 **/

void ShowMenu_main(int show_headline) {

    int selected_option = 0; // wybrana opcja

    if(show_headline)
      {
            printf("\n\n---------------------------------------------\n");
            printf("**************** MENU GŁÓWNE ***************");
            printf("\n---------------------------------------------\n\n");

            printf("1. Zarządzanie lotami\n"
                   "2. Zarządzanie Klientami\n"
                   "3. Wyjscie z programu\n");
      }

    printf("---------------------------------------------\n"
            "Akcja: "
          );
    fflush(stdout);
    fflush(stdin);

    scanf("%d", &selected_option);
    printf("wybrano: %d\n", selected_option);

    switch( selected_option )
          {
              case 1 : ShowMenu_flights(1);
              break;

              case 2 : ShowMenu_clients(1);
              break;

              case 3 : exit_program = 1;
              break;

              default: printf("\nNieznana akcja!\n\n");
                       ShowMenu_main(0);
              break;
          }
}


/**
 ** wyswietlanie menu :: menu lotów
 **/

void ShowMenu_flights(int show_headline) {

    int selected_option = 0; // wybrana opcja

    if(show_headline)
      {
            printf("\n\n---------------------------------------------\n");
            printf("***************** MENU LOTÓW ****************");
            printf("\n---------------------------------------------\n\n");

            printf("1. Pokaż listę lotów\n"
                   "2. Pokaż szczegóły lotu\n"
                   "3. Dodaj lot\n"
                   "4. Edytuj lot\n"
                   "5. Usuń lot\n"
                   "6. Powrót do menu głównego\n"
                  );
      }

    printf("---------------------------------------------\n"
            "Akcja: "
          );
    fflush(stdout);
    fflush(stdin);

    scanf("%d", &selected_option);
    printf("wybrano: %d\n", selected_option);

    switch( selected_option )
          {
              case 1 : ShowMenu_flights_list(1);
                       ShowMenu_flights(1);
              break;

              case 2 : ;
              break;

              case 3 : ;
              break;

              case 4 : ;
              break;

              case 5 : ;
              break;

              case 6 : ;
              break;

              default: printf("\nNieznana akcja!\n\n");
                       ShowMenu_flights(0);
              break;
          }
}


/**
 ** wyswietlanie menu :: menu klientów
 **/

void ShowMenu_clients(int show_headline) {

    int selected_option = 0; // wybrana opcja

    if(show_headline)
      {
            printf("\n\n---------------------------------------------\n");
            printf("******************* KLIENCI *****************");
            printf("\n---------------------------------------------\n\n");

            printf("1. Pokaż listę Klientów\n"
                   "2. Powrót do menu głównego\n"
                   );
      }

    printf("---------------------------------------------\n"
            "Akcja: "
          );
    fflush(stdout);
    fflush(stdin);

    scanf("%d", &selected_option);
    printf("wybrano: %d\n", selected_option);

    switch( selected_option )
          {
              case 1 : ;
              break;

              case 2 : ;
              break;

              default: printf("\nNieznana akcja!\n\n");
                       ShowMenu_clients(0);
              break;
          }
}


/**
 ** wyswietlanie menu :: menu lista lotów
 **/

void ShowMenu_flights_list(int show_headline) {

    int selected_option = 0; // wybrana opcja

    if(show_headline)
      {
            printf("\n\n---------------------------------------------\n");
            printf("************** POKAŻ LISTĘ LOTÓW ************");
            printf("\n---------------------------------------------\n\n");

            printf("1. Pokaż wszystkie\n"
                   "2.       lot o podanym ID\n"
                   "3.       dzisiejsze loty\n"
                   "4.       loty z dnia...\n"
                   "5.       loty do miasta...\n"
                   "6. Wróć\n"
                   );
      }

    printf("---------------------------------------------\n"
            "Akcja: "
          );
    fflush(stdout);
    fflush(stdin);

    scanf("%d", &selected_option);
    printf("wybrano: %d\n", selected_option);

    loadDataFromFile(); // Funkcja Krzysztof Zemczak

    switch( selected_option )
          {
              case 1 : printAllFlights(); // Funkcja Krzysztof Zemczak
              break;

              case 2 : printFlightsWithId(); // Funkcja Krzysztof Zemczak
              break;

              case 3 : printFlightsWithDateToday(); // Funkcja Krzysztof Zemczak
              break;

              case 4 : printFlightsWithDate(); // Funkcja Krzysztof Zemczak
              break;

              case 5 : printFlightsWithCity(); // Funkcja Krzysztof Zemczak
              break;

              case 6 : ;
              break;

              default: printf("\nNieznana akcja!\n\n");
                       ShowMenu_flights_list(0);
              break;
          }
}
