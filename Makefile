CFLAGS=-g



all: testBitmap testDict testWtpt createNumberRandom



testBitmap: testBitmap.o bitmap.o
	gcc -o testBitmap testBitmap.o bitmap.o 

testDict: testDict.o dict.o
	gcc -o testDict testDict.o dict.o

testWtpt: testWtpt.o wtpt.o
	gcc -o testWtpt testWtpt.o wtpt.o bitmap.o dict.o

createNumberRandom: createNumberRandom.o
	gcc -o createNumberRandom createNumberRandom.o



bitmap.o:  
	gcc -o bitmap.o -c bitmap.c $(CFLAGS)

dict.o: 
	gcc -o dict.o -c dict.c $(CFLAGS)

wtpt.o:
	gcc -o wtpt.o -c wtpt.c $(CFLAGS)

wtArray.o:
	gcc -o wtArray.o -c wtArray.c $(CFLAGS)





clean:
	rm -rf *.o testBitmap testDict testWtpt createNumberRandom

