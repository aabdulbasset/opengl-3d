#include <GL/gl.h>
#include <GL/glut.h>
#include "vertices.h"

float rotateX = -60, rotateY = 15, rotateZ = 0;   // rotation angle for chair
float rotatesX = 0, rotatesY = 30, rotatesZ = 0;  // rotation angle for screen
float sclaeX = 0.25, sclaeY = 0.25 , sclaeZ=0.25; // Set up scale for chair
float sclaesX = 1, sclaesY = 1 , sclaesZ=1;       // Set up scale for screen
float tx = 2, ty = 0, tz = -5;                    // Translate for chair
float tsx = -2, tsy = 0, tsz = -5;                // Translate for screen
float r =.9, g=1, b=1;

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Screen
    glLoadIdentity();
    glTranslatef(tsx,tsy,tsz);
    glRotatef(rotatesX,1,0,0);
	glRotatef(rotatesY,0,1,0);
	glRotatef(rotatesZ,0,0,1);
    glScalef(sclaesX,sclaesY,sclaesZ);
    glBegin(GL_QUADS);
    //Top
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(-1.0,1.0,0.15);
    glVertex3f(-1.0,1.0,-0.15);
    glVertex3f(1.0,1.0,-0.15);
    glVertex3f(1.0,1.0,0.15);

    //back
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(-1.0,1.0,-0.15);
    glVertex3f(-1.0,-1.0,-0.15);
    glVertex3f(1.0,-1.0,-0.15);
    glVertex3f(1.0,1.0,-0.15);

    //front
    glColor3f(r, g, b);
    glVertex3f(-0.9,0.9,0.15);
    glVertex3f(-0.9,-0.9,0.15);
    glVertex3f(0.9,-0.9,0.15);
    glVertex3f(0.9,0.9,0.15);

    //bottom
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(-1.0,-1.0,0.15);
    glVertex3f(-1.0,-1.0,-0.15);
    glVertex3f(1.0,-1.0,-0.15);
    glVertex3f(1.0,-1.0,0.15);

    //left
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(1.0,-1.0,0.15);
    glVertex3f(1.0,-1.0,-0.15);
    glVertex3f(1.0,1.0,-0.15);
    glVertex3f(1.0,1.0,0.15);

    //right
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(-1.0,-1.0,0.15);
    glVertex3f(-1.0,-1.0,-0.15);
    glVertex3f(-1.0,1.0,-0.15);
    glVertex3f(-1.0,1.0,0.15);

    //--------------------------Holder------------------------
    //Front
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(-0.15,0,-0.15);
    glVertex3f(-0.15,-2,-0.15);
    glVertex3f(0.15,-2,-0.15);
    glVertex3f(0.15,0,-0.15);

    //Back
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(-0.15,0,-0.30);
    glVertex3f(-0.15,-2,-0.30);
    glVertex3f(0.15,-2,-0.30);
    glVertex3f(0.15,0,-0.30);

    //Right
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(0.15,0.0,-0.15);
    glVertex3f(0.15,-2.0,-0.15);
    glVertex3f(0.15,-2.0,-0.30);
    glVertex3f(0.15,0.0,-0.30);

    //Left
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(-0.15,0.0,-0.15);
    glVertex3f(-0.15,-2.0,-0.15);
    glVertex3f(-0.15,-2.0,-0.30);
    glVertex3f(-0.15,0.0,-0.30);

    //----------------------------Base--------------------------
    glColor3f(0.1f, 0.1f, 0.1f);
    glVertex3f(-0.5,-2.0,0.15);
    glVertex3f(0.5,-2.0,0.15);
    glVertex3f(0.5,-2.0,-0.60);
    glVertex3f(-0.5,-2.0,-0.60);
    glEnd();




    // ----------------------------------------------------------------------------------------------
    // Quote of the day a great man once said:
    // "You don't know until you know" Zico.
    //-----------------------------------------------------------------------------------------------

    // Chair
    glLoadIdentity();             // Set up modelview transform, second shape.

   glTranslatef(tx, ty,tz );        // Chair in the middle

    //  rotations.
	glRotatef(rotateX,1,0,0);
	glRotatef(rotateY,0,1,0);
	glRotatef(rotateZ,0,0,1);
    // Scale
     glScalef(sclaeX,sclaeX,sclaeX);

    glVertexPointer( 3, GL_FLOAT, 0, vertexCoords );  // Set data type and location, second shape.
    glColorPointer( 3, GL_FLOAT, 0, vertexColors );

    glEnableClientState( GL_VERTEX_ARRAY );             // enable use of array
    glEnableClientState( GL_COLOR_ARRAY );
    glPolygonOffset(1,1); // 1 for factor 1 for unit
    glEnable(GL_POLYGON_OFFSET_FILL); // change the deepth of all faces to get more sharp edges


    glDrawElements( GL_QUADS, 400, GL_UNSIGNED_INT, facesArray ); // Draw the chair
    glDisable(GL_POLYGON_OFFSET_FILL);

    glDisableClientState( GL_COLOR_ARRAY );  //No more color
    glColor3f(0.752, 0.443, 0.164); 	  // edges color
    glLineWidth(1);

    glDrawElements( GL_LINES, 392, GL_UNSIGNED_INT, edgeElementArray );  // Draw the edges

    glutSwapBuffers();
}

//Keys XD:
// Scale, Rotation && translation for chair
// Rest all values for default value for both screen && chair
// screen on/off
void specialKeyFunction(int key, int x, int y) {
    // Rotation
    if ( key == GLUT_KEY_LEFT )
       rotateY -= 15;
    if ( key == GLUT_KEY_RIGHT )
       rotateY += 15;
    if ( key == GLUT_KEY_DOWN)
       rotateX += 15;
    if ( key == GLUT_KEY_UP )
       rotateX -= 15;
    if ( key == GLUT_KEY_PAGE_UP )
       rotateZ += 15;
    if ( key == GLUT_KEY_PAGE_DOWN )
       rotateZ -= 15;
    // Scale
    if ( key == GLUT_KEY_F1)
       sclaeX += 0.01;
    if ( key == GLUT_KEY_F2)
       sclaeX -= 0.01;
    // Translate
    if ( key == GLUT_KEY_F3)
       tx -= 1;
    if ( key == GLUT_KEY_F4)
       tx += 1;
    if ( key == GLUT_KEY_F5)
       ty -= 1;
    if ( key == GLUT_KEY_F6)
       ty += 1;
    if ( key == GLUT_KEY_F7)
       tz-= 1;
    if ( key == GLUT_KEY_F8)
       tz += 1;
    // Rest all values for default value for both screen && chair
    if ( key == GLUT_KEY_HOME )
       {
        rotateX = -60, rotateY = 30, rotateZ = 0;
        rotatesX = 0, rotatesY = 30, rotatesZ = 0;
        sclaeX = 0.25, sclaeY = 0.25 , sclaeZ=0.25;
        sclaesX = 1, sclaesY = 1 , sclaesZ=1;
        tx = 2, ty = 0, tz = -5;
        tsx = -2, tsy = 0, tsz = -5;
       }
}

// Translate for screen

void keyPress(unsigned char button,int x,int y){
    switch(button){
    case 'w':
        tsy+=1;
        glutPostRedisplay();
        break;
    case 's':
        tsy-=1;
        glutPostRedisplay();
        break;

    case 'a':
        tsx-=1;
        glutPostRedisplay();
        break;

    case 'd':
        tsx+=1;
        glutPostRedisplay();
        break;
    case 'z':
        tsz-=1;
        glutPostRedisplay();
        break;

    case 'c':
        tsz+=1;
        glutPostRedisplay();
        break;
    }
}

// initialization

void initGL() {
    glMatrixMode(GL_PROJECTION);
    //glOrtho(-4, 4, -2, 2, -2, 2);  // simple orthographic projection
    glMatrixMode(GL_MODELVIEW);

}

 void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80,1,2,200);
    glMatrixMode(GL_MODELVIEW);
     glEnable(GL_DEPTH_TEST);
    glClearColor(0.5, 0.5, 0.5, 1);
    }

//Mouse XD:
// Scale, Rotation for screen with keyboard mask SHIFT FOR X, CTRL FOR Y && ALT FOR Z
 void OnMouseClick(int button, int state, int x, int y)
{


  // Rotation with Mouse X axis and SHIFT mask
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && glutGetModifiers() == GLUT_ACTIVE_SHIFT  )
  {
     rotatesX -= 15;
     glutPostRedisplay();
  }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN &&glutGetModifiers() == GLUT_ACTIVE_SHIFT )
  {
     rotatesX += 15;
     glutPostRedisplay();
  }

  // Rotation with Mouse Y axis with CTRL mask
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && glutGetModifiers() == GLUT_ACTIVE_CTRL  )
  {
     rotatesY -= 15;
     glutPostRedisplay();
  }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && glutGetModifiers() == GLUT_ACTIVE_CTRL )
  {
    rotatesY += 15;
     glutPostRedisplay();
  }

  // Rotation with Mouse Z axis with ALT mask
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && glutGetModifiers() == GLUT_ACTIVE_ALT )
  {
     rotatesZ -= 15;
     glutPostRedisplay();
  }
    else  if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && glutGetModifiers() == GLUT_ACTIVE_ALT )
  {
     rotatesZ += 15;
     glutPostRedisplay();
  }

    // Scale with Mouse
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
  {
     sclaesX += 0.04;
     glutPostRedisplay();
  }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )
  {
     sclaesX -= 0.04;
     glutPostRedisplay();
  }

}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(200,20);
    glutCreateWindow("Good Bye Computer Graphics course 2022!");
    glutReshapeFunc(reshape);

    //initGL();
    glutDisplayFunc(display);

    glutMouseFunc(OnMouseClick);
    glutKeyboardFunc(keyPress);
    glutSpecialFunc(specialKeyFunction);
    glutMainLoop();

    return 0;
}
