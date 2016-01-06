CFLAGS=-g



all: testBitmap testBitmapOperators testDict testWtpt createNumberRandomFile testBitmapMutable testWtptMutable



testBitmap: testBitmap.o bitmap.o
	gcc -o testBitmap testBitmap.o bitmap.o 

testBitmapOperators: testBitmapOperators.o bitmapOperators.o bitmap.o
	gcc -o testBitmapOperators testBitmapOperators.o bitmapOperators.o bitmap.o

testDict: testDict.o dict.o
	gcc -o testDict testDict.o dict.o

testWtpt: testWtpt.o wtpt.o
	gcc -o testWtpt testWtpt.o wtpt.o bitmap.o bitmapOperators.o dict.o

testBitmapMutable: testBitmapMutable.o bitmapMutable.o bitmap.o
	gcc -o testBitmapMutable testBitmapMutable.o bitmapMutable.o bitmap.o

testWtptMutable: testWtptMutable.o wtptMutable.o
	gcc -o testWtptMutable testWtptMutable.o wtpt.o wtptMutable.o bitmap.o bitmapOperators.o bitmapMutable.o dict.o 

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

bitmapMutable.o:
	gcc -o bitmapMutable.o -c bitmapMutable.c $(CFLAGS)

wtptMutable.o:
	gcc -o wtptMutable.o -c wtptMutable.c $(CFLAGS)





clean:
	rm -rf *.o testBitmap testBitmapOperators testDict testWtpt createNumberRandomFile testBitmapMutable testWtptMutable

