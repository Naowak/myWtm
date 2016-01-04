#ifndef __BITMAP_MUTABLE_H__
#define __BITMAP_MUTABLE_H__

#include "bitmap.h"

/* Insert in the Bitmap b, the bit bit, to the position pos */
Bitmap insertBitmapMutable(Bitmap b, int bit, int pos);

/* Remove from the Bitmap b, the bit to the position pos */
Bitmap removeBitmapMutable(Bitmap b, int pos);

/* Modify the bit in the Bitmap b, at the position pos,
by the bit bit */
Bitmap modifyBitmapMutable(Bitmap b, int bit, int pos);

#endif