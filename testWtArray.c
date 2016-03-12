#include "wtArray.h"

int main(int argc, char** argv){
	WtArray w = WtArrayFromFile("fic");

	printWtArray(w);

	printExtractWtArray(w);

	insertWtArrayMutable(w, 65, 33);
	insertWtArrayMutable(w, 42, 0);
	insertWtArrayMutable(w, 101, 32);

	printWtArray(w);

	printExtractWtArray(w);

	removeWtArrayMutable(w, 0);
	removeWtArrayMutable(w, 33);
	removeWtArrayMutable(w, 31);

	printWtArray(w);

	printExtractWtArray(w);

	freeWtArray(w);

}
