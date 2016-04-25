#ifndef __DICT_H__
#define __DICT_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define MAX_int 2147483647

typedef struct Dict * Dict;

/* Create and Initialize a dict to zero */
Dict newDict();
/* Create a Dict from a File and return it */
Dict newDictFromFile(char* filename);
/* Copy the Dict and return the new one */
Dict copyDict(Dict d);
/* free the memory taken by a dict */
void freeDict(Dict d);

/* return the number given to a character
return -1 if c isn't in the dict */
int getCodeFromCharDict(Dict d, int c);
/* return the Character for a number (O(1)) */
int getCharFromCodeDict(Dict d, int code);
/* return the size of the Dict (number of different character) */
size_t getSizeDict(Dict d);
/* return codes' size */
int getCodeSizeDict(Dict d);

/* test if c is in the dict. If it's not, place it in it.
return the code given to the elem c */
int addElemDict(Dict d, int c);
/* remove elem from the dict */
/* Coute cher O(n) */
void removeElemDict(Dict d, int c);

/* print the dict d */
void printDict(Dict d);




#endif