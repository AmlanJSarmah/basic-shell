#include <stdio.h>
#include <string.h>
#include "./headers/args.h"

void get_command(char* command, char* command_full){
    for(int i=0; i < strlen(command_full); i++){
        if(command_full[i] == ' '){
            command[i] = '\0';
            break;
        }
        command[i] = command_full[i];
    }
}

int get_args(char* args, char* command_full){
    int index;
    int does_args_exist = 0;
    for(int i=0; i < strlen(command_full); i++){
        if(command_full[i] == ' '){
            index = i + 1;
            does_args_exist = 1;
            break;
        }
    }
    if(does_args_exist){
        strncpy(args, command_full + index, strlen(command_full) - 1);
        args[strlen(command_full)] = '\0';
        return 0;
    }
    else{
        args = NULL;
        return -1;
    }
}

void parse_args(char *args[], char *args_){
    int index = 0;
    char* token = strtok(args_," ");
    args[index] = token;
    while(token != NULL ){
        index++;
        token = strtok(NULL, " ");
        args[index] = token;
    }
}
