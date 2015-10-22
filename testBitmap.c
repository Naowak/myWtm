#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

int main(int argc, char** argv){
	Bitmap b = newBitmap();
	setBit(b, 2, 1);
	setBit(b, 12, 1);
	setBit(b, 20, 1);
	setBit(b, 65, 1);
	setBit(b, 8, 1);
	setBit(b, 8, 0);
	setBit(b, 65, 0);

	Bitmap c = copyBitmap(b);
	setBit(c, 12, 0);

	printf("%d = 3\n", getOnesBitmap(b));

	displayBitmap(b);
	displayBitmap(c);

	freeBitmap(b);
	freeBitmap(c);

	return 0;
}