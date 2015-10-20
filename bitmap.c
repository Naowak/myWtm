#include "bitmap.h"
#include <assert.h>

struct Bitmap{
	int ones;
	int length;
	int* word;
};

int getWord(Bitmap b, int i){
	assert(i < getLength(b));
	return b->word[i];
}

int getOnes(Bitmap b){
	return b->ones;
}

int getLength(Bitmap b){
	return b->length;
}

static void setWord(Bitmap b, int word, int i){
	b->word[i] = word;
}

static void setOnes(Bitmap b, int ones){
	b->ones = ones;
}

static void setLength(Bitmap b, int length){
	b->length = length;
}


char* wordToBinary(int w, char* str){
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
	for(i = getLength(b) - 1; i >= 0; i--){
		printf("%s ", wordToBinary(getWord(b, i), str));
	}
	printf("\n");
	free(str);
}

Bitmap newBitmap(){
	Bitmap b = malloc(sizeof(struct Bitmap));
	assert(b != NULL);
	setOnes(b, 0);
	setLength(b, 1); //en int
	b->word = malloc(sizeof(int));
	assert(b->word != NULL);
	return b;
}

void setBit(Bitmap b, int pos, int val){
	//Attention, un word : 0 <= pos <= 31
	assert(b != NULL);
	assert(val == 1 || val == 0);

	if(pos > getLength(b) * 32){
		if(pos % 32 > 0){
			b->word = realloc(b->word, sizeof(int) * ((pos/32) + 1));
			setLength(b, pos/32 + 1);
		}
		else{
			b->word = realloc(b->word, sizeof(int) * (pos/32));
			setLength(b, pos/32);
		}
		assert(b->word != NULL);
	}

	int nb = 1 << (pos % 32);
	int i = pos/32;
	if((getWord(b, i) >> (pos % 32)) % 2 == 1){ //bit que l'on souhaite changé égal à 1
		if(val == 0){
			setWord(b, getWord(b, i) - nb, i);
			setOnes(b, getOnes(b) - 1);
		}
	}
	else{ //bit que l'on souhaite changé égal à 0
		if(val == 1){
			setWord(b, getWord(b, i) + nb, i);
			setOnes(b, getOnes(b) + 1);
		}
	}
}

void freeBitmap(Bitmap b){
	free(b->word);
	free(b);
}

Bitmap copyBitmap(Bitmap b){
	Bitmap b2 = newBitmap();
	setOnes(b2, getOnes(b));
	setLength(b2, getLength(b));
	b2->word = malloc(sizeof(int) * getLength(b2));
	assert(b2->word != NULL);
	int i;
	for(i = 0; i < getLength(b); i++){
		setWord(b2, getWord(b, i), i);
	}
	return b2;
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

int main(int argc, char** argv){
	Bitmap b = newBitmap();
	setBit(b, 2, 1);
	setBit(b, 12, 1);
	setBit(b, 20, 1);

	Bitmap c = copyBitmap(b);
	setBit(c, 12, 0);

	displayBitmap(b);
	displayBitmap(c);

	//printf("rank1 de b : i = 16 : %d\n", rank1(b, 16));
	//printf("rank0 de b : i = 12 : %d\n", rank0(b, 12));
	//printf("select1 de c : i = 2 : %d\n", select1(c, 2));
	//printf("select0 de c : i = 5 : %d\n", select0(c, 5));

	freeBitmap(b);
	freeBitmap(c);

	return 0;
} 