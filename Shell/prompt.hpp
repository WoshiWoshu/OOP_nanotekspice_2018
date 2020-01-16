

#ifndef PROMPT_HPP_
#define PROMPT_HPP_
#define SUCCESS 0
#define FAIL -1
#define EXIT_SUCCESS 0
#define CONTINUE 42


struct instruct
{
    const char *instr;
    void (*func)(char *);
};

int shell(char *);
int check_command(char *command, char *);
void display(char *);
void simulate(char *);
void loop(char *);
void intHandler(int);
char *get_next_line(const int);


#endif 