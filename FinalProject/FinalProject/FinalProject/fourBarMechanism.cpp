#include <fstream>
#include <iostream>
#include "point2D.h"
#include <vector>
#include "fourBarMechanism.h"

using namespace std;

void fourBarMechanism::readOriginalCurvePoints(char *fileNameArg)
{
	ifstream inFile(fileNameArg, ios::in);
	
	if (!inFile)
	{
		cerr <<"File" << fileNameArg << "could not be opened" << endl;
		exit(1);
	}

	int i;
	for( i=0; i<20;i++)
	{
		double x,y;
		inFile >> x >> y;
		Point2D p(x,y);
		originalCurvePoints.push_back(p);
	}




}