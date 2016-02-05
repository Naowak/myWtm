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

//retourne une copie exacte du WtArray, sans refaire de bitmap ou dict.
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





static void putElemIntoWtArray(WtArray w, TYPE c, int pos, int* tab){
	//pos correspond ici à chaque fois à la position dans le mini bitmap
	TYPE code = getCodeFromCharDict(getDictWtArray(w), c);
	assert(code != -1);
	int codeSize = getCodeSizeDict(getDictWtArray(w));

	int bit;
	int i;
	int j = 0;
	int debutMiniBitmap;

	for(i = 0; i < codeSize; i++){
		bit = (code >> i) & 1;
		debutMiniBitmap = ((j-1) >= 0 ? tab[j-1] : 0);
		setBit(getBitmapWtArray(w), pos + debutMiniBitmap, bit);

		if(pos > 0){
			pos = rankB(getBitmapWtArray(w), pos, bit);
			if(debutMiniBitmap > 0) 
				pos -= rankB(getBitmapWtArray(w), debutMiniBitmap, bit);
		}

		if(bit)
			j = j*2+2;
		else
			j = j*2+1;
	}
}

WtArray WtArrayFromFile(char* fileName){
	WtArray w = newWtArray();

	int f = open(fileName, O_RDONLY);

	/* Première lecture du fichier pour initialiser le dict */
	int n;
	TYPE s = 0;
	char c;
	do{
		n = read(f, &c, sizeof(char));
		if(n == sizeof(char))
			if(c >= '0' && c <= '9'){
				if(s*10 + c-'0' > MAX_TYPE){
					printf("nombre fichier trop gros, %d\n", s);
					assert(0);
				}
				s *= 10;
				s += c - '0';			
			}
			else if(c == ' ' || c == '\n' || c == EOF){
				//Ici, un elem est reconnu
				addElemDict(getDictWtArray(w), s);
				s = 0;
			}
			else{
				printf("Erreur : char != ' ' ou chiffre.\n");
				assert(0);
			}
	}while(n == sizeof(char));

	/* Deuxième lecture : permet de compter dans le tableau le nombre d'occurence de chaque elem */
	lseek(f, 0, SEEK_SET);
	int taille_tab = pow(2, getCodeSizeDict(getDictWtArray(w))) - 1;
	int tab[taille_tab];
	int i;
	int bit;
	int j;
	for(i = 0; i < taille_tab; i++)
		tab[i] = 0;

	s = 0;
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
				//Ici, un elem est reconnu, on augmente les cases du tableau auxquels ses bit correspondent
				TYPE code = getCodeFromCharDict(getDictWtArray(w), s);
				assert(code != -1);
				j = 0;
				for(i = 0; i < getCodeSizeDict(getDictWtArray(w)); i++){
					bit = (code >> i) & 1;
					int k;
					for(k = j; k < taille_tab; k++)
						//On souhaite que toutes les cases du tableau ait en valeur leur dernière position
						tab[k]++;
					if(bit)
						j = 2*j+2;
					else
						j = 2*j+1;
				}
				s = 0;
			}
			else{
				printf("Erreur : char != ' ' ou chiffre.\n");
				assert(0);
			}
	}while(n == sizeof(char));


	/* Troisième lecture pour placé les éléments dans wtpt. */
	lseek(f, 0, SEEK_SET);
	s = 0;
	int pos = 0;
	int nbElem = 0;

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
				//Ici, un elem est reconnu
				putElemIntoWtArray(w, s, pos, tab);
				s = 0;
				pos++;
				nbElem++;
			}
			else{
				printf("Erreur : char != ' ' ou chiffre.\n");
				assert(0);
			}
	}while(n == sizeof(char));

	setHigh(w, getCodeSizeDict(getDictWtArray(w)));
	setNumberOfElemWtArray(w, nbElem);

	close(f);

	return w;

}


void printWtArray(WtArray w){
	int i;
	int j;
	int cmp = 0;
	for(i = 1; i <= getHighWtArray(w); i++){
		printf("%d : ", getHighWtArray(w));
		for(j = 0; j < getNumberOfElemWtArray(w); cmp++, j++){
			printf("%d", getBit(getBitmapWtArray(w), cmp));
		}
		printf("\n");
	}
}
//A revoir, sens d'affichage


