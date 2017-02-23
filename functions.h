#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

void lineProgram();
double* getXYValues( double* Points );
int evaluateSlope( double slope, double* Points );
void fillSpecialCase1( double x0, double y0, double x1, double y1, unsigned int***Raster, int r, int g, int b );
void fillSpecialCase2( double x0, double y0, double x1, double y1, unsigned int***Raster, int r, int g, int b );	
void fillRasterDDA( double x0, double y0, double x1, double y1, double slope, unsigned int***Raster, int evaluatedSlope );
void fillRasterNaive( double x0, double y0, double x1, double y1, double slope, double a, unsigned int***Raster, int evaluatedSlope, int r, int g, int b );
void fillRasterBresenham( int x0, int y0, int x1, int y1, unsigned int***Raster, int evaluatedSlope );
void putPixel( int x, int y, unsigned int***Raster, int r, int g, int b );
void drawLine( unsigned int***Raster, int width, int height, int evaluatedSlope );

#endif
