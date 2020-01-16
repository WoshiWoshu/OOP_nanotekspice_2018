#include "parse.hpp"

int check_num(char *str)
{
    int i = 1;
    while (str[i]){
        if (str[i] < '0' || str[i] > '9')
            return (EXIT_FAILURE);
        i += 1;
    }
    return (EXIT_SUCCESS);
}

char *separate_first(char *str)
{
    int i = 0;
    char *temp;
    while (str[i] != '=')
        i++;
    temp = (char *)malloc(sizeof(char) *  (i + 1));
    if (!temp)
        return (NULL);
    temp = strncpy(temp , str, i - 1);
    return (temp);
}

int check_str(char *str)
{
    int i = 0;

    while (str[i]){
        if (str[i] < ' ' || str[i] > '~')
            return (EXIT_FAILURE);
        i += 1;
    }
    return (EXIT_SUCCESS);
}
