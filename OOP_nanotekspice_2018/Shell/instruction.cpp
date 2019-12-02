#include <stdio.h>
#include <signal.h>
#include "prompt.hpp"
#include "IComponent.hpp"


void display(char *filepath)
{
    (void) filepath;
}

void simulate(char *filepath)
{
    //initReadF(filepath);
}

void loop(char *filepath)
{
    while (42) {
        simulate(filepath);
        if (signal(SIGINT, stopsim)) {
            display(filepath);
            return;
        }
    }
}

void stopsim(int sig)
{
    if (sig == 2) {
        return ;
    }
}