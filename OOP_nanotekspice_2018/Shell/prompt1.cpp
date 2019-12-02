#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "prompt.hpp"


void display_prompt(void)
{
    write(1,"> ",1);
}
// fonction pour display >

void intHandler(int sig)
{
    if (sig == 2)
        exit(0);
}

int shell(char *filepath)
{
    int status = CONTINUE;
    char *command;
    const int cin = 0;

    signal(SIGINT, intHandler); //gestion du CTRL+C
    simulate();
    display(filepath);
    display_prompt();
    while (status != EXIT_FAILURE && status != EXIT_SUCCESS) {
        command = get_next_line(0);
        if (command == NULL)
            exit(EXIT_FAILURE);
        if (*command == '\n') // ENter gestion 
            shell();
        if (check_command(command) == FAIL) // tableau de pointeur sur fonctions
            {
                dprintf(2 ,"Wrong instruction please follow nanotekspice --help \n"); // si mauvaise commande
                status = EXIT_FAILURE;
                exit(EXIT_FAILURE);
            }
        if (strcmp(command, "exit\0") == 0) // exit command
            status = EXIT_SUCCESS;
    }
    return (status);
}
//fonction du prompt


int main(void)
{
    if (shell() == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (0);
}

