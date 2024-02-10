#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "./headers/shell_commands.h"

void clear(){
    //printf("\e[1;1H\e[2J"); //we use this if we don't want platform specific code
    system("clear");
}

void cd(const char* path){
    int ret = chdir(path);
    if(ret == -1){
        perror("CHANGE DIRECTORY");
        exit(1);
    }
}
