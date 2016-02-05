#include "wtArray.h"

int main(int argc, char** argv){
	WtArray w = WtArrayFromFile("fic");

	printWtArray(w);

	freeWtArray(w);

}