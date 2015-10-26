#ifndef __BITMAP_OPERATORS_H__
#define __BITMAP_OPERATORS_H__

#include <assert.h>
#include "bitmap.h"

//return the number of bit in the i-th bit of the Bitmap b.
int rankB(Bitmap b, int i, int bit);
//return the location of the i-th bit in the Bitmap b.
int selectB(Bitmap b, int i, int bit);
//return the i-th bit
int accessB(Bitmap b, int i);

#endif