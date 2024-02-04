#include <unistd.h>
#include <stdio.h>
#include "./headers/get_info.h"

#define STD_IN 0 
#define STD_OUT 1

void display_info(){
    char* user_name = getlogin();
    ssize_t ret = write(STD_OUT, user_name, sizeof(user_name));
    if(ret == -1)
        perror("WRITE");
}
