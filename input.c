#include <readline/readline.h>
#include <readline/history.h>

#include "common.h"

// to do
size_t process_PS1(const char *pattern, char* PS){
    strncpy(PS, pattern, MAX_PMT_SIZE);
    return strlen(PS);
}

void add_to_cmd(char *cmd, const char *s){

}

char** input(void){
    char prompt[MAX_PMT_SIZE + 1] = {0};
    char cmd[MAX_CMD_SIZE + 1] = {0};
    int len_cmd = 0;

    char * s = getenv("PS1");

    if (process_PS1(s ? s : PS1, prompt)<0) {
        return NULL;
    }

    snprintf(prompt, MAX_PMT_SIZE, "%s : %s $", s, cwd);

    char *p = readline(prompt);
    // add_history(p);
    len_cmd = strlen(p);
    if(p[len_cmd - 1] == '\\'){ // expects other lines
        strncat(cmd, p, len_cmd - 1); // ignore the trailing slash
        
    }
}
