/**
 ** Deklaracje funkcji
 ** Autor pliku : Piotr Piechowicz
 **
 **/

// zabezpieczenie przed wielokrotnym wczytaniem pliku
#ifndef functions_ppiechowicz_h
#define functions_ppiechowicz_h

// polozenie plikow bazy danych
#define DB_PATH "data/"

extern int exit_program;

/**
 ** wyswietlanie menu :: menu glowne
 **/

void ShowMenu_main(int);


/**
 ** wyswietlanie menu :: menu lotów
 **/

void ShowMenu_flights(int);


/**
 ** wyswietlanie menu ::  menu lista lotów
 **/

void ShowMenu_flights_list(int);


/**
 ** wyswietlanie menu :: menu klientów
 **/

void ShowMenu_clients(int);

#endif
