#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "prompt.hpp"

static struct instruct INSTR[5] =
{
    {"display\n", &display},
    {"simulate\n", &simulate},
    {"loop\n", &loop},
    {NULL, NULL}
};



int check_command(char *command, char *filepath)
{
    int i = 0;

    while (i < 5) {
        if (strcmp(command, INSTR[i].instr) == 0) {
            INSTR[i].func(filepath);
            shell(filepath);
            return (SUCCESS);
        }
        i += 1;
        if (INSTR[i].instr == NULL)
            return (FAIL);
    }
    return (SUCCESS);
}
