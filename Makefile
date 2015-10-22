CFLAGS=-g



all: testBitmap testBitmapOperators



testBitmap: testBitmap.o bitmap.o
	gcc -o testBitmap testBitmap.o bitmap.o 

testBitmapOperators: testBitmapOperators.o bitmapOperators.o bitmap.o
	gcc -o testBitmapOperators testBitmapOperators.o bitmapOperators.o bitmap.o




bitmap.o: bitmap.c 
	gcc -o bitmap.o -c bitmap.c $(CFLAGS)

bitmapOperators.o: bitmapOperators.c 
	gcc -o bitmapOperators.o -c bitmapOperators.c $(CFLAGS)

testBitmap.o: testBitmap.c 
	gcc -o testBitmap.o -c testBitmap.c $(CFLAGS)

testBitmapOperators.o: bitmapOperators.c 
	gcc -o testBitmapOperators.o -c testBitmapOperators.c $(CFLAGS)



clean:
	rm -rf *.o bitmap bitmapOperators

