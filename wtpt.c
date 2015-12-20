#include "wtpt.h"

struct Wtpt{
	Bitmap bitmap;
	Wtpt leftSon;
	Wtpt rightSon;
	int high;
	Dict dict;
};



Bitmap getBitmapWtpt(Wtpt w){
	return w->bitmap;
}

static void setBitmap(Wtpt w, Bitmap b){
	w->bitmap = b;
}

Wtpt getLeftSonWtpt(Wtpt w){
	return w->leftSon;
}

static void setLeftSon(Wtpt w, Wtpt leftSon){
	w->leftSon = leftSon;
}

Wtpt getRightSonWtpt(Wtpt w){
	return w->rightSon;
}

static void setRightSon(Wtpt w, Wtpt rightSon){
	w->rightSon = rightSon;
}



int getHighWtpt(Wtpt w){
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
static int setAllHighWtpt(Wtpt w){
	if(w == NULL)
		return 0;
	else{
		setHigh(w, 1 + max(setAllHighWtpt(getLeftSonWtpt(w)), 
			               setAllHighWtpt(getRightSonWtpt(w))));
		return getHighWtpt(w);
	}

}

Dict getDictWtpt(Wtpt w){
	return w->dict;
}

static void setDict(Wtpt w, Dict d){
	w->dict = d;
}



Wtpt newWtpt(){
	Wtpt w = malloc(sizeof(struct Wtpt));
	setBitmap(w, newBitmap());
	setHigh(w, 1);
	setDict(w, newDict());
	setLeftSon(w, NULL);
	setRightSon(w, NULL);
	return w;
}

Wtpt copyWtpt(Wtpt w){
	if(w == NULL)
		return NULL;
	Wtpt w2 = malloc(sizeof(struct Wtpt));
	setBitmap(w2, copyBitmap(getBitmapWtpt(w)));
	setLeftSon(w2, copyWtpt(getLeftSonWtpt(w)));
	setRightSon(w2, copyWtpt(getRightSonWtpt(w)));
	setHigh(w2, getHighWtpt(w));
	setDict(w2, copyDict(getDictWtpt(w)));
	return w2;
}

void freeWtpt(Wtpt w){
	if(w != NULL){
		freeBitmap(getBitmapWtpt(w));
		freeWtpt(getLeftSonWtpt(w));
		freeWtpt(getRightSonWtpt(w));
		freeDict(getDictWtpt(w));
	}
}

/*static getLengthInBitFromCode(TYPE code){
	int i;
	while(code )
}*/

/*
	Mets le bit à la position pos du Bitmap de Wtpt au (pos+1)ème 
	bit correspondant à son code.
	Le fait de manière récursive sur ses fils droits et/ou gauches.
	Les initializes s'ils n'existent pas encore.
*/
static void putCharIntoWtpt(Wtpt w, TYPE c, int pos){
	TYPE code = addElemDict(getDictWtpt(w), c);
	int codeSize = getCodeSizeDict(getDictWtpt(w));

	Wtpt tmp = w;

	int bit;
	int i;
	//peut etre faut il d'abord créer l'alphabet
	//ou alors codeSize = log2(code).
	for(i = 0; i < codeSize; i++){
		assert(w != NULL);

		bit = (code >> i) & 1; //bit = 1 ou 0
		setBit(getBitmapWtpt(w), pos, bit);

		pos = rankB(getBitmapWtpt(w), pos+1, bit);

		if(bit){
			//bit == 1 donc droite
			if(getRightSonWtpt(w) == NULL)
				setRightSon(w, newWtpt());
			w = getRightSonWtpt(w);
		}
		else{
			//bit == 0 donc gauche
			if(getLeftSonWtpt(w) == NULL)
				setLeftSon(w, newWtpt());
			w = getLeftSonWtpt(w);
		}
	}
	setAllHighWtpt(tmp);
}

/*static TYPE readCharFromWtpt(Wtpt w, int pos){
	//TODO
}*/



Wtpt WtptFromFile(char* fileName){
	Wtpt w = newWtpt();

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
				putCharIntoWtpt(w, s, pos); // WTF, pos = 33 mais il envois 28.
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

/*void FileFromWtpt(char* fileName, Wtpt w){
	int f = open(fileName, O_WRONLY | O_CREAT, 0666);
	//TODO

}*/

void printWtpt(Wtpt w){
	if(getLeftSonWtpt(w)){
		printWtpt(getLeftSonWtpt(w));
	}
	if(getRightSonWtpt(w)){
		printWtpt(getRightSonWtpt(w));
	}
	printf("Hauteur : %d\n", getHighWtpt(w));
	printBitmap(getBitmapWtpt(w));
}