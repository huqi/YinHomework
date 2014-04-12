#ifndef BEZIERMOTION_H
#define BEZIERMOTION_H
#include "Motion.h"

class BezierMotion : public Motion
{
public:
	BezierMotion(void);
	~BezierMotion(void);
	void drawCtrlPositions(void);
	DualQuaternion calculatePir( int i, int r, double t);
	DualQuaternion getControlPoints( int i );
	vector<DualQuaternion> curvePointsComputation(void);
};

#endif /* BEZIERMOTION_H */