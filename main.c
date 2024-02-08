#include "./headers/prompt.h"
#include "./headers/args.h"
#include "./headers/const.h"

int main(){
    char command[BUF_SIZE];
    char args_[BUF_SIZE];
    char* args[ARGS_MAX];
    display_prompt();
    get_command(command, "gcc main.c -o main");
    get_args(args_, "gcc main.c -o main");
    parse_args(args, args_);
    return 0;
}
