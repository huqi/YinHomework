#ifndef BSPLINEMOTION_H
#define BSPLINEMOTION_H

#include "Motion.h"

class BSplineMotion : public Motion
{
public:
	BSplineMotion(void);
	~BSplineMotion(void);
	void drawCtrlPositions(void);

private:
	vector<DualQuaternion> inner;
	void generatePoints(void);
	void genPoints(int depth);
};

#endif /* BSPLINEMOTION_H */