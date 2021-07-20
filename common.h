#include <unistd.h>
#include <stdio.h>


#define PS1 "TinyShell"

#define CWD_SIZE 512
#define MAX_PMT_SIZE 50

char cwd[CWD_SIZE];

char** input();