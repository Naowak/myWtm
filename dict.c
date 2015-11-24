#include "dict.h"


struct Dict{
	TYPE* tab;
	size_t size;
	size_t sizeMax;
};



static TYPE* getTabDict(Dict d){
	return d->tab;
}

static void setTabDict(Dict d, TYPE* t){
	d->tab = t;
}

static void setElemTab(Dict d, int i, TYPE c){
	assert(i < getSizeDict(d));
	d->tab[i] = c;
}

static TYPE getElemTab(Dict d, int i){
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

static void initializeDict(Dict d, size_t n){
	setTabDict(d, malloc(sizeof(TYPE)*n));
	assert(getTabDict(d) != NULL);
	setSizeDict(d, 0);
	setSizeMaxDict(d, n);
}

static void agrandirDict(Dict d){
	setSizeMaxDict(d, getSizeMaxDict(d)*2);
	setTabDict(d, realloc(getTabDict(d), sizeof(TYPE)*getSizeMaxDict(d)));
	assert(getTabDict(d) != NULL);
}



Dict newDict(char* filename){
	assert(filename != NULL);

	Dict d = malloc(sizeof(struct Dict));
	assert(d != NULL);
	initializeDict(d, 16);

	int f = open(filename, O_RDONLY);

	int n;
	TYPE c;

	do{
		n = read(f, &c, sizeof(TYPE));
		if(n == sizeof(TYPE))
			addElemDict(d, c); //TODO : implements addElem !!
	}while(n == sizeof(TYPE));

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




int getCodeFromCharDict(Dict d, TYPE c){
	int i;
	for(i = 0; i < getSizeDict(d); i++){
		if(getCharFromCodeDict(d, i) == c)
			return i;
	}
	return -1;
}

TYPE getCharFromCodeDict(Dict d, int code){
	return getElemTab(d, code);
}

size_t getSizeDict(Dict d){
	return d->size;
}

int getCodeSizeDict(Dict d){
	int i = 0;
	size_t s = getSizeDict(d);
	while(s){
		s = s >> 1;
		i++;
	}
	return i; //i = log2(sizeDict)
}



void addElemDict(Dict d, TYPE c){
	if(getCodeFromCharDict(d, c) == -1){
		if(getSizeDict(d) == getSizeMaxDict(d)) // tax Max trop petite
			agrandirDict(d);
		setSizeDict(d, getSizeDict(d) + 1);
		setElemTab(d, getSizeDict(d) - 1, c);
	}
}

void removeElemDict(Dict d, TYPE c){
	int i = 0;
	while(i < getSizeDict(d) && getCharFromCodeDict(d, i) != c){
		i++;
	}
	for(i++; i < getSizeDict(d); i++){
		setElemTab(d, i-1, getCharFromCodeDict(d, i));
	}
	setSizeDict(d, getSizeDict(d) - 1);
}