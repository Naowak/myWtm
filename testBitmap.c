#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

int main(int argc, char** argv){
	Bitmap b = newBitmap();
	setBit(b, 2, 1);
	setBit(b, 12, 1);
	setBit(b, 20, 1);
	setBit(b, 32, 1);
	setBit(b, 33, 1);
	setBit(b, 65, 1);
	setBit(b, 8, 1);
	setBit(b, 8, 0);

	Bitmap c = copyBitmap(b);
	setBit(c, 12, 0);

	printf("%d = 6\n", getOnesBitmap(b));

	printBitmap(b);
	printBitmap(c);

	printf(" posFar : %d\n", getPosFar(b));
	printf("65 : 1, res : %d\n", getBit(b, 65));
	printf("32 : 1, res : %d\n", getBit(b, 32));
	printf("8 : 0, res : %d\n", getBit(b, 8));
	printf("70 : -1, res : %d\n", getBit(b, 70));

	freeBitmap(b);
	freeBitmap(c);

	/*-----Bitmap_Operators------*/
	printf("\n\n/*-----Bitmap_Operators------*/\n\n");

	b = newBitmap();
	setBit(b, 2, 1);
	setBit(b, 12, 1);
	setBit(b, 20, 1);
	setBit(b, 65, 1);
	setBit(b, 8, 1);

	printBitmap(b);

	printf("test rankB :\n");
	printf("%d = 4\n", rankB(b, 32, 1));
	printf("%d = 28\n", rankB(b, 32, 0));
	printf("%d = 4\n", rankB(b, 64, 1));
	printf("%d = 60\n", rankB(b, 64, 0));
	printf("%d = 2 \n", rankB(b, 9, 1));
	printf("%d = 4\n", rankB(b, 23, 1));
	printf("%d = 19\n", rankB(b, 23, 0));
	printf("%d = 5\n", rankB(b, 71, 1));
	printf("%d = 66\n", rankB(b, 71, 0));
	printf("%d = 5\n", rankB(b, 81, 1));
	printf("%d = 4\n", rankB(b, 41, 1));
	printf("%d = 37\n", rankB(b, 41, 0));

	printf("\n test selectB : \n");
	printf("%d = 20\n", selectB(b, 4, 1));
	printf("%d = 65\n", selectB(b, 5, 1));
	printf("%d = 66\n", selectB(b, 62, 0));
	printf("%d = 10\n", selectB(b, 9, 0));
	printf("%d = 0\n ", selectB(b, 1, 0));
	
	/*int i;
	for(i = 1; i <= getLength(b)*32 - 5; i++){
		printf("%d = %d\n", i, selectB(b, i, 0));
	}*/

	printf("\n test accessB : \n");
	printf("%d = 1\n", accessB(b, 3));
	printf("%d = 1\n", accessB(b, 66));
	printf("%d = 1\n", accessB(b, 13));
	printf("%d = 0\n", accessB(b, 6));
	printf("%d = 0\n", accessB(b, 43));

	printf("\n");

	printBitmap(b);

	freeBitmap(b);

	/*-------Bitmap_Mutable------*/
	printf("\n\n/*-------Bitmap_Mutable------*/\n\n");

	b = newBitmap();
	setBit(b, 2, 1);
	setBit(b, 12, 1);
	setBit(b, 20, 1);
	setBit(b, 32, 1);
	setBit(b, 33, 1);
	setBit(b, 65, 1);
	setBit(b, 8, 1);
	setBit(b, 8, 0);

	printBitmap(b);

	insertBitmapMutable(b, 1, 65);
	insertBitmapMutable(b, 0, 33);
	insertBitmapMutable(b, 1, 0);

	printBitmap(b);

	removeBitmapMutable(b, 65);
	removeBitmapMutable(b, 33);
	removeBitmapMutable(b, 0);	

	printBitmap(b);

	modifyBitmapMutable(b, 1, 65);
	modifyBitmapMutable(b, 0, 33);
	modifyBitmapMutable(b, 1, 0);

	printBitmap(b);
	
	freeBitmap(b);
	return 0;
}