#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef unsigned char byte;
typedef struct Bitmap * Bitmap;

/* return ith word contain in the bitmap b */
int getWord(Bitmap b, int i);
/* return the number of ones in the words <= i contain by b */
byte getOnes(Bitmap b, int i);
/* return the number of 1 in all the bitmap */
int getOnesBitmap(Bitmap b);
/* return the length (in int) of the word in the bitmap b */
int getLength(Bitmap b);
/* return the position where is the fariest bit */
int getPosFar(Bitmap b);


/* Create and return a new Bitmap initialized to 0. */
Bitmap newBitmap();
/* set the bit pos in Bitmap to the value val. */
void setBit(Bitmap b, int pos, int val);
/* free the memory taken by a Bitmap */
void freeBitmap(Bitmap b);
/* Return a copy of a Bitmap */
Bitmap copyBitmap(Bitmap b);


/* print the bitmap */
void printBitmap(Bitmap b);

#endif

