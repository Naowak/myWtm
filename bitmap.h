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
/* set the posFar to the position pos */
void setPosFar(Bitmap b, int pos);


/* Create and return a new Bitmap initialized to 0. */
Bitmap newBitmap();
/* set the bit pos in Bitmap to the value val. */
void setBit(Bitmap b, int pos, int val);
/* get the value of the bit pos in Bitmap */
int getBit(Bitmap b, int pos);
/* free the memory taken by a Bitmap */
void freeBitmap(Bitmap b);
/* Return a copy of a Bitmap */
Bitmap copyBitmap(Bitmap b);


/* print the bitmap */
void printBitmap(Bitmap b);


/*----BITMAP_OPERATORS-----*/

/* return the number of bit in the i-th bit of the Bitmap b. */
int rankB(Bitmap b, int i, int bit);
/* return the location of the i-th bit in the Bitmap b. */
int selectB(Bitmap b, int i, int bit);
/* return the i-th bit */
int accessB(Bitmap b, int i);


/*----BITMAP_MUTABLE-----*/

/* Insert in the Bitmap b, the bit bit, to the position pos */
Bitmap insertBitmapMutable(Bitmap b, int bit, int pos);

/* Remove from the Bitmap b, the bit to the position pos */
Bitmap removeBitmapMutable(Bitmap b, int pos);

/* Modify the bit in the Bitmap b, at the position pos,
by the bit bit */
Bitmap modifyBitmapMutable(Bitmap b, int bit, int pos);

#endif

