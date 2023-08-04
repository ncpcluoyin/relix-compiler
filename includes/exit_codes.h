#pragma once
#define UNKNOWN_OPTION_ERROR 1
#define OPT_LEVEL_ERROR 2
#define DIR_DO_NOT_EXIST 3
#define FILE_DO_NOT_EXIST 3//the same as dir(DIR_DO_NOT_EXIST)
#define CAN_NOT_ALLOC_MEMORY 4


#include<stdlib.h>
#define __exit(x)   printf("\nexit,return code:%d\n",x);\
                    exit(x);