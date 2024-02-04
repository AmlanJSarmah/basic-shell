#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./headers/get_info.h"
#include "./headers/const.h"

void display_prompt(){
    char* user_name = getlogin();
    char current_working_directory[BUF_SIZE];
    getcwd(current_working_directory, sizeof(current_working_directory));
    if(current_working_directory == NULL){
        perror("Cannot Get Working Directory");
        exit(EXIT_FAILURE);
    }
    printf(" (%s) %s\n", user_name, current_working_directory);
}
