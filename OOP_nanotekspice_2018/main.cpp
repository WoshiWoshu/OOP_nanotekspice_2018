/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include <iostream>
#include "ParserFileNts.hpp"

int main(int ac, char **av)
{
    (void)ac;
    initReadF(av[1]);
    std::cout << compoCollec["s"]->compute(1) << std::endl;
    
    return 0;
}
