#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "./headers/shell_commands.h"

void clear(){
    //printf("\e[1;1H\e[2J"); //we use this if we don't want platform specific code
    system("clear");
}

void cd(char* path[]){
    int count = 0;
    for(int i=0; path[i] != NULL; i++)
        count += 1;
    if(count == 1){
        if(strcmp(path[0], "~") == 0){
            path[0] = "/home/";
        }
        int ret = chdir(path[0]);
        if(ret == -1 && errno == ENOENT){
            printf("cd - error no such file or directory: %s\n", path[0]);
            fflush(stdout);
        }
    }
}
