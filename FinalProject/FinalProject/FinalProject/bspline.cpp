// bspline.cpp
// bspline class member function definition

#include <iostream>
#include <GL/glut.h>
#include <vector>

using namespace std;

#include "bslpine.h"
#include "Point2D.h"

const int number_points = 20;
const int depth = 5; // 4 times refinement

Bslpine::Bslpine(double *controlPoints_array, int count)
{
	for (int i=0; i<count+1; i++ )
	{
		Point2D P;
		P.setPx(controlPoints_array[2*i]);
		P.setPy(controlPoints_array[2*i+ 1]);
		B.push_back(P);
	}

	degree = count;
	generatePoints();
}

Bslpine::Bslpine() 
{
	degree = -1;
}

Bslpine::~Bslpine()
{

}

void Bslpine::setDegree( int d)
{
	degree = d;
}

int Bslpine::getDegree() 
{
	return degree;
}

// initialize the curves//
void Bslpine::generatePoints() 
{
	inner = B;
	genPoints(depth); // The recursive call
}

void  Bslpine::genPoints(int depth) 
{
	if(depth <= 1 ) 
		return;

	vector<Point2D> newb;   // for storing generated points for 4-Point curve.

	//for(size_t i = 0; i < inner.size(); ++i) 
	//{
	//	int iNext = (i+1)% inner.size();  // next vertice
	//	int iPrevious = (i+inner.size()-1)% inner.size();  // previous vertice

	//	Point2D p1 = inner[i].add(inner[iNext]).multiply(0.5);  // one new neighbor, midpoint of next edge
	//	Point2D p2 = inner[i].add(inner[iPrevious]).multiply(0.5); // the other new neighbor, midpoint of previous edge
	//	Point2D p3 = p1.add(p2).multiply(0.5); // average of the new neighbors
	//	Point2D p4 = p3.add(inner[i]).multiply(0.5); // adjust the original vertice by moving it halfway towards the average of the new neighbors
	//	newb.push_back(p2);
	//	newb.push_back(p4);	
	//}	
	
	inner = newb;

	genPoints(depth-1);
}

void Bslpine::draw(int mode) 
{
	// generate control points//
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	for (unsigned i=0; i< B.size(); i++)
	{
		glVertex2f( (B[i]).getPx(), (B[i]).getPy() );
	}
	glEnd();

	// connect generated control points//
	glColor3d (0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	for (unsigned k = 0; k < B.size(); k++ )
	{
		glVertex2f( (B[k]).getPx(), (B[k]).getPy() );
	}
	glEnd();

	generatePoints(); 

	// draw B-spline subdivision //
	/*glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	for(unsigned int i = 0; i < inner.size(); i++)
	{
		glVertex2d(inner[i].getPx(), inner[i].getPy());
	}
	glEnd();*/

	 //draw 4-points subdivision//
	glColor3f(0.0f, 1.0f, 0.0f);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	for(unsigned i = 0; i < mid.size(); i++)
	{
		glVertex2d(mid[i].getPx(), mid[i].getPy());
	}
	glEnd();

	// draw Jarek curve //
	glColor3f(0.0f, 0.0f, 1.0f);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	for(unsigned int i = 0; i< outer.size(); i++)
	{
		glVertex2d(outer[i].getPx(), outer[i].getPy());
	}
	glEnd();		
}