#include "bitmap.h"
#include <assert.h>

struct Bitmap{
	byte* ones;
	int length;
	int* word;
};

int getWord(Bitmap b, int i){
	assert(i < getLength(b));
	return b->word[i];
}

byte getOnes(Bitmap b, int i){
	return b->ones[i];
}

int getLength(Bitmap b){
	return b->length;
}

static void initializeWord(Bitmap b, int i){
	b->word[i] = 0;
}

static void setWord(Bitmap b, int word, int i){
	b->word[i] = word;
}

static void initializeOnes(Bitmap b, int i){
	b->ones[i] = 0;
}

static void setOnes(Bitmap b, byte ones, int i){
	assert(ones <= 32);
	byte tmp = ones - getOnes(b, i);
	int k;
	for(k = i; k < getLength(b); k++)
		b->ones[k] = getOnes(b, k) + tmp;
}

static void setLength(Bitmap b, int length){
	b->length = length;
}


char* wordToBinaryString(int w, char* str){
	str[32] = '\0';
	int i;
	char * c = malloc(sizeof(char));
	assert(c != NULL);
	for(i = 31; i >= 0; --i){
		sprintf(c, "%d", w%2);
		str[i] = c[0];
		w = w >> 1;
	}
	free(c);
	return str;
}

void displayBitmap(Bitmap b){
	int i;
	char* str = malloc(sizeof(char) * 33);
	assert(str != NULL);
	printf("Length = %d, Ones : ", getLength(b));
	for(i = getLength(b) - 1; i >= 0; i--)
		printf("%u ", getOnes(b, i));
	printf("\n");
	for(i = getLength(b) - 1; i >= 0; i--){
		printf("%s ", wordToBinaryString(getWord(b, i), str));
	}
	printf("\n");
	free(str);
}

Bitmap newBitmap(){
	Bitmap b = malloc(sizeof(struct Bitmap));
	assert(b != NULL);
	b->ones = malloc(sizeof(byte));
	assert(b->ones != NULL);
	initializeOnes(b, 0);
	setLength(b, 1); //en int
	b->word = malloc(sizeof(int));
	assert(b->word != NULL);
	initializeWord(b, 0);
	return b;
}

void setBit(Bitmap b, int pos, int val){
	//Attention, un word : 0 <= pos <= 31
	assert(b != NULL);
	assert(val == 1 || val == 0);

	if(pos > getLength(b) * 32){
		if(pos % 32 > 0){
			b->word = realloc(b->word, sizeof(int) * ((pos/32) + 1));
			b->ones = realloc(b->ones, sizeof(byte) * ((pos/32) + 1));
			int nb = getLength(b);
			setLength(b, pos/32 + 1);
			for(; nb < (pos/32) + 1; nb++){
				initializeWord(b, nb);
				initializeOnes(b , nb);
				setOnes(b, getOnes(b, nb - 1), nb);
			}
		}
		else{
			b->word = realloc(b->word, sizeof(int) * (pos/32));
			b->ones = realloc(b->ones, sizeof(byte) * (pos/32));
			int nb = getLength(b);
			setLength(b, pos/32);
			for(; nb < pos/32; nb++){
				initializeWord(b, nb);
				initializeOnes(b , nb);
				setOnes(b, getOnes(b, nb - 1), nb);
			}
			setLength(b, pos/32);
		}
		assert(b->word != NULL);
	}

	int nb = 1 << (pos % 32);
	int i = pos/32;
	if((getWord(b, i) >> (pos % 32)) % 2 == 1){ //bit que l'on souhaite changé égal à 1
		if(val == 0){
			setWord(b, getWord(b, i) - nb, i);
			setOnes(b, getOnes(b, i) - 1, i);
		}
	}
	else{ //bit que l'on souhaite changé égal à 0
		if(val == 1){
			setWord(b, getWord(b, i) + nb, i);
			setOnes(b, getOnes(b, i) + 1, i);
		}
	}
}

void freeBitmap(Bitmap b){
	free(b->word);
	free(b);
}

Bitmap copyBitmap(Bitmap b){
	Bitmap b2 = newBitmap();
	int i;

	setLength(b2, getLength(b));

	b2->ones = malloc(sizeof(byte) * getLength(b2));
	assert(b2->ones != NULL);
	for(i = 0; i < getLength(b); i++)
		setOnes(b2, getOnes(b, i), i);

	b2->word = malloc(sizeof(int) * getLength(b2));
	assert(b2->word != NULL);
	for(i = 0; i < getLength(b); i++)
		setWord(b2, getWord(b, i), i);

	return b2;
}




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

	displayBitmap(b);
	displayBitmap(c);

	freeBitmap(b);
	freeBitmap(c);

	return 0;
} 



/* int rank1(Bitmap b, int i){
	assert(i < getLength(b)*32);
	if(getOnes(b) == 0)
		return 0;
	if(getOnes(b) == getLength(b)*32)
		return i + 1;

	int ini = 1;
	int end = b->ones;
	int pos;
	int bp;

	while(ini < end){
		pos = (ini + end) / 2;
		bp = select1(b, pos);
		if(bp == i)
			return pos;
		if(bp < i)
			ini = pos + 1;
		else
			end = pos - 1;
	}
	if(select1(b, ini) > i)
		return ini - 1;
	return ini;
}

int rank0(Bitmap b, int i){
	return i + 1 - rank1(b, i);
}

int select1(Bitmap b, int i){
	assert(i <= b->ones);
	assert(i != 0);
	if(b->ones == b->length * 8)
		return i - 1;

	int ini = 0;
	int end = (b->length * 8) -1;
	int pos;
	int br;

	while(ini < end){
		pos = (ini + end)/2;
		br = rank1(b, pos);
		if(br < i)
			ini = pos + 1;
		else
			end = pos;
	}
	return ini;
}

int select0(Bitmap b, int i){
	assert(i <= (b->length * 8) - b->ones);
	assert(i != 0);
	if(b->ones == 0)
		return i - 1;

	int ini = 0;
	int end = (b->length * 8) - 1;
	int pos;
	int br;

	while(ini < end){
		pos = (ini + end) / 2;
		br = rank0(b, pos);
		if(br < i)
			ini = pos + 1;
		else
			end = pos;
	}
	return ini;
} */