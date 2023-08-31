#include<stdio.h>
#include<options.h>
#include<types.h>
#include<stdlib.h>
#include<string.h>
#include<iso646.h>
#include<ctype.h>
#include"sList.h"

typedef sList* processing_files;

int main(int argc, char const *argv[])
{
    struct opts _opt;
    get_opts(&_opt,argc,argv);
    processing_files pf = sList_init_self_void();
    loop_c(_opt.file_c){
        sList* tmpList = sList_init_self_void();
        //TODO
    }
    close_opts(&_opt);
    sList_close_void__GENERIC_close(pf,justFree);
    return 0;
};

#define CHECK_NAME_OK_MARCO(x) if(name[i] == x){\
    return false;\
    }

bool isNameOK(char* name){
    for(i32 i = 0;i != strlen(name);i++){
        CHECK_NAME_OK_MARCO('!');
        CHECK_NAME_OK_MARCO('@');
        CHECK_NAME_OK_MARCO('#');
        CHECK_NAME_OK_MARCO('$');
        CHECK_NAME_OK_MARCO('%');
        CHECK_NAME_OK_MARCO('^');
        CHECK_NAME_OK_MARCO('&');
        CHECK_NAME_OK_MARCO('*');
        CHECK_NAME_OK_MARCO('(');
        CHECK_NAME_OK_MARCO(')');
        CHECK_NAME_OK_MARCO('-');
        CHECK_NAME_OK_MARCO('=');
        CHECK_NAME_OK_MARCO('+');
        CHECK_NAME_OK_MARCO('[');
        CHECK_NAME_OK_MARCO(']');
        CHECK_NAME_OK_MARCO('{');
        CHECK_NAME_OK_MARCO('}');
        CHECK_NAME_OK_MARCO(';');
        CHECK_NAME_OK_MARCO(':');
        CHECK_NAME_OK_MARCO('\'');
        CHECK_NAME_OK_MARCO('\"');
        CHECK_NAME_OK_MARCO(',');
        CHECK_NAME_OK_MARCO('<');
        CHECK_NAME_OK_MARCO('.');
        CHECK_NAME_OK_MARCO('>');
        CHECK_NAME_OK_MARCO('/');
        CHECK_NAME_OK_MARCO('?');
        CHECK_NAME_OK_MARCO('\\');
        CHECK_NAME_OK_MARCO('|');
        CHECK_NAME_OK_MARCO('`');
        CHECK_NAME_OK_MARCO('~');
    }
    if(isdigit(name[0])){
        return false;
    }
    return true;
}

#undef CHECK_NAME_OK_MARCO

#define DEFAULT_LEXER_BUFFER_SIZE 20

void get_string(sList * v,FILE* fp){
}

void lexer(){
}
