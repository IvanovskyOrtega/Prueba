#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int
main(void)
{
	int r;
	int g;
	int b;
	int i=0;
	int j=0;
	printf("P3\n");
	printf("1920 1080\n");
	printf("255\n");
	srand(clock());
	for( i = 0 ; i < 1080 ; i++ )
	{
		for( j = 0 ; j < 1920 ; j++ )
		{
			r = rand() % 256;
			srand(clock());
			g = rand() % 256;
			srand(clock());
			b = rand() % 256;
			printf(" %d %d %d\t",r,g,b);
		}
		printf("\n");
	}	
	return 0;
}

