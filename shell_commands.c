#include <stdlib.h>
#include "./headers/shell_commands.h"

void clear(){
    //printf("\e[1;1H\e[2J"); //we use this if we don't want platform specific code
    system("clear");
}
