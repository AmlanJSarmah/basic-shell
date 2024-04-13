cmake_minimum_required(VERSION 3.22.1)
project(basic-shell)
include_directories(${PROJECT_SOURCE_DIR}/headers)
add_executable(${PROJECT_NAME} main.c prompt.c args.c shell.c shell_commands.c const.c)
