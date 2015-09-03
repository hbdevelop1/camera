

#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <unistd.h>     // needed to sleep

#include "soho/Matrices.h"
#include "utils.h"
#include "objects.h"

extern float	rtri;
extern float	rquad;

static Vector3 camposworld;
Vector3 camposworld_0;
extern float camanglelocal_Y;
extern Vector3 camdislocal;

void update7(void)   // Create The update Function
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
  glLoadIdentity();					// Reset The Current Modelview Matrix

  /*
  //get current local orientation
  //get last world position
  //new worldposition = last world position + new world displacment
  wcampos = new worldposition;
  glTranslatef(wcampos);
  glRotatef();
  invert;

  glLoadMatrix();
  */
  
  Matrix4 camrotworld;
  camrotworld.rotateY(180+camanglelocal_Y);

  Vector3 camdisworld = camrotworld*camdislocal;
  camdislocal=Vector3(0,0,0);
  camposworld += camdisworld;

  Matrix4 camrotlocal;
  camrotlocal.rotateY(camanglelocal_Y);
  Matrix4 cammtxworld = camrotlocal;
  cammtxworld[3] = camposworld.x;
  cammtxworld[7] = camposworld.y;
  cammtxworld[11] = camposworld.z;

  cammtxworld.invert();
  float mtx[16];
  ToOpenGLMat(cammtxworld, mtx);
  glLoadMatrixf(mtx);
  
  DrawGrid();

  glPushMatrix();
  glTranslatef(-1.5f, 0.0f, -26.0f);
  glPushMatrix();
  glRotatef(rtri, 0.0f, 1.0f, 0.0f);

  draw_pyramid();
  glPopMatrix();


  glRotatef(rquad * 10, 0.0f, 1.0f, 0.0f);
  glTranslatef(-1.5f, 2.0f, 3.0f);
  draw_cube();

  glPopMatrix();

  glPushMatrix();
  glTranslatef(1.5f, 0.0f, 26.0f);
  glRotatef(rquad, 1.0f, 0.0f, 0.0f);
  glColor3f(0.5f, 0.5f, 1.0f);
  draw_cube();
  glPopMatrix();

  DrawAxis();

  rtri += 1.2f;
  rquad -= 1.15f;


  glutSwapBuffers();
  // Swap The Buffers To Not Be Left With A Clear Screen
}
