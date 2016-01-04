#ifndef __WTPT_MUTABLE_H__
#define __WTPT_MUTABLE_H__

#include "wtpt.h"


/* Insert in the Wtpt w, the caractere c, to the position pos. */
void insertInWtpt(Wtpt w, TYPE c, int pos);

/* Remove from the Wtpt w, the caractere which is at the
position pos */
void removeFromWtpt(Wtpt w, int pos);

/* Modify the caractere at the position pos, by the caractere c */
void modifyInWtpt(Wtpt w, TYPE c, int pos);

/*
/!\ Necessite ces mêmes fonctions sur des bitmaps
*/

#endif