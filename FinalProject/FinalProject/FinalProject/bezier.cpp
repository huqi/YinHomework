// bezier.cpp
// Bezier class member function definition

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#include "Bezier.h"
#include "Point2D.h"

const int number_points = 20;

// constructor 
Bezier::Bezier( double *controlPoints_array, int d )
{
	
	for (int i=0; i<d+1; i++)
	{
		Point2D P;
		P.setPx(controlPoints_array[2*i]);
        P.setPy(controlPoints_array[2*i+ 1]);
		B.push_back(P);
	}
	
	degree = d;

}

Bezier::Bezier()
{	

	degree = -1;

}


// destructor
Bezier::~Bezier()
{

}

void Bezier::setPx( int Number, double xValue )
{
	(B[Number]).setPx(xValue);

}

double Bezier::getPx( int Number )
{
	return (B[Number]).getPx();

}

void Bezier::setPy( int Number, double yValue )
{
	(B[Number]).setPy( yValue );

}

double Bezier::getPy( int Number )
{
	return (B[Number]).getPy();

}

void Bezier::saveInFile ( char *fileNameArg ) 
{
	double t, Px, Py;
	ofstream outFile(fileNameArg, ios::out);
	if (!outFile)
	{
		cerr<<"File" << fileNameArg << "could not be edited" << endl;
		exit(1);
	}

	for ( t = 0.0; t < 1.000001; t += 1.0 / ( number_points - 1 ) )	
	{
		deCasteljau_algorithm( Px, Py, t );
		outFile << Px << " " << Py;
	}	
		
 }

// deCastejau_algorithm function
void Bezier::deCasteljau_algorithm( double &x, double &y, double t )
{
	vector<Point2D> tempB = B;

	for (unsigned r=1; r< B.size(); r++)
		for (unsigned i=0; i<B.size()-r; i++)
		{

			tempB[i].setPx( (1.0-t)*tempB[i].getPx() + t*tempB[i+1].getPx() );
			tempB[i].setPy( (1.0-t)*tempB[i].getPy() + t*tempB[i+1].getPy() );
		}
		x = tempB[0].getPx();
		y = tempB[0].getPy();		

}

int Bezier::getDegree() 
{
	return degree;
}

void Bezier::setDegree( int d)
{
	degree = d;
}
