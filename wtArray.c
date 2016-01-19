#include "wtArray.h"

struct WtArray{
	Bitmap bitmap;
	Dict dict;
	TYPE nbElem;
	int high;
	int posDebutMiniBitmap;
	int posDansMiniBitmap;
};


Bitmap getBitmapWtArray(WtArray w){
	return w->bitmap;
}

WtArray getLeftSonWtArray(WtArray w){
	//TODO
}

WtArray getRightSonWtArray(WtArray w){
	//TODO
}

int getHighWtArray(WtArray w){
	return w->high;
}

Dict getDictWtArray(WtArray w){
	return w->dict;
}

TYPE getNumberOfElemWtArray(WtArray w){
	return w->nbElem;
}

static int getPosDansMiniBitmap(WtArray w){
	return w->posDansMiniBitmap;
}

static int getPosDebutMiniBitmap(WtArray w){
	return w->posDebutMiniBitmap;
}

static void setPosDansMiniBitmap(WtArray w, int pos){
	w->posDansMiniBitmap = pos;
}

static void setPosDebutMiniBitmap(WtArray w, int pos){
	w->posDebutMiniBitmap = pos;
}

static void setHigh(WtArray w, int high){
	w->high = high;
}

/* set the High of the WtArray w and his sons, and return the high of w */
static int setHighWtArray(WtArray w){
	//TODO
}

/* set The Bitmap from the WtArray w, by the bitmap b */
static void setBitmapWtArray(WtArray w, Bitmap b){
	w->bitmap = b;
}

/* set the left son of the WtArray w by the WtArray leftSon */
static void setLeftSonWtArray(WtArray w, WtArray leftSon){
	//TODO ????
} //HOW DOES IT WORK

/* set the right son of the WtArray w by the WtArray rightSon */
static void setRightSonWtArray(WtArray w, WtArray rightSon){
	//TODO ????
} //HOW DOES IT WORK

/* set the Dict in the WtArray w by the dict d */
static void setDictWtArray(WtArray w, Dict d){
	w->dict = d;
}

/* set the number of elem in the WtArray */
static void setNumberOfElemWtArray(WtArray w, TYPE nb){
	w->nbElem = nb;
}


WtArray newWtArray(){
	WtArray w = malloc(sizeof(struct WtArray));
	setBitmapWtArray(w, newBitmap());
	setDictWtArray(w, newDict());
	setHigh(w, 1);
	setNumberOfElemWtArray(w, 0);
	setPosDebutMiniBitmap(w, 0);
	setPosDansMiniBitmap(w, 0);
	return w;
}

//The dict rest the same one, be carefull
WtArray copyWtArray(WtArray w){
	if(w == NULL)
		return NULL;
	WtArray w2 = malloc(sizeof(struct WtArray));
	setBitmapWtArray(w2, copyBitmap(getBitmapWtArray(w)));
	setDictWtArray(w2, getDictWtArray(w));
	setHigh(w2, getHighWtArray(w));
	setNumberOfElemWtArray(w2, getNumberOfElemWtArray(w));
	setPosDansMiniBitmap(w2, getPosDansMiniBitmap(w));
	setPosDebutMiniBitmap(w2, getPosDebutMiniBitmap(w));
	return w2;
}

void freeWtpt(WtArray w){
	if(w != NULL){
		freeBitmap(getBitmapWtArray(w));
		freeDict(getDictWtArray(w));
		free(w);
	}
}


