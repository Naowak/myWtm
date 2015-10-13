#include "bitmap.h"
#include <assert.h>

struct Bitmap{
	int ones;
	int length;
	byte* octet;
};

char* byteToBinary(byte b, char* str){
	str[8] = '\0';
	int i;
	char * c = malloc(sizeof(char));
	assert(c != NULL);
	for(i = 7; i >= 0; --i){
		sprintf(c, "%d", b%2);
		str[i] = c[0];
		b = b / 2;
	}
	free(c);
	return str;
}

void displayBitmap(Bitmap b){
	int i;
	char* str = malloc(sizeof(char) * 9);
	assert(str != NULL);
	for(i = b->length - 1; i >= 0; i--){
		printf("%s ", byteToBinary(b->octet[i], str));
	}
	printf("\n");
	free(str);
}

Bitmap newBitmap(){
	Bitmap b = malloc(sizeof(struct Bitmap));
	assert(b != NULL);
	b->ones = 0;
	b->length = 1; //en octet
	b->octet = malloc(sizeof(byte));
	assert(b->octet != NULL);
	return b;
}

void setBit(Bitmap b, int pos, int val){
	//Attention, un octet : 0 <= pos <= 7
	assert(b != NULL);
	assert(val == 1 || val == 0);

	if(pos > b->length * 8){
		if(pos % 8 > 0){
			b->octet = realloc(b->octet, sizeof(byte) * ((pos/8) + 1));
			b->length = pos/8 + 1;
		}
		else{
			b->octet = realloc(b->octet, sizeof(byte) * (pos/8));
			b->length = pos/8;
		}
		assert(b->octet != NULL);
	}

	int nb = 1 << (pos % 8);
	int i = pos/8;
	if((b->octet[i] >> (pos % 8)) % 2 == 1){ //bit que l'on souhaite changé égal à 1
		if(val == 0){
			b->octet[i] = b->octet[i] - nb;
			b->ones = b->ones - 1;
		}
	}
	else{ //bit que l'on souhaite changé égal à 0
		if(val == 1){
			b->octet[i] = b->octet[i] + nb;
			b->ones = b->ones + 1;
		}
	}
}

void freeBitmap(Bitmap b){
	free(b->octet);
	free(b);
}

Bitmap copyBitmap(Bitmap b){
	Bitmap b2 = newBitmap();
	b2->ones = b->ones;
	b2->length = b->length;
	b2->octet = malloc(sizeof(byte));
	assert(b2->octet != NULL);
	int i;
	for(i = 0; i < b->length; i++){
		b2->octet[i] = b->octet[i];
	}
	return b2;
}


int rank1(Bitmap b, int i){
	assert(i < b->length*8);
	if(b->ones == 0)
		return 0;
	if(b->ones == b->length*8)
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
}

int main(int argc, char** argv){
	Bitmap b = newBitmap();
	setBit(b, 2, 1);
	setBit(b, 12, 1);
	setBit(b, 20, 1);

	Bitmap c = copyBitmap(b);
	setBit(c, 12, 0);

	displayBitmap(b);
	displayBitmap(c);

	printf("rank1 de b : i = 16 : %d\n", rank1(b, 16));
	//printf("rank0 de b : i = 12 : %d\n", rank0(b, 12));
	//printf("select1 de c : i = 2 : %d\n", select1(c, 2));
	//printf("select0 de c : i = 5 : %d\n", select0(c, 5));

	freeBitmap(b);
	freeBitmap(c);

	return 0;
} 