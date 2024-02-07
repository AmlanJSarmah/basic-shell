// #include <stdio.h>
#include <string.h>
#include "./headers/args.h"

void get_command(char* command, char* command_full){
    int i;
    for(i=0; i < strlen(command_full); i++){
        if(command_full[i] == ' '){
            command[i] = '\0';
            break;
        }
        command[i] = command_full[i];
    }
}
