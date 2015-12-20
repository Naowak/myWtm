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
#define MAX_TYPE 2147483647
//type pour les printf : %d

typedef struct Dict * Dict;

//Create and Initialize a dict to zero
Dict newDict();
//Create a Dict from a File and return it
Dict newDictFromFile(char* filename);
//Copy the Dict and return the new one
Dict copyDict(Dict d);
//free the memory taken by a dict
void freeDict(Dict d);

//return the number given to a character
//return -1 if c isn't in the dict
TYPE getCodeFromCharDict(Dict d, TYPE c);
//return the Character for a number (O(1))
TYPE getCharFromCodeDict(Dict d, int code);
//return the size of the Dict (number of different character)
size_t getSizeDict(Dict d);
//return codes' size
int getCodeSizeDict(Dict d);

//test if c is in the dict. If it's not, place it in it.
//return the code given to the elem c 
TYPE addElemDict(Dict d, TYPE c);
//remove elem from the dict
//Coute cher O(n)
void removeElemDict(Dict d, TYPE c);

//print the dict d
void printDict(Dict d);




#endif