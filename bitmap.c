#include "bitmap.h"

/* 
	Structure Bitmap :
		ones = nombre de 1
		length = nombre de mot de 32 bits
		word = tableau des mots
*/
struct Bitmap{
	byte* ones;
	int posFar; //nombre de mot stocké
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

int getOnesBitmap(Bitmap b){
	return getOnes(b, getLength(b) -1);
}

int getLength(Bitmap b){
	return b->length;
}

int getPosFar(Bitmap b){
	return b->posFar;
}

void setPosFar(Bitmap b, int pos){
	b->posFar = pos;
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
	//assert(ones <= 32);
	int tmp = ones - getOnes(b, i);
	int k;
	for(k = i; k < getLength(b); k++)
		b->ones[k] = getOnes(b, k) + tmp;
}

static void setLength(Bitmap b, int length){
	b->length = length;
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
	setPosFar(b, -1);
	return b;
}

void setBit(Bitmap b, int pos, int val){
	//Attention, un word : 0 <= pos <= 31
	assert(b != NULL);
	assert(val == 1 || val == 0);
	assert(pos >= 0);

	if(getPosFar(b) < pos)
		setPosFar(b, pos);

	if(pos >= getLength(b) * 32){
		//mot plus grand que zone alloué -> réalocation de la mémoire
		b->word = realloc(b->word, sizeof(int) * ((pos/32) + 1));
		assert(b->word != NULL);
		b->ones = realloc(b->ones, sizeof(byte) * ((pos/32) + 1));
		assert(b->ones != NULL);
		int nb = getLength(b);
		setLength(b, pos/32 + 1);
		for(; nb < (pos/32) + 1; nb++){
			initializeWord(b, nb);
			initializeOnes(b , nb);
			setOnes(b, getOnes(b, nb - 1), nb);
		}
	}

	int nb = 1 << (pos % 32);
	int i = pos/32;
	if((getWord(b, i) >> (pos % 32)) & 1){ //bit que l'on souhaite changé égal à 1
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

int getBit(Bitmap b, int pos){
	assert(b != NULL);
	assert(pos >= 0);
	if(pos > getPosFar(b))
		return -1;

	int q = pos/32;
	int r = pos%32;

	return (getWord(b, q) >> r) & 1;
}

void freeBitmap(Bitmap b){
	free(b->word);
	free(b->ones);
	free(b);
}

Bitmap copyBitmap(Bitmap b){
	Bitmap b2 = malloc(sizeof(struct Bitmap));
	assert(b2 != NULL);

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

static char* wordToBinaryString(int w, char* str){
	str[32] = '\0';
	int i;
	char * c = malloc(sizeof(char));
	assert(c != NULL);
	for(i = 31; i >= 0; --i){
		sprintf(c, "%d", w%2);
		str[i] = *c;
		w = w >> 1;
	}
	free(c);
	return str;
}

void printBitmap(Bitmap b){
	int i;
	char* str = malloc(sizeof(char) * 33);
	assert(str != NULL);
	/*printf("Length = %d, Ones : ", getLength(b));
	for(i = getLength(b) - 1; i >= 0; i--)
		printf("%u ", getOnes(b, i));
	printf("\n");*/
	for(i = getLength(b) - 1; i >= 0; i--){
		printf("%s ", wordToBinaryString(getWord(b, i), str));
	}
	printf("\n");
	free(str);
}
