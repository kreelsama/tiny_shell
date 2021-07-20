#include <readline/readline.h>
#include <readline/history.h>

#include "common.h"

// to do
char * process_PS1(const char *pattern){
    return pattern;
}

void add_to_cmd(char *cmd, const char *s){

}

char** input(void){
    char prompt[MAX_PMT_SIZE + 1] = {0};
    char cmd[MAX_CMD_SIZE + 1] = {0};
    int len_cmd = 0;

    char * s = getenv("PS1");
    s = process_PS1(s);
    snprintf(prompt, MAX_PMT_SIZE, "%s : %s $", s ? s : PS1, cwd);

    char *p = readline(prompt);
    // add_history(p);
    len_cmd = strlen(p);
    if(p[len_cmd - 1] == '\\'){ // expects other lines
        strncat(cmd, p, len_cmd - 1); // ignore the trailing slash
        
    }
}
