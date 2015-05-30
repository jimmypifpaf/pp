/**
 ** Deklaracje funkcji
 ** Autor pliku : Krzysztof Zemczak
 **
 **/

// zabezpieczenie przed wielokrotnym wczytaniem pliku
#ifndef functions_kzemczak_h
#define functions_kzemczak_h

extern int exit_program;

/**
 ** Krótki opis/nazwa funkcji. Opis danych wejsciowych i zwracanych
 **/

void loadDataFromFile(void);
void printFlight(int);
void printAllFlights(void);
void printFlightsWithId(void);
void printFlightsWithDateToday(void);
void printFlightsWithDate(void);
void printFlightsWithCity(void);




#endif
