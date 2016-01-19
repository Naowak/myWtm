#ifndef __WTPT_H__
#define __WTPT_H__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bitmap.h"
#include "dict.h"

typedef struct Wtpt * Wtpt;


/* return the bitmap */
Bitmap getBitmapWtpt(Wtpt w);
/* return the leftSon */
Wtpt getLeftSonWtpt(Wtpt w);
/* return the rightSon */
Wtpt getRightSonWtpt(Wtpt w);
/* return tree's high */
int getHighWtpt(Wtpt w);
/* return the Dict */
Dict getDictWtpt(Wtpt w);
/* return the number of elem in the Wtpt */
TYPE getNumberOfElemWtpt(Wtpt w);



/* Create and initialize a wtpt */
Wtpt newWtpt();
/* Copy the Wtpt w and return the copy */
Wtpt copyWtpt(Wtpt w);
/* Free the memory taken by a Wtpt */
void freeWtpt(Wtpt w);


/* Create a Wtpt based on the file and return it.
The file must have only numbers inside */
Wtpt WtptFromFile(char* fileName);
/* Extract the data compress in the wtpt, print the result */
void printExtractWtpt(Wtpt w);

/* print the Wtpt w */
void printWtpt(Wtpt w);


/*------WTPT_MUTABLE------*/

/* Insert in the Wtpt w, the caractere c, to the position pos. */
void insertWtptMutable(Wtpt w, TYPE c, int pos);

/* Remove from the Wtpt w, the caractere which is at the
position pos */
void removeWtptMutable(Wtpt w, int pos);

/* Modify the caractere at the position pos, by the caractere c */
void modifyWtptMutable(Wtpt w, TYPE c, int pos);

#endif