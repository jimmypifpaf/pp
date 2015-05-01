#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "functions/ppiechowicz/functions_ppiechowicz.h"
#include "functions/bstrzebonski/functions_bstrzebonski.h"
#include "functions/jpieniazek/functions_jpieniazek.h"
#include "functions/kzemczak/functions_kzemczak.h"

int exit_program = 0;

int main(void) {

    show_msg_welcome();
    login();

    function_bartek();
    function_jarek();
    function_krzysiek();

    while( !exit_program )
         {
            show_menu("main");
         }

    show_msg_exit();
    return 0;
}
