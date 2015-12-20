#include "dict.h"

int main(int argc, char** argv){
	Dict d = newDictFromFile("fic");
	assert(getCodeFromCharDict(d, 2) == -1);
	printf("Ajout elem 2 case : %d, supposé égal à 33\n", addElemDict(d, 2));
	assert(getCodeFromCharDict(d, 2) != -1);
	printf("569 = %d\n", getCharFromCodeDict(d, 0));
	printf("34= %ld\n", getSizeDict(d));
	printf("6 = %d\n", getCodeSizeDict(d));

	printDict(d);

	removeElemDict(d, 'e');
	printf("\n\n");
	printDict(d);

	printf("\n\n");

	Dict np = copyDict(d);

	printDict(np);
	printf("\n569 = %d\n", getCharFromCodeDict(np, 0));
	printf("33 = %ld\n", getSizeDict(np));
	printf("6 = %d\n", getCodeSizeDict(np));

	freeDict(d);
	freeDict(np);

	return 0;
}