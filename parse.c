#include "common.h"


typedef enum {
    WAITING= 1,
    ESCAPED,
    WRAPPED,
    QUOTED,
    IDLE,
    COMMAND
}status_t ;

/*
convert from raw command line to recognizable tokens

EX:
    # LD_LIBRARY_PATH=../123/ ./ax  -s 1 -t=No -d "fire box" 2>/dev/null || echo "wrong command" \
=>  {"LD_LIBRARY_PATH=../123/", "./ax", "-s", "1", "-t=No", "-d", "fire box", "2>/dev/null", OR_CONCAT, 
    "echo", "wrong command", NEWLINE
    }
*/
char ** parse_line(const char* raw){
    int len = strlen(raw);
    char *tokens[MAX_TKN_SIZE + 1]  = {NULL};
    int token_cur = 0;

    status_t state = IDLE;
    char nxt;

    for(int i = 0; i < len; ++i){
        switch (raw[i]){
            case ' ':
                if (state == IDLE){

                } else if (state == ESCAPED){
                    nxt = ' ';
                    state = WAITING;
                } else if (state == WRAPPED){
                    state = IDLE;
                } else {
                    // Exception
                }
                break;
            case '\\': // Escape character
                if(state == ESCAPED || state == QUOTED){

                } else if (state == IDLE){
                    state = ESCAPED;
                } else if (state == WRAPPED){
                    state = ESCAPED;
                }
                break;
            case '\'':
            case '"':

            case '$': // Inset command or variable
                // Not implemented yet
            default:
        }
    }
    return tokens;
}  


int vfree(int argc, char *argv[]){
    if(!argv){
        return -1;
    }
    for(int i = 0; i < argc; ++i){
        if(argv[i]){
            free(argv[i]);
        }
    }
    return 0;
}