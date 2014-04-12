#include <iostream>
#include <vector>
#include <GL/glut.h>

#include "motion.h"
#include "BezierMotion.h"
#include "OpenGLInitialization.h"
#include "Interaction.h"
#include "color.h"

using namespace std;

void display(void)
{
	static BezierMotion bm;

	Motion *mp = &bm;
	mp->readCtrlPositions("input.txt");

	::glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    ::glPushMatrix();
	::glTranslated( Interaction::m_xTrans, Interaction::m_yTrans, Interaction::m_zTrans);
	::glRotated(Interaction::m_xRotate, 1.0, 0.0, 0.0);
	::glRotated(Interaction::m_yRotate, 0.0, 1.0, 0.0);
	::glRotated(Interaction::m_zRotate, 0.0, 0.0, 1.0);

	::glMaterialfv(GL_FRONT,GL_DIFFUSE,BROWN);
	mp->drawCtrlPositions();
	::glPopMatrix();

	::glutSwapBuffers();
}

int main (int argc, char *argv[])
{
	
	//Initialize Default OpenGL window 
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_ALPHA);
   glutInitWindowSize (800, 600); 
   glutInitWindowPosition (0, 0);
   int win_id = glutCreateWindow("Motion Design Skeleton Code");
   
   init();
   setupLight();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMouseFunc(Interaction::mouseButtonEvents);
   glutMotionFunc(Interaction::mouseMotionEvents);
   glutKeyboardFunc(Interaction::keyboard);

   glutMainLoop();

	return 0;
}
