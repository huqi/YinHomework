// bspline.h
// bspline class definition

#ifndef BSPLINE_H
#define BSPLINE_H

#include <vector>
#include "Point2D.h"

using namespace std;

class Bslpine
{
	friend class Interaction;

public:
	Bslpine( double *, int );  // constructor
	Bslpine();
	~Bslpine();
	void setPx( int, double );  // set x in coordinate 
	double getPx( int );        // get x in coordinate
	void setPy( int, double );  // set y in coordinate
	double getPy( int );        // get y in coordinate

	void setDegree( int );
	int getDegree();
	void generatePoints();
	void draw(int mode) ;
	
private:
	vector<Point2D> B;
	vector<Point2D> inner, mid, outer;
	void genPoints(int); 
	int degree;
};

#endif
