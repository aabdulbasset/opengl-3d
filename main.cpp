
#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

void init(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3D Screen");
	glEnable(GL_DEPTH_TEST);
}




void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clears color buffer just in case

   glTranslatef(0.0,0.0,-5.0f);
   glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,1.0);

    glColor3f(0,1,0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);

    glColor3f(0,0,1);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,1.0,1.0);

    glColor3f(1,1,0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,1.0);
   glEnd();
   glutSwapBuffers(); // executes commands

}

void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1,2,10);
    glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char** argv) {
   init(argc, argv);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();

   return 0;
}
