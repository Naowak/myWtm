#include "wtptMutable.h"

int main(int argc, char** argv){
	Wtpt w = WtptFromFile("fic");

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

	return 0;
}