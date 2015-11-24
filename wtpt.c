#include "wtpt.h"

struct Wtpt{
	Bitmap bitmap;
	Wtpt leftSon;
	Wtpt rightSon;
	int high;
	Dict dict;
};



Bitmap getBitmap(Wtpt w){
	return w->bitmap;
}

static void setBitmap(Wtpt w, Bitmap b){
	w->bitmap = b;
}

Wtpt getLeftSon(Wtpt w){
	return w->leftSon;
}

static void setLeftSon(Wtpt w, Wtpt leftSon){
	w->leftSon = leftSon;
}

Wtpt getRightSon(Wtpt w){
	return w->rightSon;
}

static void setRightSon(Wtpt w, Wtpt rightSon){
	w->rightSon = rightSon;
}

int getHigh(Wtpt w){
	return w->high;
}

static void setHigh(Wtpt w, int high){
	w->high = high;
}

Dict getDict(Wtpt w){
	return w->dict;
}

static void setDict(Wtpt w, Dict d){
	w->dict = d;
}



Wtpt newWtpt(){
	Wtpt w = malloc(sizeof(struct Wtpt));
	setBitmap(w, newBitmap());
	setHigh(w, 0);
	setDict(w, newDict());
	return w;
}

Wtpt copyWtpt(Wtpt w){
	if(w == NULL)
		return NULL;
	Wtpt w2 = malloc(sizeof(struct Wtpt));
	setBitmap(w2, copyBitmap(getBitmap(w)));
	setLeftSon(w2, copyWtpt(getLeftSon(w)));
	setRightSon(w2, copyWtpt(getRightSon(w)));
	setHigh(w2, getHigh(w));
	setDict(w2, copyDict(getDict(w)));
	return w2;
}

void freeWtpt(Wtpt w){
	if(Wtpt != NULL){
		freeBitmap(getBitmap(w));
		freeWtpt(getLeftSon(w));
		freeWtpt(getRightSon(w));
		freeDict(getDict(w));
	}
}



/*Wtpt WtptFromFile(char* fileName){

}*/

