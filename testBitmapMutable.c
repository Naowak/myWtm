#include "bitmapMutable.h"

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
}