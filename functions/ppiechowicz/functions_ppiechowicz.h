/**
 ** Deklaracje funkcji
 ** Autor pliku : Piotr Piechowicz
 **
 **/

// zabezpieczenie przed wielokrotnym wczytaniem pliku
#ifndef functions_ppiechowicz_h
#define functions_ppiechowicz_h

extern int exit_program;

/**
 ** Wyswietlenie ekranu powitalnego
 **/

void show_msg_welcome(void);

/**
 ** Wyswietlenie ekranu pozegnalnego
 **/

void show_msg_exit(void);

/**
 ** Logowanie do systemu
 **/

void login(void);

/**
 ** Oczekiwanie na wybranie pozycji menu
 **/

int select_menu_option(int *possibility_vals, int possibility_vals_size);

/**
 ** wyswietlanie menu
 **/

void show_menu(char *menu_name);

/**
 ** rysuj menu :: menu glowne
 **/

void drow_menu_main(void);

/**
 ** rysuj menu :: przykladowe menu 1
 **/

void drow_menu_example1(void);

/**
 ** kolejne funkcje ...
 **/

#endif
