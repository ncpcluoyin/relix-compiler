#include<options.h>
#include<types.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<exit_codes.h>
#include<ctype.h>
#include<unistd.h>

#define default_name "unknown"

static void empty(struct opts* value){
    value->opt_level = 0;
    value->_step = help;
    value->file_c = 0;
    value->file_p = null;
    value->rename = false;
    value->name = default_name;
    value->used_dir_c = 0;
    value->include_dir = (char**) malloc(sizeof(char*)*4);
    if(value->include_dir == NULL){
        printf("\ncan't alloc memory!\n");
        __exit(CAN_NOT_ALLOC_MEMORY);
    }
    value->dir_c = 4;
};

void close_opts(struct opts * value){
    free(value->include_dir);
}

void get_opts(struct opts * value,int argc, char const *argv[]){
    empty(value);//reset the structure
    if(argc < 2){
        //help mode
        return;
    }
    char* pre = null;
    i32 processed = 0;
    for(processed++;processed != argc;processed++){
        pre = argv[processed];
        if(pre[0]=="-"){
            if(pre[1]=="-"){
                //full name option
            }
            else{
                //short name option
                if(strlen(pre) == 2){
                    if(pre[1] == "o"){
                        //rename the output file
                        processed++;//processed the next argment
                        value->rename = true;
                        value->name = argv[processed];
                    }elif (pre[1] == "S")
                    {
                        value->_step = compile;
                    }elif (pre[1] == "E")
                    {
                        value->_step = preprocess;
                    }elif (pre[1] == "c")
                    {
                        value->_step = assemble;
                    }elif (pre[1] == "I"){
                        processed++;
                        pre = argv[processed];
                        if(!access(pre,F_OK)){
                            printf("directory :\"%s\" not found",pre);
                            __exit(DIR_DO_NOT_EXIST);
                        }
                        if(value->used_dir_c == value->dir_c){
                            char** tmp = NULL;
                            tmp = realloc(value->include_dir,sizeof(char*) * value->dir_c * 2);
                            if(tmp == NULL){
                                printf("\ncan't alloc memory!\n");
                                __exit(CAN_NOT_ALLOC_MEMORY);
                            }
                        }
                    }
                }elif(strlen(pre) == 3){
                    if(pre[1] == "O"){
                        if(isdigit(pre[2])){
                            i32 num = atoi(pre[2]+'0');
                            if(num < 0 || num > 4){
                                puts("opt_level should be 0,1,2,3 or 4");
                                __exit(OPT_LEVEL_ERROR);
                            }
                            value->opt_level = (u8)num;
                        }
                    }
                }else{
                    if(pre[1] == "I"){
                        //TODO
                    }
                }
            }
        }else
        {
            printf("unknown option: %s\n",pre);
            __exit(UNKNOWN_OPTION_ERROR);
        }
    }
};