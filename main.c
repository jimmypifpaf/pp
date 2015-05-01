#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "functions/functions.h"

int exit_program = 0;

int main(void) {

    show_msg_welcome();
    login();

    while(!exit_program)
         {
    	       show_menu("main");
         }

    show_msg_exit();
    return 0;
}
