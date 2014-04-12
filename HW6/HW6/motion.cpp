#include <iostream>
#include <fstream>
#include <vector>
#include <GL\glut.h>

#include "motion.h"
#include "Quaternion.h"
#include "hMatrix.h"
#include "hPoint.h"

using namespace std;

void Motion::readCtrlPositions(char *fileNameArg)
{
	ifstream inFile(fileNameArg, ios::in);
	
	if (!inFile)
	{
		cerr<<"File" << fileNameArg << "could not be opened" << endl;
		exit(1);
	}

	int i;
	
	inFile >> numberOfPositions;
	
	Quaternion *RotationQuaternion = new Quaternion[numberOfPositions];
	Vector *TranslationVector = new Vector[numberOfPositions];

   	for(i=0; i<numberOfPositions; i++)
			inFile >> RotationQuaternion[i];
    	
    for(i=0; i<numberOfPositions; i++)
			inFile >> TranslationVector[i];
	
    for(i=0; i<numberOfPositions; i++)
    {
	   DualQuaternion dQ(RotationQuaternion[i], TranslationVector[i]);
	   ctrlPos.push_back(dQ);
	   cout<<"first position from input: "<<ctrlPos[i]<<endl;
    }

    delete[] RotationQuaternion;
    delete[] TranslationVector;
    
}

void Motion::writePositions(char *fileNameArg)
{
	ofstream outFile(fileNameArg, ios::out);
	
	if (!outFile)
	{
		cerr<<"File" << fileNameArg << "could not be opened for writing" << endl;
		exit(1);
	}

	int i;
	
	outFile << numberOfPositions << endl;
	
	for(i=0; i<numberOfPositions; i++)
		outFile<<ctrlPos[i]<<endl;
}


void Motion::drawCtrlPositions(void)
{
	vector <hMatrix> homogeneousMatricesForCtrlPositions;
	for (int i=0; i<numberOfPositions; i++)
	{
		homogeneousMatricesForCtrlPositions.push_back(ctrlPos[i].dualQuaternionToHomogeneousMatrix().transpose());
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


Motion::~Motion()
{
	
}