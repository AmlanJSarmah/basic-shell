#ifndef __SHELL__
#define __SHELL__

void input_command(char* command);
void execute_command(char* command, char* args[]);
void execute_process(char* command, char* args[]);

#endif
