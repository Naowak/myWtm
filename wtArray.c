#include "wtArray.h"

struct wtArray{
	Bitmap bitmap;
	Dict dict;
	TYPE nbElem;
	int high;

	int highMiniBitmap;
	int posDebutMiniBitmap;
	int nbElemMiniBitmap;
};

static int getHighMiniBitmap(WtArray w){
	return w->highMiniBitmap;
}
static void setHighMiniBitmap(WtArray w, int highMiniBitmap){
	w->highMiniBitmap = highMiniBitmap;
}
static int getNbElemMiniBitmap(WtArray w){
	return w->nbElemMiniBitmap;
}
static void setNbElemMiniBitmap(WtArray w, int nb){
	w->nbElemMiniBitmap = nb;
}
static int getPosDebutMiniBitmap(WtArray w){
	return w->posDebutMiniBitmap;
}
static void setPosDebutMiniBitmap(WtArray w, int pos){
	w->posDebutMiniBitmap = pos;
}
static WtArray initAllAttributMiniBitmap(WtArray w){
	setHighMiniBitmap(w, 1);
	setPosDebutMiniBitmap(w, 0);
	setNbElemMiniBitmap(w, getNumberOfElemWtArray(w));
	return w;
}



static void setHigh(WtArray w, int high){
	w->high = high;
}
/* set The Bitmap from the WtArray w, by the bitmap b */
static void setBitmapWtArray(WtArray w, Bitmap b){
	w->bitmap = b;
}
/* set the Dict in the WtArray w by the dict d */
static void setDictWtArray(WtArray w, Dict d){
	w->dict = d;
}
/* set the number of elem in the WtArray */
static void setNumberOfElemWtArray(WtArray w, TYPE nb){
	w->nbElem = nb;
}





Bitmap getBitmapWtArray(WtArray w){
	return w->bitmap;
}

WtArray getLeftSonWtArray(WtArray w){
	if(getNumberOfElemWtArray(w) == 0 || getHighMiniBitmap(w) + 1 >= getHighWtArray(w))
		return NULL;

	//Fixe le nombre d'élément du fils gauche
	setNbElemMiniBitmap(w, 
		rankB(getBitmapWtArray(w), getPosDebutMiniBitmap(w) + getNbElemMiniBitmap(w), 0) 
		- getPosDebutMiniBitmap(w) != 0 ? 
			rankB(getBitmapWtArray(w), getPosDebutMiniBitmap(w), 0)
			: 0);

	//Fixe la position du début du fils gauche
	setPosDebutMiniBitmap(w, getHighMiniBitmap(w) * getNumberOfElemWtArray(w) +
		getPosDebutMiniBitmap(w) % getNumberOfElemWtArray(w));

	//Fixe la hauteur du mini Bitmap
	setHighMiniBitmap(w, getHighMiniBitmap(w) + 1);

	return w;
}

WtArray getRightSonWtArray(WtArray w){
	if(getNumberOfElemWtArray(w) == 0 || getHighMiniBitmap(w) + 1 >= getHighWtArray(w))
		return NULL;

	//Fixe le nombre d'élément du fils droit
	setNbElemMiniBitmap(w, 
		rankB(getBitmapWtArray(w), getPosDebutMiniBitmap(w) + getNbElemMiniBitmap(w), 1) 
		- getPosDebutMiniBitmap(w) != 0 ? 
			rankB(getBitmapWtArray(w), getPosDebutMiniBitmap(w), 1)
			: 0);

	//Fixe la position du début du fils droit
	setPosDebutMiniBitmap(w, getHighMiniBitmap(w) * getNumberOfElemWtArray(w) +
		getPosDebutMiniBitmap(w) % getNumberOfElemWtArray(w) + 
		rankB(getBitmapWtArray(w), getPosDebutMiniBitmap(w) + getNbElemMiniBitmap(w), 0) 
		- getPosDebutMiniBitmap(w) != 0 ? 
			rankB(getBitmapWtArray(w), getPosDebutMiniBitmap(w), 0)
			: 0);

	//Fixe la hauteur du mini Bitmap
	setHighMiniBitmap(w, getHighMiniBitmap(w) + 1);

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






WtArray newWtArray(){
	WtArray w = malloc(sizeof(struct wtArray));
	setBitmapWtArray(w, newBitmap());
	setDictWtArray(w, newDict());
	setHigh(w, 1);
	setNumberOfElemWtArray(w, 0);
	setPosDebutMiniBitmap(w, 0);
	setHighMiniBitmap(w, 1);
	setNbElemMiniBitmap(w, 0);
	return w;
}

//The dict rest the same one, be carefull
WtArray copyWtArray(WtArray w){
	if(w == NULL)
		return NULL;
	WtArray w2 = malloc(sizeof(struct wtArray));
	setBitmapWtArray(w2, copyBitmap(getBitmapWtArray(w)));
	setDictWtArray(w2, copyDict(getDictWtArray(w))); // /!\ Pas pareil sur Wtpt
	setHigh(w2, getHighWtArray(w));
	setNumberOfElemWtArray(w2, getNumberOfElemWtArray(w));
	setPosDebutMiniBitmap(w2, getPosDebutMiniBitmap(w));
	setHighMiniBitmap(w2, getHighMiniBitmap(w));
	setNbElemMiniBitmap(w2, getNbElemMiniBitmap(w));
	return w2;
}

static WtArray backUpWtArray(WtArray w){
	WtArray w2 = malloc(sizeof(struct wtArray));
	setBitmapWtArray(w2, getBitmapWtArray(w));
	setDictWtArray(w2, getDictWtArray(w));
	setHigh(w2, getHighWtArray(w));
	setNumberOfElemWtArray(w2, getNumberOfElemWtArray(w));
	setPosDebutMiniBitmap(w2, getPosDebutMiniBitmap(w));
	setHighMiniBitmap(w2, getHighMiniBitmap(w));
	setNbElemMiniBitmap(w2, getNbElemMiniBitmap(w));
	return w2;
}

void freeWtArray(WtArray w){
	if(w != NULL){
		freeBitmap(getBitmapWtArray(w));
		freeDict(getDictWtArray(w));
		free(w);
	}
}





static void putElemIntoWtArray(WtArray w, TYPE c, int pos){

	/*

	ATTENTION, POS DOIT IL ETRE DE LA BONNE TAILLE ?

	*/
	//assert(pos < getNb)
	TYPE code = addElemDict(getDictWtArray(w), c);
	int codeSize = getCodeSizeDict(getDictWtArray(w));

	WtArray tmp = backUpWtArray(w);

	int bit;
	int i;

	for(i = 0; i < codeSize, i++){
		assert(w != NULL);

		bit = (code >> i) & 1;
		setBit(getBitmapWtArray(w), pos, bit)
	}
}


void printWtArray(WtArray w){
	int i;
	int j;
	int cmp = 0;
	for(i = 1; i++; i <= getHighWtArray(w)){
		printf("%d : ", getHighWtArray(w));
		for(j = 0; j++; j < getNumberOfElemWtArray(w), cmp++){
			printf("%d", getBit(getBitmapWtArray(w), cmp));
		}
	}
}


