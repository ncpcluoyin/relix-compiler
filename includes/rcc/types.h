#pragma once
#include<stdint.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
#define NULL ((void*)0)
#define null NULL
#include<stdbool.h>

bool isNameOK(char* name);
#define loop for(;;)
#define loop_c(x) for(i32 i = 0;i != x;i++)
#define elif else if