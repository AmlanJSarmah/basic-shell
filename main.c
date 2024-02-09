#include "./headers/prompt.h"
#include "./headers/args.h"
#include "./headers/const.h"
#include "./headers/shell.h"
#include "./headers/shell_commands.h"

int main(){
    clear();
    char command[BUF_SIZE];
    char command_main[BUF_SIZE];
    char args_[BUF_SIZE];
    char* args[ARGS_MAX];
    display_prompt();
    input_command(command);
    get_command(command_main, command); 
    int if_args_exist = get_args(args_, command);
    if(if_args_exist == -1){
        //do
    }
    else{
        parse_args(args, args_);
    }
   return 0;
}
