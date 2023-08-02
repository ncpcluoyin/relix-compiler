#include<options.h>
#include<types.h>

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
                if(pre[1] == "o"){
                    //rename the output file
                    processed++;//processed the next argment
                    
                }
            }
        }
    }
};