#include "./headers/prompt.h"
#include "./headers/args.h"
#include "./headers/const.h"

int main(){
    char command[BUF_SIZE];
    display_prompt();
    get_command(command, "gcc main.c -o main");
    return 0;
}
