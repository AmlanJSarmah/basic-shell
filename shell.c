#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "./headers/shell.h"
#include "./headers/const.h"
#include "./headers/shell_commands.h"

void input_command(char* command){
    ssize_t ret = read(STD_IN, command, BUF_SIZE);
    if(ret == -1){
        perror("READ");
        exit(1);
    }
    command[ret - 1] = '\0';
}

void execute_process(char *command, char **args){
    pid_t pid = fork();
    if(pid == -1){
        perror("FORK");
        exit(1);
    }
    else if(pid == 0){
        if(execvp(command,args) == -1){
            perror("EXEC\n");
        }
        exit(0);
    }
    else{
        wait(NULL);
        return;
    }
}

void execute_command(char *command, char **args){
    int command_no = -1;
    char* shell_built_in_commands[NUMBER_OF_SHELL_COMMANDS] = {"cd", "exit", "clear"}; 
    for(int i = 0; i < NUMBER_OF_SHELL_COMMANDS; i++){
        if(strcmp(command, shell_built_in_commands[i]) == 0){
            command_no = i;
            break;
        }
    }
    if(command_no == 0){
        cd(args);
    }
    else if(command_no == 1){
        exit(0);
    }
    else if(command_no == 2){
        clear();
    }
    else{
        execute_process(command, args);
    }
}
