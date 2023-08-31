#include <options.h>
#include <types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <exit_codes.h>
#include <ctype.h>
#include <unistd.h>
#include <sList.h>

static void empty(struct opts *value)
{
    value->opt_level = 0;
    value->_step = help;
    value->file_c = 0;
    value->file_p = sList_init_self_void();
    value->name = null;
    value->include_dir = sList_init_self_void();
};

void close_opts(struct opts *value)
{
    justFree(value->file_p);
    justFree(value->include_dir);
}

void get_opts(struct opts *value, int argc, char const *argv[])
{                 // TODO
    empty(value); // reset the structure
    if (argc < 2)
    {
        // help mode
        return;
    }
    char *pre = null;
    i32 processed = 0;
    for (processed++; processed != argc; processed++)
    {
        pre = argv[processed];
        if (pre[0] == "-")
        {
            if (pre[1] == "-")
            {
                // full name option
            }
            else
            {
                // short name option
                if (strlen(pre) == 2)
                {
                    if (pre[1] == "o")
                    {
                        // rename the output file
                        processed++; // processed the next argment
                        value->name = argv[processed];
                    }
                    elif (pre[1] == "S")
                    {
                        value->_step = compile;
                    }
                    elif (pre[1] == "E")
                    {
                        value->_step = preprocess;
                    }
                    elif (pre[1] == "c")
                    {
                        value->_step = assemble;
                    }
                    elif (pre[1] == "I")
                    {
                        processed++;
                        pre = argv[processed];
                        if (!access(pre, F_OK))
                        {
                            printf("directory :\"%s\" not found", pre);
                            __exit(DIR_DO_NOT_EXIST);
                        }
                        char *sTmp = (char *)safeMalloc(sizeof(char) * (strlen(pre) + 1));
                        strcpy(sTmp, pre);
                        sList_append_int32_object(value->include_dir, sTmp);
                    }
                }
                elif (strlen(pre) == 3)
                {
                    if (pre[1] == "O")
                    {
                        if (isdigit(pre[2]))
                        {
                            i32 num = atoi(pre[2] + '0');
                            if (num < 0 || num > 4)
                            {
                                puts("opt_level should be 0,1,2,3 or 4");
                                __exit(OPT_LEVEL_ERROR);
                            }
                            value->opt_level = (u8)num;
                        }
                    }
                }
                else
                {
                    if (pre[1] == "I")
                    {
                        char *sTmp = (char *)safeMalloc(sizeof(char) * (strlen(pre) - 2 + 1));
                        memcpy(sTmp,pre+2,sizeof(char) * (strlen(pre) - 2 + 1));
                        sList_append_int32_object(value->include_dir,sTmp);
                    }
                }
            }
        }
        else
        {
            printf("unknown option: %s\n", pre);
            __exit(UNKNOWN_OPTION_ERROR);
        }
    }
};