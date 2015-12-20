#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bitmapOperators.h"

int main(){
	Bitmap b = newBitmap();
	setBit(b, 2, 1);
	setBit(b, 12, 1);
	setBit(b, 20, 1);
	setBit(b, 65, 1);
	setBit(b, 8, 1);

	printf("test rankB :\n");
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
}