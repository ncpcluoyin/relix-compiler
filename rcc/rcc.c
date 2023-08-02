#include<stdio.h>
#include<options.h>
#include<types.h>

extern static struct opts _opt;

int main(int argc, char const *argv[])
{
    get_opts(&_opt);
    return 0;
};
