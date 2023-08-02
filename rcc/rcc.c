#include<stdio.h>
#include<options.h>
#include<types.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    struct opts _opt;
    get_opts(&_opt,argc,argv);
    return 0;
};

#define TO_CHAR(x) #@x

#define CHECK_NAME_OK_MARCO(x) if(name[i] == TO_CHAR(x)){\
    return false;\
    }
bool isNameOK(char* name){
    for(i32 i = 0;i != strlen(name);i++){
        CHECK_NAME_OK_MARCO(!);
    }
}
