#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"functions.h"

void lineProgram()
{	
	unsigned int ***Raster;
	double Points[4]={};
	int width = 0;
	int height = 0;
	double aux;
	int i;
	int j;
	int r = 0;
	int g = 0;
	int b = 0;
	Raster = malloc(1920 * sizeof(unsigned int **));
    	for (i = 0; i < 1920; ++i)
  	  {
   	     Raster[i] = malloc(1080 * sizeof(unsigned int *));
   	     for (j = 0; j < 1080; ++j)
   	     {
      	      Raster[i][j] = malloc(3);
      	  }
   	 }
	srand(clock());
	for( i = 0 ; i < 10000 ; i++ )
	{
		getXYValues( Points );
	}
	
	if(Points[3] - Points[1] == 0)
	{	
		if(Points[2] < Points[0])
		{
			aux = Points[0];
			Points[0] = Points[2];
			Points[2] = aux;		
		}
		printf("\nSpecial case, the algorith isn't going to be used, but the the program will draw the line :D\n");
		printf("The line ecuation is: y = %lf\n",Points[3]);	
		fillSpecialCase2( Points[0], Points[1], Points[2], Points[3], Raster, r, g, b );
		drawLine( Raster, width, height, 0 );
	}
	else if(Points[2] - Points[0] == 0)
	{	
		if(Points[3] < Points[1])
		{
			aux = Points[1];
			Points[1] = Points[3];
			Points[3] = aux;		
		}
		printf("\nSpecial case, the algorith isn't going to be used, but the the program will draw the line :D\n");
		printf("The line ecuation is: x = %lf\n",Points[0]);
		fillSpecialCase2( Points[0], Points[1], Points[2], Points[3], Raster, r, g, b );	
		drawLine( Raster, width, height, 0 );
	}
}

double* getXYValues( double* Points )
{
	double x0 = rand()%1920;
	double y0 = rand()%1080;
	double x1 = rand()%1920;
	double y1 = rand()%1080;
	printf("\nType the points where the line passes by.\nFormat (x0,y0),(x1,y1)");
	printf("\nx0:	");
	scanf("%lf",&x0);
	printf("y0:	");
	scanf("%lf",&y0);
	printf("x1:	");
	scanf("%lf",&x1);
	printf("y1:	");	
	scanf("%lf",&y1);
	if(x1 < x0)
	{
		Points[0] = x1;
		Points[1] = y1;
		Points[2] = x0;
		Points[3] = y0; 	
	}
	else
	{
		Points[0] = x0;
		Points[1] = y0;
		Points[2] = x1;
		Points[3] = y1; 
	}
	return Points;
}

int evaluateSlope( double slope, double* Points )
{
	if( slope > 1 )//The line is in the 2nd or 6th octect
	{
		return 2;
	}
	else if( slope < 0 && slope > -1 )//The line is in the 4th or 8th octect
	{
		return 3;
	}
	else if( slope < -1 )//The slope is in the 3rd or 7th octect
	{
		return 4;
	}	
	else//No problems, the line is in the 1st or 5th octect
		return 0;
}

void fillSpecialCase1( double x0, double y0, double x1, double y1, unsigned int***Raster, int r, int g, int b )
{
	for( int i = x0 ; i <= x1 ; i++ )
	{
		putPixel( i , y0 , Raster, r, g, b );
	}
}

void fillSpecialCase2( double x0, double y0, double x1, double y1, unsigned int***Raster, int r, int g, int b )
{
	for( int i = y0 ; i <= y1 ; i++ )
	{
		putPixel( x0 , i , Raster, r, g, b );
	}
}

void fillRasterNaivefillRasterNaive( double x0, double y0, double x1, double y1, double slope, double a, unsigned int***Raster, int evaluatedSlope, int r, int g, int b )
{
	putPixel( x0 , y0 , Raster, r, g, b );
	putPixel( x1 , y1 , Raster, r, g, b );
	for( int i = x0 + 1 ; i < x1 ; i++ )
	{
		y0 = slope*i + a ;
		putPixel( i , (int)y0 , Raster, r, g, b );
	}
}

void putPixel( int x, int y, unsigned int***Raster, int r, int g, int b )
{
	Raster[x][y][0]=r;
	Raster[x][y][1]=g;
	Raster[x][y][2]=b;
}
void drawLine( unsigned int***Raster, int width, int height, int evaluatedSlope )
{
	printf("P3\n");
	printf("1920 1080\n");
	printf("255\n");
	for( int i = height - 1 ; i >=0 ; i-- )
	{
		for( int j = 0 ; j < width ; j++ )
		{
			printf(" %d %d %d\t",Raster[i][j][0],Raster[i][j][2],Raster[i][j][3]);
		}
		printf("\n");
	}
}
