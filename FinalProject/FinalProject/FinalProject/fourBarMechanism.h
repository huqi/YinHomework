
#ifndef FOURBARMECHANISM_H
#define FOURBARMECHANISM_H

#include <vector>
#include "point2D.h"

using namespace std;


class fourBarMechanism
{
public:
	void readOriginalCurvePoints(char *fileNameArg);




private:
	vector<Point2D> originalCurvePoints;

};

#endif
