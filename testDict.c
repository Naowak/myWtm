#include "dict.h"

int main(int argc, char** argv){
	Dict d = newDictFromFile("fic");

	printf("longueur dict : %zu\n", getSizeDict(d));
	printf("longueur code dict : %d\n", getCodeSizeDict(d));
	
	printDict(d);

	Dict e = copyDict(d);
	printDict(e);

	freeDict(d);
	freeDict(e);

	return 0;
}