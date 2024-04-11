#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <ctype.h>
#include "./headers/shell.h"
#include "./headers/const.h"
#include "./headers/shell_commands.h"

void set_signal(){
   if(signal(SIGINT, SIG_IGN) == SIG_ERR){
       perror("SIG:");
       exit(EXIT_FAILURE);
   }
   if(signal(SIGQUIT, SIG_IGN) == SIG_ERR){
       perror("SIG:");
       exit(EXIT_FAILURE);
   }
   if(signal(SIGTSTP, SIG_IGN) == SIG_ERR){
       perror("SIG:");
       exit(EXIT_FAILURE);
   }
}

void input_command(char* command){
    ssize_t ret = read(STDIN_FILENO, command, BUF_SIZE);
    if(ret == -1){
        perror("READ");
        exit(EXIT_FAILURE);
    }
    command[ret - 1] = '\0';
}

void execute_process(char *command, char **args){
    pid_t pid = fork();
    if(pid == -1){
        perror("FORK");
        exit(EXIT_FAILURE);
    }
    else if(!pid){
        if(execvp(command,args) == -1){
            perror("EXEC ");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    else{
        int status;
        wait(&status);
        if(WIFEXITED(status))
            errno = status;
    }
}

void execute_command(char *command, char **args){
    int command_no = -1;
    char* shell_built_in_commands[NUMBER_OF_SHELL_COMMANDS] = {"cd", "exit", "clear", "\0"}; 
    for(int i = 0; i < NUMBER_OF_SHELL_COMMANDS; i++){
        if(strcmp(command, shell_built_in_commands[i]) == 0){
            command_no = i;
            break;
        }
    }
    switch(command_no){
        case 0:
            cd(args);
            break;
        case 1:
            exit(EXIT_SUCCESS);
        case 2:
            clear();
            break;
        case 3:
            return;
        default:
            execute_process(command, args);
            break;
    }
}
