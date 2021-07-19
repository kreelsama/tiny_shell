#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "common.h"

int main(void){
    while(1){
        char *p = readline(PS1);
        add_history(p);
    }
}