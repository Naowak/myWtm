#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv){
	int n = 100;
	if(argc == 2)
		n = atoi(argv[1]);

	int f = open("fic", O_RDONLY | O_CREAT, 0666);

	int i;
	int nb;
	for(i = 0; i < n; i++){
		nb = (int) random();
		if(nb < 0)
			nb*= -1;
		printf("%d\n", nb);
	}

	return EXIT_SUCCESS;

}
