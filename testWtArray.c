#include "wtArray.h"

int main(int argc, char** argv){
	/* /!\ Attention, ce fichier de test marche pour fic allant de 1 à 32.
	Il peut ne pas marcher pour d'autre fichier fic */

	WtArray w = WtArrayFromFile("fic");

	printWtArray(w);
	printExtractWtArray(w);

	insertWtArrayMutable(w, 42, 0);
	insertWtArrayMutable(w, 101, 32);
	insertWtArrayMutable(w, 65, 33);

	printf("\nInsertion de 42 en 0, 101 en 32, 65 en 33 (Donc à la fin).\n");

	printWtArray(w);
	printExtractWtArray(w);

	printf("\nRemove des éléments rajoutés. -> On doit donc obtenir le même résultat qu'au début.\n");

	removeWtArrayMutable(w, 0);
	removeWtArrayMutable(w, 32);
	removeWtArrayMutable(w, 31);

	printWtArray(w);
	printExtractWtArray(w);

	printf("\nModify de pos 0 en 3000, pos 16 en 4000 et pos 32 en 5000.\n");

	modifyWtArrayMutable(w, 3000, 0);
	modifyWtArrayMutable(w, 4000, 16);
	modifyWtArrayMutable(w, 5000, 31);

	printWtArray(w);
	printExtractWtArray(w);

	freeWtArray(w);

}
