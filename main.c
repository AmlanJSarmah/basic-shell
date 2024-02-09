#include "./headers/prompt.h"
#include "./headers/args.h"
#include "./headers/const.h"
#include "./headers/shell.h"
#include <stdio.h>

int main(){
    char command[BUF_SIZE];
    char command_main[BUF_SIZE];
    char args_[BUF_SIZE];
    char* args[ARGS_MAX];
    display_prompt();
    input_command(command);
    get_command(command_main, command); 
    get_args(args_, command);
    printf("\n %s", args_);
    //parse_args(args, args_);
    //printf("\n %s", command);
    //printf("\n %s", command_main);
    //for(int i=0; args[i] != NULL; i++)
    //    printf("\n %s", args[i]);
    return 0;
}
