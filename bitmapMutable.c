#include "bitmapMutable.h"

Bitmap insertBitmapMutable(Bitmap b, int bit, int pos){
	assert(b != NULL);
	assert(pos <= getPosFar(b) + 1); //On peut le mettre dans le bitmap, ou à la fin (+1)
	assert(bit == 1 || bit == 0);

	int posCurrent = getPosFar(b);

	for(; posCurrent >= pos; posCurrent--){
		setBit(b, posCurrent + 1, getBit(b, posCurrent));
	}
	setBit(b, pos, bit);

	return b;
}

Bitmap removeBitmapMutable(Bitmap b, int pos){
	assert(b != NULL);
	assert(pos <= getPosFar(b)); //On ne peut supprimer que un bit existant.

	int posMax = getPosFar(b);

	for(; pos < posMax; pos++){
		setBit(b, pos, getBit(b, pos + 1));
	}
	setBit(b, posMax, 0);
	setPosFar(b, posMax - 1);

	return b;
}

Bitmap modifyBitmapMutable(Bitmap b, int bit, int pos){
	assert(b != NULL);
	assert(pos <= getPosFar(b)); //On ne peut modifier que un bit  existant.

	setBit(b, pos, bit);

	return b;
}