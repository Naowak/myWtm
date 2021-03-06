#include "dict.h"


struct Dict{
	int* tab;
	size_t size;
	size_t sizeMax;
	int codeSize;
};



static int* getTabDict(Dict d){
	return d->tab;
}

static void setTabDict(Dict d, int* t){
	d->tab = t;
}

static void setElemTab(Dict d, int i, int c){
	assert(i < getSizeDict(d));
	d->tab[i] = c;
}

static int getElemTab(Dict d, int i){
	assert(i < getSizeDict(d));
	return d->tab[i];
}

static void setSizeDict(Dict d, int n){
	d->size = n;
}

static void setSizeMaxDict(Dict d, int n){
	d->sizeMax = n;
}

static size_t getSizeMaxDict(Dict d){
	return d->sizeMax;
}

static void calculCodeSizeDict(Dict d){
	int i = 1;
	size_t s = getSizeDict(d) - 1;
	while(s >>= 1){
		i++;
	}
	d->codeSize = i; //i = log2(sizeDict)
}

static void initializeDict(Dict d, size_t n){
	setTabDict(d, malloc(sizeof(int)*n));
	assert(getTabDict(d) != NULL);
	setSizeDict(d, 0);
	setSizeMaxDict(d, n);
}

static void agrandirDict(Dict d){
	setSizeMaxDict(d, getSizeMaxDict(d)*2);
	setTabDict(d, realloc(getTabDict(d), sizeof(int)*getSizeMaxDict(d)));
	assert(getTabDict(d) != NULL);
}


Dict newDict(){
	Dict d = malloc(sizeof(struct Dict));
	assert(d != NULL);
	initializeDict(d, 16);
	setSizeDict(d, 0);
	return d;
}


Dict newDictFromFile(char* filename){
	Dict d = newDict();

	int f = open(filename, O_RDONLY);

	int n;
	int s = 0;
	char c;

	do{
		n = read(f, &c, sizeof(char));
		if(n == sizeof(char))
			if(c >= '0' && c <= '9'){
				if(s*10 + c-'0' > MAX_int){
					printf("nombre fichier trop gros, %d\n", s);
					assert(0);
				}
				s *= 10;
				s += c - '0';			
			}
			else if(c == ' ' || c == '\n' || c == EOF){
				addElemDict(d, s);
				s = 0;
			}
			else{
				printf("Erreur : char != ' ' ou chiffre.\n");
				assert(0);
			}
	}while(n == sizeof(char));

	close(f);

	return d;
}

Dict copyDict(Dict d){
	assert(d != NULL);

	Dict nd = malloc(sizeof(struct Dict));
	initializeDict(nd, getSizeMaxDict(d));

	int i;
	for(i = 0; i < getSizeDict(d); i++){
		addElemDict(nd, getElemTab(d, i));
	}

	return nd;
}

void freeDict(Dict d){
	free(getTabDict(d));
	free(d);	
}




int getCodeFromCharDict(Dict d, int c){
	int i;
	for(i = 0; i < getSizeDict(d); i++){
		if(getCharFromCodeDict(d, i) == c)
			return i;
	}
	return -1;
}

int getCharFromCodeDict(Dict d, int code){
	return getElemTab(d, code);
}

size_t getSizeDict(Dict d){
	return d->size;
}

int getCodeSizeDict(Dict d){
	return d->codeSize;
}



int addElemDict(Dict d, int c){
	//O(n), n = taille dict
	int nb = getCodeFromCharDict(d, c);
	if(nb == -1){
		if(getSizeDict(d) == getSizeMaxDict(d)) // tax Max trop petite
			agrandirDict(d);
		setSizeDict(d, getSizeDict(d) + 1);
		setElemTab(d, getSizeDict(d) - 1, c);
		calculCodeSizeDict(d);
		return getSizeDict(d) - 1;
	}
	return nb;
}

void removeElemDict(Dict d, int c){
	int i = 0;
	while(i < getSizeDict(d) && getCharFromCodeDict(d, i) != c){
		i++;
	}
	for(i++; i < getSizeDict(d); i++){
		setElemTab(d, i-1, getCharFromCodeDict(d, i));
	}
	setSizeDict(d, getSizeDict(d) - 1);
}

void printDict(Dict d){
	int i;
	printf("CodeSize : %d\n", getCodeSizeDict(d));
	for(i = 0; i < getSizeDict(d); i++)
		printf("%d:%d ", i, getCharFromCodeDict(d, i));
	printf("\n");
}