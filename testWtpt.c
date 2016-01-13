#include "wtpt.h"

int main(int argc, char** argv){
	Wtpt w = WtptFromFile("fic");
	printWtpt(w);

	//Wtpt w2 = copyWtpt(w);
	printf("\n\n");
	//printWtpt(w2);

	//free(w2);
	free(w);

	/*-----test_WTPT_MUTABLE------*/
	printf("\n\n----------test_wtpt_mutable-----------\n\n");

	w = WtptFromFile("fic");

	printWtpt(w);
	insertWtptMutable(w, 12, 0);
	insertWtptMutable(w, 96, 4);
	//insertWtptMutable(w, 104, 25);
	//insertWtptMutable(w, 205, 35);

	printf("\n\n");
	printWtpt(w);

	removeWtptMutable(w, 0);
	removeWtptMutable(w, 4);
	removeWtptMutable(w, 2);

	printf("\n\n");
	printWtpt(w);

	modifyWtptMutable(w, 125, 0);
	modifyWtptMutable(w, 256, 2);
	modifyWtptMutable(w, 659, 1);

	printf("\n\n");
	printWtpt(w);

	return 0;
}