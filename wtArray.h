#ifndef __WTARRAY_H__
#define __WTARRAY_H__

#include "bitmap.h"
#include "dict.h"
#include "math.h"
#include <sys/types.h>
#include <unistd.h>


typedef struct wtArray * WtArray;

/* return the bitmap */
Bitmap getBitmapWtArray(WtArray w);
/* return tree's high */
int getHighWtArray(WtArray w);
/* return the Dict */
Dict getDictWtArray(WtArray w);
/* return the number of elem in the WtArray */
int getNumberOfElemWtArray(WtArray w);


/* Create and initialize a WtArray */
WtArray newWtArray();
/* Copy the WtArray and return the copy */
WtArray copyWtArray(WtArray w);
/* Free the momery taken by a WtArray */
void freeWtArray(WtArray w);

/* Create a WtArray based on the file and return it.
The file must have only numbers inside */
WtArray WtArrayFromFile(char* fileName);
/* Extract the data compress in the WtArray, print the result */
void printExtractWtArray(WtArray w);
/* print the WtArray w */
void printWtArray(WtArray w);


/*------WtArray_MUTABLE------*/

/* Insert in the WtArray w, the caractere c, to the position pos. */
void insertWtArrayMutable(WtArray w, int c, int pos);
/* Remove from the WtArray w, the caractere which is at the
position pos */
void removeWtArrayMutable(WtArray w, int pos);
/* Modify the caractere at the position pos, by the caractere c */
void modifyWtArrayMutable(WtArray w, int c, int pos);



#endif