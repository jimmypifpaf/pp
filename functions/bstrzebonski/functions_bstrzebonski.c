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


// dodac mozliwosc zmiany hasla
// ograniczenie mozliwosci wpisania wiecej znakow niz jest przewidziane


void login()
{
	char username[25], password[15], pass, usr, ch;
	int i;

	FILE *passcode;
	if ((passcode = fopen("passcode.txt","r")) == NULL)
	{
		printf ("plik porównawczy nie znaleziony");
		exit(1);
	}
	else
	{
			while (fscanf (passcode, "%s", usr) != EOF)

			printf("login :    \n");
			scanf ("%s", username);
			printf ("hasło :    \n");
			scanf("%s", password);

			//prototyp "zagwiazdkowania" hasla
			 /*while (ch != '\n')
			{
				password[i] = ch;
				i++;
				printf("*");
				if (i >= 25)
					{
						break;
					}
			}
			password[i]="\0"; */

			if (username==usr)
			{
				if(password==pass)
				{
				printf ("Witamy\n");
				//przejście do jakiegoś menu wyboru
				}
			}
			else
			{
				printf ("Podany login lub hasło jest błędny, spróbuj ponownie\n");
				login();
			}


	}
}




/**
 ** kolejne funkcje ...
 **/

