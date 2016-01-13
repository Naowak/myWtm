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


/* set the High og the Wtpt w and his sons, and return the high of w */
int setAllHighWtpt(Wtpt w);
/* set The Bitmap from the Wtpt w, by the bitmap b */
void setBitmapWtpt(Wtpt w, Bitmap b);
/* set the left son of the wtpt w by the wtpt leftSon */
void setLeftSonWtpt(Wtpt w, Wtpt leftSon);
/* set the right son of the wtpt w by the wtpt rightSon */
void setRightSonWtpt(Wtpt w, Wtpt rightSon);
/* set the Dict in the Wtpt w by the dict d */
void setDictWtpt(Wtpt w, Dict d);
/* set the number of elem in the Wtpt */
void setNumberOfElemWtpt(Wtpt w, TYPE nb);



/* Create and initialize a wtpt */
Wtpt newWtpt();
/* Copy the newWtpt and return the copy */
Wtpt copyWtpt(Wtpt w);
/* Free the memory taken by a Wtpt */
void freeWtpt(Wtpt w);


/* Create a Wtpt based on the file and return it.
The file must have only numbers inside */
Wtpt WtptFromFile(char* fileName);
/* Create a file based on a Wtpt */
void FileFromWtpt(char* fileName, Wtpt w);


/* Write the Wtpt in a file */
void writeWtpt(char* fileName, Wtpt w); //TODO
/* Read and Create a Wtpt from a file and return it */
Wtpt readWtpt(char* fileName); //TODO


/* Compress the Input file in the Output one. */
void compress_Wtpt(char* fileNameInput, char* fileNameOutput); //TODO
/* Decompress the Output file int the Input one. */
void decompress_Wtpt(char* fileNameInput, char* fileNameOutput); //TODO

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