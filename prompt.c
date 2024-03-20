#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "./headers/prompt.h"
#include "./headers/const.h"

void display_prompt(){
    int err_status = errno;
    char* user_name = getlogin();
    char current_working_directory[BUF_SIZE];
    char* status= getcwd(current_working_directory, sizeof(current_working_directory));
    if(status == NULL){
        perror("Cannot Get Working Directory");
        exit(EXIT_FAILURE);
    }
    if(err_status == 0)
        printf(" (%s) %s  ", user_name, current_working_directory);
    else
        printf(" (%s) %s  ", user_name, current_working_directory);
    fflush(stdout);
}
