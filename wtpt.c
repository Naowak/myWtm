#include "wtpt.h"

struct Wtpt{
	Bitmap bitmap;
	Wtpt leftSon;
	Wtpt rightSon;
	int high;
	Dict dict;
};
