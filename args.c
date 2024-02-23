#include <stdio.h>
#include <string.h>
#include "./headers/args.h"

void get_command(char* command, char* command_full){
    int index = 0;
    for(int i=0; i < strlen(command_full); i++){
        if(command_full[i] == ' '){
            index = i;
            break;
        }
    }
    if(index == 0)
        index = strlen(command_full);
    strncpy(command, command_full, index);
    command[index] = '\0';
}

void get_args(char* args, char* command_full){
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
        strncpy(args, command_full + index, strlen(command_full));
        args[strlen(command_full)] = '\0';
    }
    else{
        args[0] = '\0';
    }
}

void parse_args(char *args[], char *args_, char* command){
    if(args_ != NULL){
        int index = 0;
        char* token = strtok(args_," ");
        if(!(strcmp("cd",command) == 0)){
            // By default the first argument is command name in args list
            args[index] = command;
            index++;
        }
        args[index] = token;
        while(token != NULL ){
            index++;
            token = strtok(NULL, " ");
            args[index] = token;
        }
    }
    else{
        args[0] = NULL;
    }
}
