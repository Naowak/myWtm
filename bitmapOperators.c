#include "bitmapOperators.h"

int rankB(Bitmap b, int i, int bit){
	//32 is the size of a int in bit
	assert(i > 0);
	assert(bit == 0 || bit == 1);
	i = i - 1;
	int pos = i/32; //Position du word
	int nb = 0; 
	i = i % 32; //position du i dans word
	if(pos != 0)
		nb = getOnes(b, pos-1);
	nb = nb + __builtin_popcount(( (1<<(i+1)) - 1) & getWord(b, pos)); //masque i+1
	if(bit)
		return nb;
	return i+1 + (32*pos) - nb;
}

int selectB(Bitmap b, int i, int bit){
	assert(i > 0);
	assert(bit == 0 || bit == 1);
	assert((bit && i <= getOnesBitmap(b)) || (!bit && i <= getLength(b)*32 - getOnesBitmap(b)));
	if((bit && getOnesBitmap(b) == getLength(b)*32) || (!bit && getOnesBitmap(b) == 0))
		return i - 1;

	int ini = 1;
	int end = getLength(b)*32 - 1;
	int pos;
	int br;

	while(ini < end){
		pos = (ini + end) / 2;
		br = rankB(b, pos, bit);
		if(br < i)
			ini = pos + 1;
		else
			end = pos;
	}

	return ini - 1;
}	

int accessB(Bitmap b, int i){
	assert(i > 0 && i <= getLength(b)*32);
	i = i - 1;
	int pos = i / 32;
	i = i % 32;
	return (getWord(b, pos)>>i) & 1;
}


