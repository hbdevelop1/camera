//
// This code was created by Jeff Molofee '99 (ported to Linux/GLUT by Richard Campbell '99)
//
// If you've found this code useful, please let me know.
//
// Visit me at www.demonews.com/hosted/nehe 
// (email Richard Campbell at ulmont@bellsouth.net)
//
#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <unistd.h>     // needed to sleep
//#include <iostream>     // needed to sleep
#include <stdio.h>     // needed to sleep
#include <math.h>     // needed to sleep
#include "objects.h"

#include "soho/Matrices.h"
#include "utils.h"



/* ASCII code for the escape key. */
#define ESCAPE 27

/* The number of our GLUT window */
int window; 
const GLint Width=640;
const GLint Height=480;
GLint viewport[4]={0, 0, 640, 480};
/* rotation angle for the triangle. */
float rtri = 0.0f;

/* rotation angle for the quadrilateral. */
float rquad = 0.0f;
GLfloat yrot=0;            // y rotation



void keyPressed(unsigned char key, int x, int y) ;
void specialKeyPressed(int key, int x, int y) ;




/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
  glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);			        // The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);		        // Enables Depth Testing
  glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();				// Reset The Projection Matrix

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

  glMatrixMode(GL_MODELVIEW);
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeGLScene(int Width, int Height)
{
  if (Height==0)				// Prevent A Divide By Zero If The Window Is Too Small
    Height=1;

  glViewport(viewport[0],viewport[1],viewport[2],viewport[3]);		// Reset The Current Viewport And Perspective Transformation

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
  glMatrixMode(GL_MODELVIEW);
}


GLfloat g_lookat_x=0;

/* The main drawing function. */
void DrawGLScene()
{
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
  glLoadIdentity();				// Reset The View

float cm_ogl[16];
Matrix4 cm;


cm.identity();
cm.rotateY(90);
cm.invert();
ToOpenGLMat(cm,cm_ogl);


cm.identity();
cm.rotateY(180);
cm.invert();
ToOpenGLMat(cm,cm_ogl);



glLoadMatrixf(cm_ogl);



glPushMatrix();

  glTranslatef(-1.5f,0.0f,-12.0f);		// Move Left 1.5 Units And Into The Screen 6.0
  glRotatef(rtri,0.0f,1.0f,0.0f);		// Rotate The Pyramid On The Y axis 
	
draw_pyramid();

glPopMatrix();


glPushMatrix();

  glTranslatef(0.f,0.f,12.0f);		// Move Left 1.5 Units And Into The Screen 6.0
  glRotatef(rtri,0.0f,1.0f,0.0f);		// Rotate The Pyramid On The Y axis 
	
blue_draw_pyramid();

glPopMatrix();


glPushMatrix();

  glTranslatef(12.f,0.f,0.0f);		// Move Left 1.5 Units And Into The Screen 6.0
  glRotatef(rtri,0.0f,1.0f,0.0f);		// Rotate The Pyramid On The Y axis 
	
red_draw_pyramid();

glPopMatrix();


glPushMatrix();

  glTranslatef(-12.f,0.f,0.0f);		// Move Left 1.5 Units And Into The Screen 6.0
  glRotatef(rtri,0.0f,1.0f,0.0f);		// Rotate The Pyramid On The Y axis 
	
green_draw_pyramid();

glPopMatrix();

glPushMatrix();

  glTranslatef(1.5f,0.0f,-12.0f);		// Move Right 3 Units, and back into the screen 7
  glRotatef(rquad,1.0f,1.0f,1.0f);		// Rotate The Cube On X, Y, and Z

  draw_cube();
glPopMatrix();

  rtri+=1.0f;					// Increase The Rotation Variable For The Pyramid
  rquad-=1.0f;					// Decrease The Rotation Variable For The Cube

GLdouble view[16];
glGetDoublev(GL_MODELVIEW_MATRIX, view);

{
printf("view:\n");
printf("%+.2f,%+.2f,%+.2f,%+.2f \n\
%+.2f,%+.2f,%+.2f,%+.2f \n\
%+.2f,%+.2f,%+.2f,%+.2f \n\
%+.2f,%+.2f,%+.2f,%+.2f \n",
view[0], view[4], view[8], view[3],
view[1], view[5], view[9], view[7],
view[8], view[6], view[10], view[11],
view[12], view[13], view[14], view[15]);

}

  // swap the buffers to display, since double buffering is used.
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  /* Initialize GLUT state - glut will take any command line arguments that pertain to it or 
     X Windows - look at its documentation at http://reality.sgi.com/mjk/spec3/spec3.html */  
  glutInit(&argc, argv);  

  /* Select type of Display mode:   
     Double buffer 
     RGBA color
     Alpha components supported 
     Depth buffered for automatic clipping */  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  

  /* get a 640 x 480 window */
  glutInitWindowSize(640, 480);  

  /* the window starts at the upper left corner of the screen */
  glutInitWindowPosition(0, 0);  

  /* Open a window */  
  window = glutCreateWindow("Jeff Molofee's GL Code Tutorial ... NeHe '99");  

  /* Register the function to do all our OpenGL drawing. */
  glutDisplayFunc(&DrawGLScene);  

  /* Go fullscreen.  This is as soon as possible. */
  //glutFullScreen();

  /* Even if there are no events, redraw our gl scene. */
  glutIdleFunc(&DrawGLScene);

  /* Register the function called when our window is resized. */
  glutReshapeFunc(&ReSizeGLScene);

  /* Register the function called when the keyboard is pressed. */
  glutKeyboardFunc(&keyPressed);

    /* Register the function called when special keys (arrows, page down, etc) are pressed. */
    glutSpecialFunc(&specialKeyPressed);

  /* Initialize our window. */
  InitGL(640, 480);
  
  /* Start Event Processing Engine */  
  glutMainLoop();  

  return 1;
}



/* The function called whenever a normal key is pressed. */
void specialKeyPressed(int key, int x, int y) 
{
    /* avoid thrashing this procedure */
    usleep(100);

    switch (key) {    
    case GLUT_KEY_PAGE_UP: // tilt up
	break;
    
    case GLUT_KEY_PAGE_DOWN: // tilt down
	break;

    case GLUT_KEY_UP: // walk forward (bob head)
	break;

    case GLUT_KEY_DOWN: // walk back (bob head)
	break;

    case GLUT_KEY_LEFT: // look left
	yrot += 1.5f;
	++g_lookat_x;
	break;
    
    case GLUT_KEY_RIGHT: // look right
	yrot -= 1.5f;
	--g_lookat_x;
	break;

    default:
	printf ("Special key %d pressed. No action there yet.\n", key);
	break;
    }	
}


/* The function called whenever a key is pressed. */
void keyPressed(unsigned char key, int x, int y) 
{
    /* avoid thrashing this call */
    usleep(100);

    /* If escape is pressed, kill everything. */
    if (key == ESCAPE) 
    { 
      /* shut down our window */
      glutDestroyWindow(window); 
      
      /* exit the program...normal termination. */
      exit(0);                   
    }
}

