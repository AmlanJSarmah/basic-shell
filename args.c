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

void get_args(char* args, char* command_full){
    int index;
    for(int i=0; i < strlen(command_full); i++){
        if(command_full[i] == ' '){
            index = i + 1;
            break;
        }
    }
    strncpy(args, command_full + index, strlen(command_full) - 1);
    args[strlen(command_full)] = '\0';
}
