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
    set_home_dir();
    set_signal();

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
