
/*
this data struture was the one I wrote before
I will rewrite this one day :)
*/


#include <stdint.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdalign.h>
typedef void* object;
typedef char* string;
#ifndef __STONE_SIMPLE_LIST__
#define __STONE_SIMPLE_LIST__ 1919810

#define sListDefaultInitSize 4

//define structure(object only)
typedef struct{
    alignas(int32_t) int32_t valueCounter;
    alignas(int32_t) int32_t positionCounter;
    alignas(int64_t) object * objectArray;
} sList;

//init for sList structure
sList * sList_init_self_void();
sList * sList_init_self_int32(int32_t initSize);

//impl for sList structure
int32_t sList_append_int32_object(sList* self,object value);
bool sList_has_bool__GENERIC_equals_object(sList* self,bool (*equals)(object,object),object value);
int32_t sList_set_int32__GENERIC_close_int32_object(sList* self,int32_t position,object value);
object sList_get_object_void(sList* self);
object sList_get_object_int32(sList* self,int32_t position);
bool sList_delete_bool__GENERIC_close_int32(sList* self,void (*close)(object),int32_t position);
void sList_close_void__GENERIC_close(sList* self,void (*close)(object));
object sList_pop_object_void(sList* self);
object sList_pop_object_int32(sList* self,int32_t position);
object sList_exchange_object_int32_object(sList* self,int32_t position,object value);
bool sList_exchange_bool_int32_int32(sList* self,int32_t position1,int32_t position2);
int32_t sList_insert_int32_int32_object(sList* self,int32_t position,object value);
bool sList_delete_bool__GENERIC_close(sList *self,void (*close)(object));

void justFree(sList * v);

#define sList_get_value_num(x) x->valueCounter + 1

#endif
