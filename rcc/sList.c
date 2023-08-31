#include "sList.h"
//init functions
sList * sList_init_self_void(){
    sList* self = (sList*) safeMalloc(sizeof(sList));
    self->valueCounter = sListDefaultInitSize - 1;
    self->positionCounter = 0;
    self->objectArray = safeMalloc(sizeof(object) * sListDefaultInitSize);
    return self;
}
sList * sList_init_self_int32(int32_t _initSize){
    int32_t initSize = _initSize;
    if(initSize < sListDefaultInitSize){
        initSize = sListDefaultInitSize;
    }
    sList* self = (sList*) safeMalloc(sizeof(sList));
    self->valueCounter = initSize - 1;
    self->positionCounter = 0;
    self->objectArray = safeMalloc(sizeof(object) * initSize);
    return self;
}
//end init functions

//impl for sList structure
//the first argument's name must be "self" with a type "sList*"

int32_t sList_append_int32_object(sList * self,object value){
    if((self->positionCounter-1) == self->valueCounter){
        object * tmpPtr = safeMalloc((self->valueCounter+1) * 2 * sizeof(object));
        for(int32_t i=0;i != self->positionCounter;i++){
            tmpPtr[i] = self->objectArray[i];
        }
        free(self->objectArray);
        self->objectArray = tmpPtr;
        self->valueCounter = ((self->valueCounter+1) * 2) - 1;
    }
    self->objectArray[self->positionCounter] = value;
    self->positionCounter++;
    return self->positionCounter - 1;
}

bool sList_has_bool__GENERIC_equals_object(sList* self,bool (*equals)(object,object),object value){
    bool has = false;
    for(int32_t i;i != self->positionCounter;i++){
        if(equals(self->objectArray[i],value)){has = true;}
    }
    return has;
}

int32_t sList_set_int32__GENERIC_close_int32_object(sList* self,int32_t _position,object value){
    int32_t position = _position;
    if(position > self->positionCounter-1){
        return -(position);
    }
    if(position < 0){
	    if(-(position) > self->valueCounter+1){
		    return -(position);
	    }
	    position = self->valueCounter + position + 1;
    }
    free(self->objectArray[position]);
    self->objectArray[position] = value;
    return position;
}

object sList_get_object_void(sList* self){
    if(self->positionCounter == 0){
        return NULL;
    }
    return self->objectArray[self->positionCounter-1];
}

object sList_get_object_int32(sList* self,int32_t _position){
    int32_t position = _position;
    if(position > (self->positionCounter - 1)){
        return NULL;
    }
    if(position < 0){
	    if(-(position) > self->valueCounter+1){
		    return NULL;
	    }
	    position = self->valueCounter + position + 1;
    }
    return self->objectArray[position];
}

bool sList_delete_bool__GENERIC_close_int32(sList* self,void (*close)(object),int32_t _position){
    int32_t position = _position;
    if(position > (self->positionCounter - 1)){
        return false;
    }
    if(position < 0){
	    if(-(position) > self->valueCounter+1){
		    return -(position);
	    }
	    position = self->valueCounter + position + 1;
    }
    object* tmpPtr = safeMalloc((self->valueCounter+1)*sizeof(object));
    int32_t offSet = 0;
    for(int32_t i = 0;i != self->positionCounter;i++){
        if(i == position){
            offSet++;
            close(self->objectArray[i]);
            continue;
        }
        tmpPtr[i-offSet] = self->objectArray[i];
    }
    free(self->objectArray);
    self->objectArray = tmpPtr;
    self->positionCounter--;
    return true;
}

void sList_close_void__GENERIC_close(sList* self,void (*close)(object)){
    for(int32_t i = 0;i < self->positionCounter;i++){
        close(self->objectArray[i]);
    }
    free(self->objectArray);
    free(self);
}

object sList_pop_object_void(sList* self){
    if(self->positionCounter == 0){
        return NULL;
    }
	object result = self->objectArray[self->positionCounter-1];
	self->positionCounter--;
	return result;
}

object sList_pop_object_int32(sList* self,int32_t _position){
    int32_t position = _position;
    if(position > (self->positionCounter - 1)){
        return NULL;
    }
    if(position < 0){
	    if(-(position) > self->valueCounter+1){
		    return NULL;
	    }
	    position = self->valueCounter + position + 1;
    }
	object* tmpPtr = safeMalloc((self->valueCounter+1)*sizeof(object));
	int32_t offSet = 0;
	object result = NULL;
	for(int32_t i = 0;i != self->positionCounter;i++){
		if(i == position){
			offSet++;
			//free(self->objectArray[i])
			result = self->objectArray[i];
			continue;
		}
		tmpPtr[i-offSet] = self->objectArray[i];
	}
	free(self->objectArray);
	self->objectArray = tmpPtr;
	self->positionCounter--;
	return result;
}

bool sList_delete_bool__GENERIC_close(sList *self,void (*close)(object)){
    if(self->positionCounter == 0){
        return false;
    }
	close(self->objectArray[self->positionCounter-1]);
	self->positionCounter--;
	return true;
}

object sList_exchange_object_int32_object(sList* self,int32_t _position,object value){
    int32_t position = _position;
    if(position > self->positionCounter-1){
        return NULL;
    }
    if(position < 0){
	    if(-(position) > self->valueCounter+1){
		    return NULL;
	    }
	    position = self->valueCounter + position + 1;
    }
    object tmp = self->objectArray[position];
    self->objectArray[position] = value;
    return tmp;
}

bool sList_exchange_bool_int32_int32(sList* self,int32_t _position1,int32_t _position2){
    int32_t position1 = _position1;
    int32_t position2 = _position2;
    if(position1 > self->positionCounter-1){
        return false;
    }
    if(position2 > self->positionCounter-1){
        return false;
    }
    if(position1 < 0){
	    if(-(position1) > self->valueCounter+1){
		    return false;
	    }
	    position1 = self->valueCounter + position1 + 1;
    }
    if(position2 < 0){
	    if(-(position2) > self->valueCounter+1){
		    return false;
	    }
	    position2 = self->valueCounter + position2 + 1;
    }
    object tmp = self->objectArray[position1];
    self->objectArray[position1] = self->objectArray[position2];
    self->objectArray[position2] = tmp;
    return true;
}

int32_t sList_insert_int32_int32_object(sList* self,int32_t _position,object value){
    int32_t position = _position;
    if(position > self->positionCounter-1){
        return -(position);
    }
    if(position < 0){
	    if(-(position) > self->valueCounter+1){
		    return -(position);
	    }
	    position = self->valueCounter + position + 1;
    }
    int32_t tmp_positionCounter = self->positionCounter;
    sList* array = sList_init_int32(tmp_positionCounter - position);
    for(int32_t i = 0;i < tmp_positionCounter - position;i++){
	    sList_append_int32_object(array,sList_pop_object_void(self));
    }
    sList_append_int32_object(self, value);
    for(int32_t i = 0;i < tmp_positionCounter - position;i++){
	    sList_append_int32_object(self, sList_pop_object_void(array));
    }
    sList_close(array,free);
    return position;
}

void justFree(sList * v){
    sList_close_void__GENERIC_close(v,free);
}

//end impl
