CFLAGS=-g



all: testBitmap testDict testWtpt createNumberRandom testWtArray



testBitmap: testBitmap.o bitmap.o
	gcc -o testBitmap testBitmap.o bitmap.o 

testDict: testDict.o dict.o
	gcc -o testDict testDict.o dict.o

testWtpt: testWtpt.o wtpt.o
	gcc -o testWtpt testWtpt.o wtpt.o bitmap.o dict.o

testWtArray: testWtArray.o wtArray.o
	gcc -o testWtArray testWtArray.o wtArray.o bitmap.o dict.o -lm

createNumberRandom: createNumberRandom.o
	gcc -o createNumberRandom createNumberRandom.o



bitmap.o: bitmap.c bitmap.h 
	gcc -o bitmap.o -c bitmap.c $(CFLAGS)

dict.o: dict.c dict.h
	gcc -o dict.o -c dict.c $(CFLAGS)

wtpt.o: wtpt.c wtpt.h dict.h dict.c bitmap.h bitmap.c
	gcc -o wtpt.o -c wtpt.c $(CFLAGS)

wtArray.o: wtArray.c wtArray.h dict.h dict.c bitmap.h bitmap.c
	gcc -o wtArray.o -c wtArray.c $(CFLAGS)





clean:
	rm -rf *.o testBitmap testDict testWtpt testWtArray createNumberRandom

