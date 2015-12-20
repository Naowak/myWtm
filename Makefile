CFLAGS=-g



all: testBitmap testBitmapOperators testDict testWtpt createNumberRandomFile



testBitmap: testBitmap.o bitmap.o
	gcc -o testBitmap testBitmap.o bitmap.o 

testBitmapOperators: testBitmapOperators.o bitmapOperators.o bitmap.o
	gcc -o testBitmapOperators testBitmapOperators.o bitmapOperators.o bitmap.o

testDict: testDict.o dict.o
	gcc -o testDict testDict.o dict.o

testWtpt: testWtpt.o wtpt.o
	gcc -o testWtpt testWtpt.o wtpt.o bitmap.o bitmapOperators.o dict.o

createNumberRandomFile: createNumberRandomFile.o
	gcc -o createNumberRandomFile createNumberRandomFile.o


bitmap.o:  
	gcc -o bitmap.o -c bitmap.c $(CFLAGS)

bitmapOperators.o:  
	gcc -o bitmapOperators.o -c bitmapOperators.c $(CFLAGS)

dict.o: 
	gcc -o dict.o -c dict.c $(CFLAGS)

wtpt.o:
	gcc -o wtpt.o -c wtpt.c $(CFLAGS)

testBitmap.o: 
	gcc -o testBitmap.o -c testBitmap.c $(CFLAGS)

testBitmapOperators.o:
	gcc -o testBitmapOperators.o -c testBitmapOperators.c $(CFLAGS)

testDict.o:
	gcc -o testDict.o -c testDict.c $(CFLAGS)




clean:
	rm -rf *.o testBitmap testBitmapOperators testDict testWtpt createNumberRandomFile

