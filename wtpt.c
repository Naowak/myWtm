#include "wtpt.h"

struct Wtpt{
	Bitmap bitmap;
	Wtpt leftSon;
	Wtpt rightSon;
	int high;
	Dict dict;
	TYPE nbElem;
};



Bitmap getBitmapWtpt(Wtpt w){
	assert(w != NULL);
	return w->bitmap;
}

void setBitmapWtpt(Wtpt w, Bitmap b){
	w->bitmap = b;
}

Wtpt getLeftSonWtpt(Wtpt w){
	assert(w != NULL);
	return w->leftSon;
}

void setLeftSonWtpt(Wtpt w, Wtpt leftSon){
	w->leftSon = leftSon;
}

Wtpt getRightSonWtpt(Wtpt w){
	assert(w != NULL);
	return w->rightSon;
}

void setRightSonWtpt(Wtpt w, Wtpt rightSon){
	w->rightSon = rightSon;
}

int getHighWtpt(Wtpt w){
	assert(w != NULL);
	return w->high;
}

static void setHigh(Wtpt w, int high){
	w->high = high;
}

static max(int x, int y){
	if(x > y)
		return x;
	return y;
}

/*
	Calcul la hauteur de manière récursive de tout l'arbre,
	set chaque noeud à sa valeur
*/
int setAllHighWtpt(Wtpt w){
	if(w == NULL)
		return 0;
	else{
		setHigh(w, 1 + max(setAllHighWtpt(getLeftSonWtpt(w)), 
			               setAllHighWtpt(getRightSonWtpt(w))));
		return getHighWtpt(w);
	}

}

Dict getDictWtpt(Wtpt w){
	assert(w != NULL);
	return w->dict;
}

void setDictWtpt(Wtpt w, Dict d){
	w->dict = d;
}

TYPE getNumberOfElemWtpt(Wtpt w){
	assert(w != NULL);
	return w->nbElem;
}

void setNumberOfElemWtpt(Wtpt w, TYPE nb){
	w->nbElem = nb;
}



Wtpt newWtpt(){
	Wtpt w = malloc(sizeof(struct Wtpt));
	setBitmapWtpt(w, newBitmap());
	setHigh(w, 1);
	setDictWtpt(w, newDict());
	setLeftSonWtpt(w, NULL);
	setRightSonWtpt(w, NULL);
	setNumberOfElemWtpt(w, 0);
	return w;
}

Wtpt copyWtpt(Wtpt w){
	if(w == NULL)
		return NULL;
	Wtpt w2 = malloc(sizeof(struct Wtpt));
	setBitmapWtpt(w2, copyBitmap(getBitmapWtpt(w)));
	setLeftSonWtpt(w2, copyWtpt(getLeftSonWtpt(w)));
	setRightSonWtpt(w2, copyWtpt(getRightSonWtpt(w)));
	setHigh(w2, getHighWtpt(w));
	setDictWtpt(w2, getDictWtpt(w));
	return w2;
}

void freeWtpt(Wtpt w){
	if(w != NULL){
		freeBitmap(getBitmapWtpt(w));
		freeWtpt(getLeftSonWtpt(w));
		freeWtpt(getRightSonWtpt(w));
		freeDict(getDictWtpt(w));
		free(w);
	}
}

/*
	Mets le bit à la position pos du Bitmap de Wtpt au (pos+1)ème 
	bit correspondant à son code.
	Le fait de manière itératif sur ses fils droits et/ou gauches.
	Les initializes s'ils n'existent pas encore.

	/!\ Attention, la collision n'est pas gérer. L'elem sera écrasé si
	pos contient déjà une valeur. De plus un elem en plus sera compter
*/
static void putCharIntoWtpt(Wtpt w, TYPE c, int pos){
	TYPE code = addElemDict(getDictWtpt(w), c);
	int codeSize = getCodeSizeDict(getDictWtpt(w));

	Wtpt tmp = w;

	int bit;
	int i;
	
	for(i = 0; i < codeSize; i++){
		assert(w != NULL);

		bit = (code >> i) & 1; //bit = 1 ou 0
		setBit(getBitmapWtpt(w), pos, bit);
		setNumberOfElemWtpt(w, getNumberOfElemWtpt(w) + 1);

		if(pos != 0)
			/* pos devient le nombre de "bit" qu'il y avait avant lui
			On fait attention, car on ne peut pas utiliser rankB pour 0
			si pos est 0, finalement on reste à 0 :) */
			pos = rankB(getBitmapWtpt(w), pos, bit);

		if(i+1 < codeSize)
			if(bit){
				//bit == 1 donc droite
				if(getRightSonWtpt(w) == NULL){
					setRightSonWtpt(w, newWtpt());
				}
				w = getRightSonWtpt(w);
			}
			else{
				//bit == 0 donc gauche
				if(getLeftSonWtpt(w) == NULL){
					setLeftSonWtpt(w, newWtpt());
				}
				w = getLeftSonWtpt(w);
			}
	}
	setAllHighWtpt(tmp);
}


Wtpt WtptFromFile(char* fileName){
	Wtpt w = newWtpt();
	freeDict(getDictWtpt(w));
	setDictWtpt(w, newDictFromFile(fileName));

	int f = open(fileName, O_RDONLY);

	int n;
	TYPE s = 0;
	int pos = 0;
	char c;

	do{
		n = read(f, &c, sizeof(char));
		if(n == sizeof(char))
			if(c >= '0' && c <= '9'){
				if(s*10 > MAX_TYPE - c + '0'){
					printf("nombre dans fichier trop gros, %d\n", s);
					assert(0);
				}
				s *= 10;
				s += c - '0';			
			}
			else if(c == ' ' || c == '\n' || c == EOF){
				putCharIntoWtpt(w, s, pos);
				s = 0;
				pos++;
			}
			else{
				printf("Erreur : char != ' ' ou chiffre.\n");
				assert(0);
			}
	}while(n == sizeof(char));

	close(f);

	return w;
}


void printWtpt(Wtpt w){
	if(getLeftSonWtpt(w)){
		printWtpt(getLeftSonWtpt(w));
	}
	if(getRightSonWtpt(w)){
		printWtpt(getRightSonWtpt(w));
	}
	printf("Hauteur : %d\n", getHighWtpt(w));
	printf("Nb elem : %d\n", getNumberOfElemWtpt(w));
	printf("pointeur : %p\n", w);
	printBitmap(getBitmapWtpt(w));
}