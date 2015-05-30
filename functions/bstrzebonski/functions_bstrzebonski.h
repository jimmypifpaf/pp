/**
 ** Deklaracje funkcji
 ** Autor pliku : Bartłomiej Strzeboński
 **
 **/

// zabezpieczenie przed wielokrotnym wczytaniem pliku
#ifndef functions_bstrzebonski_h
#define functions_bstrzebonski_h

extern int exit_program;

/**
 ** Logowanie do systemu
 **/

void login(void);

/**
 ** Wyswietlenie ekranu powitalnego
 **/

void show_msg_welcome(void);

/**
 ** Wyswietlenie ekranu pozegnalnego
 **/

void show_msg_exit(void);

#endif
