#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char * argv){
	int fd = open("dict.c", O_RDONLY);
	int f2 = open("2test.txt", O_WRONLY | O_CREAT, 0666);
	int c = 0;
	int n = read(fd, &c, 1);
	n = write(f2, &c, 1);
}