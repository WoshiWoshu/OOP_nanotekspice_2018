#ifndef PARSE_HPP_
#define PARSE_HPP_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>


int nbr_world(char *);
int letter(char *);
int check(char );
char **epur_tab(char **);
char **my_str_to_wordtab(char *);
//strtowordtab

char *find_extension(char *);
bool check_circuitfile(char *);
bool check_value(int, char **);
int parse_args(int, char **);
//parse_args

void get_coor(int, char **);
//GeT_coordooneé



int check_num(char *);
char *separate_first(char *);
int check_str(char *);
int get_args(int, char **);
extern std::unordered_map<std::string, std::string> paramInput;


#endif 