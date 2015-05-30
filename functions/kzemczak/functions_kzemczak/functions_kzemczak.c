/**
 ** Definicje funkcji
 ** Autor pliku : Krzysztof Zemczak
 **
 **/

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "functions_kzemczak.h"
#include "../bstrzebonski/functions_bstrzebonski.h"
#include "../jpieniazek/functions_jpieniazek.h"
#include "../ppiechowicz/functions_ppiechowicz.h"

/**
 ** Krótki opis/nazwa funkcji. Opis danych wejsciowych i zwracanych
 **/

struct flight{
    char flight_id[20];
    char flight_from[50];
    char flight_to[50];
    char flight_start_date[11];
    char flight_start_time[6];
    char flight_finish_date[11];
    char flight_finish_time[6];
    char flight_max_seats[20];
    //int flight_status[20];

    //char test[255];
} Tab[200];
int number_of_flights;

void loadDataFromFile()
{
   number_of_flights=0;
   int i;
   static const char filename[] = DB_PATH "flights_db.txt";
   FILE *file = fopen ( filename, "r" );
   if ( file != NULL )
   {

        for(i=0; i<200; ++i)
        {
           if (fscanf(file, "%[^;;];;%[^;;];;%[^;;];;%[^;;];;%[^;;];;%[^;;];;%[^;;];;%s\n",
            Tab[i].flight_id,
            Tab[i].flight_from,
            Tab[i].flight_to,
            Tab[i].flight_start_date,
            Tab[i].flight_start_time,
            Tab[i].flight_finish_date,
            Tab[i].flight_finish_time,
            Tab[i].flight_max_seats) <=0)
             break;
             ++number_of_flights;


        }
      fclose ( file );
   }
   else
   {
      perror ( filename ); /* why didn't the file open? */
      exit_program = 1;
   }
}

void printFlight(int struct_id)
{
   printf("Lot nr %s z %s do %s.\n", Tab[struct_id].flight_id, Tab[struct_id].flight_from, Tab[struct_id].flight_to);
   printf("Odlot z %s w dniu %s o godz. %s\n", Tab[struct_id].flight_from, Tab[struct_id].flight_start_date, Tab[struct_id].flight_start_time);
   printf("Przylot do %s w dniu %s o godz. %s\n", Tab[struct_id].flight_to, Tab[struct_id].flight_finish_date, Tab[struct_id].flight_finish_time);
   printf("Maksymalna liczba miejsc: %s\n\n", Tab[struct_id].flight_max_seats);
}

void printAllFlights()
{
     int i;
     for(i=0; i<number_of_flights; ++i)
        {
           printFlight(i);
        }
}

void printFlightsWithId()
{

     // pobieranie id
     char id[255];
     printf("Enter the flight number: ");
     fflush(stdout);
     scanf("%s", id);
     printf("\n");

     int anything_found=0;
     int i;
     for(i=0; i<number_of_flights; ++i)
        {
           if (strcmp(id, Tab[i].flight_id) ==0) //strings match
           {
              printFlight(i);
              anything_found=1;
           }
        }
     if (anything_found == 0)
        printf("No flights were found with id = %s\n\n",id);
}

void printFlightsWithDateToday()
{
     time_t t = time(NULL);
     struct tm tm = *localtime(&t);
     char str[11];
     sprintf(str,"%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

     int anything_found=0;
     int i;
     for(i=0; i<number_of_flights; ++i)
        {
           if (   (strcmp(str, Tab[i].flight_start_date) ==0)  //date matched with start date
               || (strcmp(str, Tab[i].flight_finish_date) ==0)) //date matched with end date
           {
              printFlight(i);
              anything_found=1;
           }
        }
     if (anything_found == 0)
        printf("No flights were found for date = %s\n\n", str);
}

void printFlightsWithDate()
{
     char date[255];
     printf("Enter the date you want to show flights on (format yyyy-mm-dd): ");
     fflush(stdout);
     scanf("%s", date);
     printf("\n");

     int anything_found=0;
     int i;
     for(i=0; i<number_of_flights; ++i)
        {
           if (   (strcmp(date, Tab[i].flight_start_date) ==0)  //date matched with start date
               || (strcmp(date, Tab[i].flight_finish_date) ==0)) //date matched with end date
           {
              printFlight(i);
              anything_found=1;
           }
        }
     if (anything_found == 0)
        printf("No flights were found for date = %s\n\n", date);
}

void printFlightsWithCity()
{
     char city[255];
     printf("Enter the city name: ");
     fflush(stdout);
     scanf("%s", city);
     printf("\n");

     int anything_found=0;
     int i;
     for(i=0; i<number_of_flights; ++i)
        {
           if (   (strcmp(city, Tab[i].flight_from) ==0)  //date matched with start date
               || (strcmp(city, Tab[i].flight_to) ==0)) //date matched with end date
           {
              printFlight(i);
              anything_found=1;
           }
        }
     if (anything_found == 0)
        printf("No flights were found for city = %s\n\n", city);
}


