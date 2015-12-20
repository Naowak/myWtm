#ifndef __WTPT_H__
#define __WTPT_H__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bitmap.h"
#include "bitmapOperators.h"
#include "dict.h"

typedef struct Wtpt * Wtpt;

//1
//return the bitmap
Bitmap getBitmapWtpt(Wtpt w);
//return the leftSon
Wtpt getLeftSonWtpt(Wtpt w);
//return the rightSon
Wtpt getRightSonWtpt(Wtpt w);
//return tree's high
int getHighWtpt(Wtpt w);
//return the Dict
Dict getDictWtpt(Wtpt w);

//2
//Create and initialize a wtpt
Wtpt newWtpt();
//Copy the newWtpt and return the copy
Wtpt copyWtpt(Wtpt w);
//Free the memory taken by a Wtpt
void freeWtpt(Wtpt w);

//3
//Create a Wtpt based on the file and return it.
//The file must have only numbers inside
Wtpt WtptFromFile(char* fileName);
//Create a file based on a Wtpt
void FileFromWtpt(char* fileName, Wtpt w);

//4
//Write the Wtpt in a file
void writeWtpt(char* fileName, Wtpt w);
//Read and Create a Wtpt from a file and return it
Wtpt readWtpt(char* fileName);

//5
//Compress the Input file in the Output one.
void compress_Wtpt(char* fileNameInput, char* fileNameOutput);
//Decompress the Output file int the Input one.
void decompress_Wtpt(char* fileNameInput, char* fileNameOutput);

//print the Wtpt w
void printWtpt(Wtpt w);

#endif