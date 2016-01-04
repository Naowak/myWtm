#include "wtpt.h"

int main(int argc, char** argv){
	Wtpt w = WtptFromFile("fic");
	printWtpt(w);

	//Wtpt w2 = copyWtpt(w);
	printf("\n\n");
	//printWtpt(w2);

	//free(w2);
	free(w);
}