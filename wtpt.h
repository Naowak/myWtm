#ifndef __WTPT_H__
#define __WTPT_H__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bitmap.h"
#include "bitmapOperators.h"

typedef struct Wtpt * Wtpt;


//Create a Wtpt based on the file and return it.
//syzeOfType is encode use in the file (16, 32, 64 bits or other)
Wtpt WtptFromFile(char* fileName, int sizeOfType);
//Create a file based on a Wtpt
void FileFromWtpt(char* fileName, Wtpt w);


//Write the Wtpt in a file
void writeWtpt(char* fileName, Wtpt w);
//Read and Create a Wtpt from a file and return it
Wtpt readWtpt(char* fileName);


//Copy the newWtpt and return the copy
Wtpt copyWtpt(Wtpt w);
//Free the memory taken by a Wtpt
void freeWtpt(Wtpt w);


//return the bitmap
Bitmap getBitmap(Wtpt w);
//return the leftSon
Wtpt getLeftSon(Wtpt w);
//return the rightSon
Wtpt getRightSon(Wtpt w);
//return tree's high
int getHigh(Wtpt w);
//return the Dict
Dict getDict(Wtpt w);


//Compress the Input file in the Output one.
void compress(char* fileNameInput, char* fileNameOutput);
//Decompress the Output file int the Input one.
void decompress(char* fileNameInput, char* fileNameOutput);

#endif