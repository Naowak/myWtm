#ifndef __DICT_H__
#define __DICT_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Dict * Dict;

//Create a Dict from a File and return it
//SizeOfType is the encode use to encode the file (16, 32, 64 bits.)
Dict newDict(char* filename, int sizeOfType);
//Copy the Dict and return the new one
Dict copyDict(Dict d);
//free the memory taken by a dict
void freeDict(Dict d);

//return the number given to a character
//Need a void* to be generic
int getCodeFromCharDict(Dict d, void* character);
//return the Character for a number
void* getCharFromCodeDict(Dict d, int code);
//return the size of the Dict (number of different character)
size_t getSizeDict(Dict d);
//return codes' size
int getCodeSizeDict(Dict d);




#endif