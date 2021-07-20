#include <unistd.h>
#include <stdio.h>


#define PS1 "TinyShell"

#define CWD_SIZE 512
#define MAX_PMT_SIZE 50
#define MAX_CMD_SIZE 500

char cwd[CWD_SIZE];

char** input();