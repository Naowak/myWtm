#include <stdlib.h>
#include <stdio.h>

typedef unsigned char byte;
typedef struct Bitmap * Bitmap;

//return ith word contain in the bitmap b
int getWord(Bitmap b, int i);
//return the number of ones in the word contain by b 
int getOnes(Bitmap b);
//return the length (in int) of the word in the bitmap b
int getLength(Bitmap b);

//give the string for a byte
char* wordToBinary(int w, char* str);
//display the Bitmap
void displayBitmap(Bitmap b);


//Create and return a new Bitmap initialized to 0.
Bitmap newBitmap();
//set the bit pos in Bitmap to the value val.
void setBit(Bitmap b, int pos, int val);
//free the memory taken by a Bitmap
void freeBitmap(Bitmap b);
//Return a copy of a Bitmap
Bitmap copyBitmap(Bitmap b);

//return the number of 1 in the ith bit.
int rank1(Bitmap b, int i);
//return the number of 0 in the ith bit.
int rank0(Bitmap b, int i);
//return the location of the ith 1 in the Bitmap.
int select1(Bitmap b, int i);
//return the location of the ith 0 in the Bitmap.
int select0(Bitmap b, int i);