#include "wtpt.h"

int main(int argc, char** argv){
	Wtpt w = WtptFromFile("fic");
	printWtpt(w);
}