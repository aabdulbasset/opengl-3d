
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

float width = 0.15;
int angle = 0;
int xAxis=0;int yAxis=0;
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clears color buffer just in case
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0,0.0,-5.0f);
   glRotatef(angle,xAxis,yAxis,0);
   glBegin(GL_QUADS);
    //Top
    glColor3f(0.1f, 0.1f, 0.1f);;
    glVertex3f(-1.0,1.0,0.15);
    glVertex3f(-1.0,1.0,-0.15);
    glVertex3f(1.0,1.0,-0.15);
    glVertex3f(1.0,1.0,0.15);

    //back
    glColor3f(0.1f, 0.1f, 0.1f);;
    glVertex3f(-1.0,1.0,-0.15);
    glVertex3f(-1.0,-1.0,-0.15);
    glVertex3f(1.0,-1.0,-0.15);
    glVertex3f(1.0,1.0,-0.15);

    //front
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0,1.0,0.15);
    glVertex3f(-1.0,-1.0,0.15);
    glVertex3f(1.0,-1.0,0.15);
    glVertex3f(1.0,1.0,0.15);

    //bottom
    glColor3f(0.1f, 0.1f, 0.1f);;
    glVertex3f(-1.0,-1.0,0.15);
    glVertex3f(-1.0,-1.0,-0.15);
    glVertex3f(1.0,-1.0,-0.15);
    glVertex3f(1.0,-1.0,0.15);

    //left
    glColor3f(0.1f, 0.1f, 0.1f);;
    glVertex3f(1.0,-1.0,0.15);
    glVertex3f(1.0,-1.0,-0.15);
    glVertex3f(1.0,1.0,-0.15);
    glVertex3f(1.0,1.0,0.15);

    //right
    glColor3f(0.1f, 0.1f, 0.1f);;
    glVertex3f(-1.0,-1.0,0.15);
    glVertex3f(-1.0,-1.0,-0.15);
    glVertex3f(-1.0,1.0,-0.15);
    glVertex3f(-1.0,1.0,0.15);
   glEnd();
   glutSwapBuffers(); // executes commands

}

void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1,2,200);
    glMatrixMode(GL_MODELVIEW);

}

void keyPress(unsigned char button,int x,int y){
    switch(button){
    case 'w':
        angle -= 10;
        xAxis = 1;
        yAxis = 0;
        glutPostRedisplay();
        break;
    case 's':
        angle += 10;
        xAxis = 1;
        yAxis = 0;
        glutPostRedisplay();
        break;

    case 'a':
        angle -= 10;
        xAxis = 0;
        yAxis = 1;
        glutPostRedisplay();
        break;

    case 'd':
        angle += 10;
        xAxis = 0;
        yAxis = 1;
        glutPostRedisplay();
        break;
    }
}

int main(int argc, char** argv) {
   init(argc, argv);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyPress);
   glutMainLoop();

   return 0;
}
