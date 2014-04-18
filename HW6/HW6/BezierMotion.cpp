#include <iostream>
#include <fstream>
#include <vector>
#include <GL\glut.h>

#include "BezierMotion.h"
#include "Quaternion.h"
#include "hMatrix.h"
#include "hPoint.h"

using namespace std;

BezierMotion::BezierMotion(void)
{

}

BezierMotion::~BezierMotion(void)
{

}

DualQuaternion BezierMotion::calculatePir( int i, int r, double t)
{
	if (r == 0)
	{
		return getControlPoints( i );
	}
	else
	{
		return (1-t)*calculatePir(i,r-1,t) + t*calculatePir(i+1,r-1,t);
	}
}

DualQuaternion BezierMotion::getControlPoints( int i )
{
	return ctrlPos.at(i);
}

vector<DualQuaternion> BezierMotion::curvePointsComputation()
{
	vector< DualQuaternion > curve_points;
	int degree = numberOfPositions-1;

	for ( double t = 0.00; t < 1.00; t += 0.04)
	{
		for ( int r = 0; r <= degree; r++ )
		{
			for ( int i = 0; i<= degree-r; i++)
			{
				DualQuaternion point = calculatePir( i, r, t);
				if( r == degree && i == 0 )
					curve_points.push_back( point );
			}
		}
	}

	return curve_points;
}

void BezierMotion::drawCtrlPositions(void)
{
	vector <hMatrix> homogeneousMatricesForCtrlPositions;
	vector<DualQuaternion> curve = curvePointsComputation();
	for (int i=0; i<curve.size(); i++)
	{
		homogeneousMatricesForCtrlPositions.push_back(curve[i].dualQuaternionToHomogeneousMatrix().transpose());
		double MatrixforOpenGLStack[16];

		for (int i1=0; i1<4; i1++)
			for (int i2=0; i2<4; i2++)
				MatrixforOpenGLStack[4*i1+i2] =  homogeneousMatricesForCtrlPositions.at(i).m[i1][i2];

		::glPushMatrix();
		::glMultMatrixd(MatrixforOpenGLStack);
		glutSolidTeapot(0.15);
		::glPopMatrix();
	}

}
