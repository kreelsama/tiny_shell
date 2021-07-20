#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

#include "common.h"

int main(void){
    char **cmd = NULL;
    getcwd(cwd, CWD_SIZE);
    while(1){
        cmd = input();
    }
}