#include<iostream>
#include"bezier.h"
using namespace std;

int main()
{
	double controlPoints[] = { 0, 0, 3, 5, 6, -3, 5, 0 };
	Bezier b( controlPoints, 3 );
	b.saveInFile( "bezierPoints.txt" );
	
}
