#include <iostream>
#include <fstream>
#include <vector>
#include <GL\glut.h>

#include "BSplineMotion.h"
#include "Quaternion.h"
#include "hMatrix.h"
#include "hPoint.h"

using namespace std;

BSplineMotion::BSplineMotion(void)
{

}

BSplineMotion::~BSplineMotion(void)
{

}

// initialize the curves//
void BSplineMotion::generatePoints(void) 
{
	inner = GetCtrlPos();
	genPoints(3); // The recursive call
}

void BSplineMotion::genPoints(int depth) 
{
	if(depth <= 1 ) 
		return;

	vector<DualQuaternion> newb; 

	for(size_t i = 0; i < inner.size(); ++i) 
	{
		int iNext = (i+1)% inner.size();  // next vertice
		int iPrevious = (i+inner.size()-1)% inner.size();  // previous vertice

		DualQuaternion p1 = (inner[i] + inner[iNext]) * 0.5;
		DualQuaternion p2 = (inner[i] + inner[iPrevious]) * 0.5;
		DualQuaternion p3 = (p1 + p2) * 0.5;
		DualQuaternion p4 = (p3 + inner[i]) * 0.5;

		newb.push_back(p2);
		newb.push_back(p4);	
	}	

	inner = newb;

	genPoints(depth-1);
}

void BSplineMotion::drawCtrlPositions(void)
{
	vector <hMatrix> homogeneousMatricesForCtrlPositions;
	generatePoints();
	for (int i=0; i<inner.size(); i++)
	{
		homogeneousMatricesForCtrlPositions.push_back(inner[i].dualQuaternionToHomogeneousMatrix().transpose());
		double MatrixforOpenGLStack[16];

		for (int i1=0; i1<4; i1++)
			for (int i2=0; i2<4; i2++)
				MatrixforOpenGLStack[4*i1+i2] =  homogeneousMatricesForCtrlPositions.at(i).GetM(i1, i2);

		::glPushMatrix();
		::glMultMatrixd(MatrixforOpenGLStack);
		glutSolidTeapot(0.15);
		::glPopMatrix();
	}

}
