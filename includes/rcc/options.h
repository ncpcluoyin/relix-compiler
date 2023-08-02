#pragma once
#include<types.h>
#include<stdalign.h>

enum step{
    preprocess,
    compile,
    assemble,
    link,
    help
};

struct opts{
    alignas(i32) u8 opt_level;
    alignas(i32) enum step _step;
    alignas(i32) u32 file_c;
    alignas(i64) char** file_p;
    alignas(i32) bool rename;
    alignas(i64) char* name;
};

void get_opts(struct opts * value,int argc, char const *argv[]);
