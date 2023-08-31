#pragma once
#include <stdlib.h>
#include<types.h>
#include<exit_codes.h>
#include<stdio.h>
void* safeMalloc(size_t size){
    void * tmp = malloc(size);
    if(tmp == null){
        printf("\ncan't alloc memory!\n");
        __exit(CAN_NOT_ALLOC_MEMORY);
    }
    return tmp;
}