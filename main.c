#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./headers/prompt.h"
#include "./headers/args.h"
#include "./headers/const.h"
#include "./headers/shell.h"
#include "./headers/shell_commands.h"


int main(){
    clear();

    // sets the home directory
    // char* HOME_DIRECTORY;
    // HOME_DIRECTORY = getcwd(HOME_DIRECTORY, BUF_SIZE);
    // if(HOME_DIRECTORY == NULL){
    //     perror("GETCWD");
    //     exit(EXIT_FAILURE);
    // }

    // shell loop
    while(1){
        char command[BUF_SIZE];
        char command_main[BUF_SIZE];
        char args_[BUF_SIZE];
        char* args[ARGS_MAX];
        display_prompt();
        input_command(command);
        get_command(command_main, command); 
        get_args(args_, command);
        parse_args(args, args_, command_main);
        execute_command(command_main, args); 
    }
    return 0;
}
