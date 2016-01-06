#include "wtptMutable.h"

/*
	Calcul la hauteur de manière récursive de tout l'arbre,
	set chaque noeud à sa valeur
*/

void insertWtptMutable(Wtpt w, TYPE c, int pos){
	assert(w != NULL);
	assert(pos <= getNumberOfElemWtpt(w)); //On peut ajouter en premier, en dernier ou entre

	TYPE code = addElemDict(getDictWtpt(w), c);
	int codeSize = getCodeSizeDict(getDictWtpt(w));

	Wtpt tmp = w;

	int bit;
	int i;

	for(i = 0; i < codeSize; i++){
		assert(w != NULL);

		bit = (code >> i) & 1; //bit = 1 ou 0
		insertBitmapMutable(getBitmapWtpt(w), bit, pos);
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
					setPosFar(getBitmapWtpt(getRightSonWtpt(w)), pos-1);
					setNumberOfElemWtpt(getRightSonWtpt(w), pos);
				}
				w = getRightSonWtpt(w);
			}
			else{
				//bit == 0 donc gauche
				if(getLeftSonWtpt(w) == NULL){
					setLeftSonWtpt(w, newWtpt());
					setPosFar(getBitmapWtpt(getLeftSonWtpt(w)), pos-1);
					setNumberOfElemWtpt(getLeftSonWtpt(w), pos);
				}
				w = getLeftSonWtpt(w);
			}
	}
	setAllHighWtpt(tmp);
}

/* 
	/!\ ATTENTION
	On ne prends pas en compte le fait qu'un wtpt atteigne 0 elem à l'intérieur.
	On devrait le supprimer si le cas présent arrive.
	Lui et tous ses fils.
*/
void removeWtptMutable(Wtpt w, int pos){
	assert(w != NULL);
	assert(pos < getNumberOfElemWtpt(w));
	assert(getNumberOfElemWtpt(w) > 0);

	int codeSize = getCodeSizeDict(getDictWtpt(w));

	Wtpt tmp = w;

	int bit;
	int i;
	for(i = 0; i < codeSize; i++){
		bit =  (getWord(getBitmapWtpt(w), pos/32) >> pos) & 1;
		removeBitmapMutable(getBitmapWtpt(w), pos);
		setNumberOfElemWtpt(w, getNumberOfElemWtpt(w) - 1);

		if(pos != 0)
			/* pos devient le nombre de "bit" qu'il y avait avant lui
			On fait attention, car on ne peut pas utiliser rankB pour 0
			si pos est 0, finalement on reste à 0 :) */
			pos = rankB(getBitmapWtpt(w), pos, bit);

		if(i+1 < codeSize)
			if(bit)
				//bit == 1 donc droite
				w = getRightSonWtpt(w);
			else
				//bit == 0 donc gauche
				w = getLeftSonWtpt(w);

		if(w == NULL)
			break;
	}
	setAllHighWtpt(tmp);
}