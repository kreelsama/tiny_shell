#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define PS1 "TinyShell"

#define CWD_SIZE 512
#define MAX_PMT_SIZE 50
#define MAX_CMD_SIZE 500
#define MAX_TKN_SIZE 64

enum Delimiters{
    NEWLINE=1, // "trailing \"
    OR_CONCAT, // "||"
    AND_CONCAT // "&&"  
};

char cwd[CWD_SIZE];

char** input();