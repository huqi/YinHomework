// motion.h defines all operations for a motion class

#ifndef MOTION_H
#define MOTION_H

#include <vector>

#include "DualQuaternion.h"

class Motion
{
public:
	~Motion();
	void readCtrlPositions(char *fileNameArg);
	void writePositions(char *fileNameArg);
	virtual void drawCtrlPositions(void);
	DualQuaternion GetCtrlPosAt(int i);
	vector<DualQuaternion> GetCtrlPos(void);
	int GetNunberOfPositions(void);

private:
	vector<DualQuaternion> ctrlPos;
	int numberOfPositions;

};

#endif
