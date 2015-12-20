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

	printf("%d = 5\n", getOnesBitmap(b));

	printBitmap(b);
	printBitmap(c);

	freeBitmap(b);
	freeBitmap(c);

	return 0;
}