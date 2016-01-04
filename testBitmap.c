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

	return 0;
}