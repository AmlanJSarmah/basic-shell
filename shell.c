#include <unistd.h>
#include <stdio.h>
#include "./headers/shell.h"
#include "./headers/const.h"

void input_command(char* command){
    ssize_t ret = read(STD_IN, command, BUF_SIZE);
    if(ret == -1)
        perror("READ");
}

void execute_command(char *command, char **args){
    char* shell_built_in_commands[] = {"cd", "exit", "clear"};
}
