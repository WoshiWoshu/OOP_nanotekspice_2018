#include "parse.hpp"

void display_result(char **tab)
{
    int i = 0;

    while (tab[i]){
        printf("result  = %s\n",tab[i]);
        i++;
    }
}

int get_args(int argc, char **argv)
{
    int err_value;
    int i = 0;


    if (argc < 2) {
        dprintf(2, "Please follow --help\n");
        return (EXIT_FAILURE);
    }
    err_value = parse_args(argc, argv);
    if (err_value == EXIT_FAILURE)
        return (84);

    get_coor(argc, argv);
    return (0);
}