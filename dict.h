#ifndef __DICT_H__
#define __DICT_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// /!\ Cette bibliothèque n'est pas prévu pour un utilisateur

#define TYPE int 
/* TEMPORAIREMENT ON MET CHAR */

typedef struct Dict * Dict;

//Create a Dict from a File and return it
//SizeOfType is the encode use to encode the file (16, 32, 64 bits.)
Dict newDict(char* filename);
//Copy the Dict and return the new one
Dict copyDict(Dict d);
//free the memory taken by a dict
void freeDict(Dict d);

//return the number given to a character
//return -1 if c isn't in the dict
int getCodeFromCharDict(Dict d, TYPE c);
//return the Character for a number (O(1))
TYPE getCharFromCodeDict(Dict d, int code);
//return the size of the Dict (number of different character)
size_t getSizeDict(Dict d);
//return codes' size
int getCodeSizeDict(Dict d);

//add elem to the dict
void addElemDict(Dict d, TYPE c);
//remove elem from the dict
//Coute cher O(n)
void removeElemDict(Dict d, TYPE c);




#endif