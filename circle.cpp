#include <iostream>
#include "graphics.h"

using namespace std;

#define PI 3.14159

void drawCircLe( int x, int y, int radius );

struct Circle {

	int x;
	int y;

	int radius;

};

int main( )
{

	initwindow(500, 500, "Circle");

	Circle c;
	c.x = 250;
	c.y = 250;
	c.radius = 100;

	drawCircLe( c.x, c.y, c.radius);

	while (!kbhit( ))
	{
		delay( 200 );
	}


	return 0;

}

void drawCircLe( int x, int y, int radius)
{
	
	// Base case.
	if( radius < 4 ) 
		return;

	// Draw circle
	int color = rand( ) % 15 + 2;
	setcolor( color );
	circle( x, y, radius );

	int newRadius = 0.51*radius;

	// Recursive calls
	// Calculating Cartesian coordinates from Polar coordinates 
	for(int i = 1; i <= 4; i++)
	{

		drawCircLe( x + radius * cos( i * PI / 2 ), y + radius * sin( i * PI / 2 ), newRadius);

	}

}