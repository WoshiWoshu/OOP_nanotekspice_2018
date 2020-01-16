#include "parse.hpp"

char *find_extension(char *file)
{
    int i = 0;
    int x = 0;
    char *sub = (char *)malloc(5);

    while (file[i] != '.')
        i++;
    while (file[i]) {
        sub[x] = file[i];
        x++;
        i++;
        }
    sub[x] = '\0';
    return (sub);
}

bool check_circuitfile(char *file)
{
    char *ext = find_extension(file);

    if (strcmp(ext,".nts") != 0)
        return (false);
    return (true);
}

bool check_value(int argc, char **argv)
{
    int i = 2;
    char *equal;

    while (i < argc){
        if (strstr(argv[i], "=") == NULL)
            return (false);
        else if (equal = strstr(argv[i], "=")) {
            if (check_num(equal) == EXIT_FAILURE) 
                return (false);
            if (check_str(separate_first(argv[1])) == EXIT_FAILURE) 
                return (false);
        }
        i++;
    }
    return (true);
}

int parse_args(int argc, char **argv)
{
    bool err_file; 
    bool err_value;
    int i = 2;

    err_file = check_circuitfile(argv[1]);
    if (err_file == false)
        return (EXIT_FAILURE);
    err_value = check_value(argc, argv);
    if (err_value == false)
        return (EXIT_FAILURE);    
    return (EXIT_SUCCESS);
}
