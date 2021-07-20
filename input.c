#include <readline/readline.h>
#include <readline/history.h>

#include "common.h"

// to do
char * process_PS1(const char *pattern){
    return pattern;
}

char** input(void){
    char prompt[MAX_PMT_SIZE+1] = {0};

    char * s = getenv("PS1");
    s = process_PS1(s);
    snprintf(prompt, MAX_PMT_SIZE, "%s : %s $", s ? s : PS1, cwd);

    char *p = readline(prompt);
    // add_history(p);
    int len_p = strlen(p);
    if(p[len_p - 1] == '\\'){ // expects other lines
        
    }
}
