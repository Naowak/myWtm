#include "wtArray.h"

int main(int argc, char** argv){
	WtArray w = newWtArray();
	WtArray w2 = copyWtArray(w);
	freeWtArray(w);
	freeWtArray(w2);
}