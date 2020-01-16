#include "parse.hpp"
#include <iostream>

std::unordered_map<std::string, std::string> paramInput(0);

void get_coor(int argc, char **argv)
{
    int i = 2;
    int x = 0;
    char **tab = (char **)malloc(sizeof(char *) * 2);
    std::unordered_map<std::string, std::string>::iterator it;

    while(i < argc){
        tab= my_str_to_wordtab(argv[i]);
        paramInput[tab[0]] = tab[1];
        i++;
    }
    for(it=paramInput.begin(); it != paramInput.end(); ++it)
    {
        std::cout<<it->first << std::endl << it->second <<std::endl;
    }
}