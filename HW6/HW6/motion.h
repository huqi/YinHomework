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
	void drawCtrlPositions(void);
		

public:
	vector<DualQuaternion> ctrlPos;
	int numberOfPositions;

};

#endif
