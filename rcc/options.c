#include<options.h>
#include<types.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<exit_codes.h>
#include<ctype.h>

#define default_name "unknown"

static void empty(struct opts* value){
    value->opt_level = 0;
    value->_step = help;
    value->file_c = 0;
    value->file_p = null;
    value->rename = false;
    value->name = default_name;
};

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
                        //TODO
                    }
                }elif(strlen(pre) == 3){
                    if(pre[1] == "O"){
                        if(isdigit(pre[2])){
                            i32 num = atoi(pre[2]+'0');
                            if(num < 0 || num > 4){
                                printf("opt_level should be 0,1,2,3 or 4");
                                exit(OPT_LEVEL_ERROR);
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
            printf("unknown option: %s",pre);
            exit(UNKNOWN_OPTION_ERROR);
        }
        
    }
};