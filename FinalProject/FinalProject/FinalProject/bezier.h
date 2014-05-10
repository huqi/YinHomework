// Bezier.h
// Bezier class definition 

#ifndef BEZIER_H
#define BEZIER_H

#include <vector>
#include "Point2D.h"


using namespace std;

class Bezier 
{
	friend class Interaction;

public:
	Bezier( double *, int );  // constructor
	Bezier();
	~Bezier();
	void setPx( int, double );  // set x in coordinate 
	double getPx( int );        // get x in coordinate
	void setPy( int, double );  // set y in coordinate
	double getPy( int );        // get y in coordinate
    int getDegree();
	void setDegree( int );
	void deCasteljau_algorithm( double &, double &, double ); 
	void saveInFile( char *fileNameArg );            // draw Bezier curve 
    
private:
	vector<Point2D> B;
	int degree;
};

#endif

