#include <GL/gl.h>
#include <GL/glut.h>
#include "vertices.h"
#include <windows.h>

using namespace std;

int rotateX = -60, rotateY = 30, rotateZ = 0;  // rotation angle
float sclaeX = 0.25, sclaeY = 0.25 , sclaeZ=0.25; // Set up scale
int tx = 0, ty = 0, tz = 0;  // Translate
void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //cube
  /*  glLoadIdentity();             // Set up modelview transform, first shape.
    glTranslatef(-2, 0, 0);      // Move cube to left half of window.

    glRotatef(rotateZ,0,0,1);     // Apply rotations.
    glRotatef(rotateY,0,1,0);
    glRotatef(rotateX,1,0,0);

    glVertexPointer( 3, GL_FLOAT, 0, cubeCoords );  // Set data type and location, first shape.
    glColorPointer( 3, GL_FLOAT, 0, cubeFaceColors );

    glEnableClientState( GL_VERTEX_ARRAY ); // permission for using data e.g. giving access
					    // to set a connection like a clinet-server
					    // enable use of array
    glEnableClientState( GL_COLOR_ARRAY );

    glDrawArrays( GL_QUADS, 0, 24 ); // Draw the first shape!
   */

    // ----------------------------------------------------------------------------------------------
    // Quote of the day a great man once said:
    // "You don't know until you know" Zico.
    //-----------------------------------------------------------------------------------------------
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
    glEnableClientState( GL_VERTEX_ARRAY ); // permission for using data e.g. giving access
					    // to set a connection like a clinet-server
					    // enable use of array
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
void specialKeyFunction(int key, int x, int y) {
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
    if ( key == GLUT_KEY_HOME )
       rotateX = rotateY = rotateZ = 0;
    if ( key == GLUT_KEY_F1)
       sclaeX += 0.01;
    if ( key == GLUT_KEY_F2)
       sclaeX -= 0.01;

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

    glutPostRedisplay();
}

// Mouse -> // Abdelbasset Deal

// initialization

void initGL() {
    glMatrixMode(GL_PROJECTION);
    glOrtho(-4, 4, -2, 2, -2, 2);  // simple orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5, 0.5, 0.5, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(20,20);
    glutCreateWindow("USE ARROW KEYS TO ROTATE; HOME KEY RESETS");
    initGL();
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeyFunction);
    glutMainLoop();
    return 0;
}
