#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <unistd.h>     // needed to sleep

#include "objects.h"
#include "utils.h"
#include <stdio.h>

void draw_pyramid()
{

  // draw a pyramid (in smooth coloring mode)
  glBegin(GL_POLYGON);				// start drawing a pyramid

  // front face of pyramid
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Red
  glVertex3f(0.0f, 1.0f, 0.0f);		        // Top of triangle (front)
  glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Green
  glVertex3f(-1.0f,-1.0f, 1.0f);		// left of triangle (front)
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f(1.0f,-1.0f, 1.0f);		        // right of traingle (front)	

  // right face of pyramid
  glColor3f(1.0f,0.0f,0.0f);			// Red
  glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Right)
  glColor3f(0.0f,0.0f,1.0f);			// Blue
  glVertex3f( 1.0f,-1.0f, 1.0f);		// Left Of Triangle (Right)
  glColor3f(0.0f,1.0f,0.0f);			// Green
  glVertex3f( 1.0f,-1.0f, -1.0f);		// Right Of Triangle (Right)

  // back face of pyramid
  glColor3f(1.0f,0.0f,0.0f);			// Red
  glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Back)
  glColor3f(0.0f,1.0f,0.0f);			// Green
  glVertex3f( 1.0f,-1.0f, -1.0f);		// Left Of Triangle (Back)
  glColor3f(0.0f,0.0f,1.0f);			// Blue
  glVertex3f(-1.0f,-1.0f, -1.0f);		// Right Of Triangle (Back)

  // left face of pyramid.
  glColor3f(1.0f,0.0f,0.0f);			// Red
  glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Left)
  glColor3f(0.0f,0.0f,1.0f);			// Blue
  glVertex3f(-1.0f,-1.0f,-1.0f);		// Left Of Triangle (Left)
  glColor3f(0.0f,1.0f,0.0f);			// Green
  glVertex3f(-1.0f,-1.0f, 1.0f);		// Right Of Triangle (Left)

  glEnd();					// Done Drawing The Pyramid
}

void small_draw_pyramid()
{

  // draw a pyramid (in smooth coloring mode)
GLfloat extent=.1f;
  glBegin(GL_POLYGON);				// start drawing a pyramid
  // front face of pyramid
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Red
  glVertex3f(0.0f, extent, 0.0f);		        // Top of triangle (front)
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Red
  glVertex3f(-extent,-extent, extent);		// left of triangle (front)
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Red
  glVertex3f(extent,-extent, extent);		        // right of traingle (front)	

  // right face of pyramid
  glColor3f(0.0f,0.0f,1.0f);			// Blue
  glVertex3f( 0.0f, extent, 0.0f);		// Top Of Triangle (Right)
  glColor3f(0.0f,0.0f,1.0f);			// Blue
  glVertex3f( extent,-extent, extent);		// Left Of Triangle (Right)
  glColor3f(0.0f,0.0f,1.0f);			// Blue
  glVertex3f( extent,-extent, -extent);		// Right Of Triangle (Right)

  // back face of pyramid
  glColor3f(1.0f,0.0f,0.0f);			// Red
  glVertex3f( 0.0f, extent, 0.0f);		// Top Of Triangle (Back)
  glColor3f(0.0f,1.0f,0.0f);			// Green
  glVertex3f( extent,-extent, -extent);		// Left Of Triangle (Back)
  glColor3f(0.0f,0.0f,1.0f);			// Blue
  glVertex3f(-extent,-extent, -extent);		// Right Of Triangle (Back)

  // left face of pyramid.
  glColor3f(1.0f,0.0f,0.0f);			// Red
  glVertex3f( 0.0f, extent, 0.0f);		// Top Of Triangle (Left)
  glColor3f(0.0f,0.0f,1.0f);			// Blue
  glVertex3f(-extent,-extent,-extent);		// Left Of Triangle (Left)
  glColor3f(0.0f,1.0f,0.0f);			// Green
  glVertex3f(-extent,-extent, extent);		// Right Of Triangle (Left)

  glEnd();					// Done Drawing The Pyramid
}


void draw_cube()
{
  // draw a cube (6 quadrilaterals)
  glBegin(GL_QUADS);				// start drawing the cube.
  
  // top of cube
  glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Blue
  glVertex3f( 1.0f, 1.0f,-1.0f);		// Top Right Of The Quad (Top)
  glVertex3f(-1.0f, 1.0f,-1.0f);		// Top Left Of The Quad (Top)
  glVertex3f(-1.0f, 1.0f, 1.0f);		// Bottom Left Of The Quad (Top)
  glVertex3f( 1.0f, 1.0f, 1.0f);		// Bottom Right Of The Quad (Top)

  // bottom of cube
  glColor3f(1.0f,0.5f,0.0f);			// Set The Color To Orange
  glVertex3f( 1.0f,-1.0f, 1.0f);		// Top Right Of The Quad (Bottom)
  glVertex3f(-1.0f,-1.0f, 1.0f);		// Top Left Of The Quad (Bottom)
  glVertex3f(-1.0f,-1.0f,-1.0f);		// Bottom Left Of The Quad (Bottom)
  glVertex3f( 1.0f,-1.0f,-1.0f);		// Bottom Right Of The Quad (Bottom)

  // front of cube
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Red
  glVertex3f( 1.0f, 1.0f, 1.0f);		// Top Right Of The Quad (Front)
  glVertex3f(-1.0f, 1.0f, 1.0f);		// Top Left Of The Quad (Front)
  glVertex3f(-1.0f,-1.0f, 1.0f);		// Bottom Left Of The Quad (Front)
  glVertex3f( 1.0f,-1.0f, 1.0f);		// Bottom Right Of The Quad (Front)

  // back of cube.
  glColor3f(1.0f,1.0f,0.0f);			// Set The Color To Yellow
  glVertex3f( 1.0f,-1.0f,-1.0f);		// Top Right Of The Quad (Back)
  glVertex3f(-1.0f,-1.0f,-1.0f);		// Top Left Of The Quad (Back)
  glVertex3f(-1.0f, 1.0f,-1.0f);		// Bottom Left Of The Quad (Back)
  glVertex3f( 1.0f, 1.0f,-1.0f);		// Bottom Right Of The Quad (Back)

  // left of cube
  glColor3f(0.0f,0.0f,1.0f);			// Blue
  glVertex3f(-1.0f, 1.0f, 1.0f);		// Top Right Of The Quad (Left)
  glVertex3f(-1.0f, 1.0f,-1.0f);		// Top Left Of The Quad (Left)
  glVertex3f(-1.0f,-1.0f,-1.0f);		// Bottom Left Of The Quad (Left)
  glVertex3f(-1.0f,-1.0f, 1.0f);		// Bottom Right Of The Quad (Left)

  // Right of cube
  glColor3f(1.0f,0.0f,1.0f);			// Set The Color To Violet
  glVertex3f( 1.0f, 1.0f,-1.0f);	        // Top Right Of The Quad (Right)
  glVertex3f( 1.0f, 1.0f, 1.0f);		// Top Left Of The Quad (Right)
  glVertex3f( 1.0f,-1.0f, 1.0f);		// Bottom Left Of The Quad (Right)
  glVertex3f( 1.0f,-1.0f,-1.0f);		// Bottom Right Of The Quad (Right)
  glEnd();					// Done Drawing The Cube
}

void blue_draw_pyramid()
{

  // draw a pyramid (in smooth coloring mode)
  glBegin(GL_POLYGON);				// start drawing a pyramid

  // front face of pyramid
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f(0.0f, 1.0f, 0.0f);		        // Top of triangle (front)
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f(-1.0f,-1.0f, 1.0f);		// left of triangle (front)
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f(1.0f,-1.0f, 1.0f);		        // right of traingle (front)	

  // right face of pyramid
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Right)
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f( 1.0f,-1.0f, 1.0f);		// Left Of Triangle (Right)
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f( 1.0f,-1.0f, -1.0f);		// Right Of Triangle (Right)

  // back face of pyramid
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Back)
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f( 1.0f,-1.0f, -1.0f);		// Left Of Triangle (Back)
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f(-1.0f,-1.0f, -1.0f);		// Right Of Triangle (Back)

  // left face of pyramid.
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Left)
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f(-1.0f,-1.0f,-1.0f);		// Left Of Triangle (Left)
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f(-1.0f,-1.0f, 1.0f);		// Right Of Triangle (Left)

  glEnd();					// Done Drawing The Pyramid
}

void red_draw_pyramid()
{

  // draw a pyramid (in smooth coloring mode)
  glBegin(GL_POLYGON);				// start drawing a pyramid

  // front face of pyramid
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f(0.0f, 1.0f, 0.0f);		        // Top of triangle (front)
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Blue
  glVertex3f(-1.0f,-1.0f, 1.0f);		// left of triangle (front)
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Blue
  glVertex3f(1.0f,-1.0f, 1.0f);		        // right of traingle (front)	

  // right face of pyramid
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Blue
  glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Right)
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Blue
  glVertex3f( 1.0f,-1.0f, 1.0f);		// Left Of Triangle (Right)
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Blue
  glVertex3f( 1.0f,-1.0f, -1.0f);		// Right Of Triangle (Right)

  // back face of pyramid
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Blue
  glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Back)
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Blue
  glVertex3f( 1.0f,-1.0f, -1.0f);		// Left Of Triangle (Back)
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Blue
  glVertex3f(-1.0f,-1.0f, -1.0f);		// Right Of Triangle (Back)

  // left face of pyramid.
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Blue
  glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Left)
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Blue
  glVertex3f(-1.0f,-1.0f,-1.0f);		// Left Of Triangle (Left)
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Blue
  glVertex3f(-1.0f,-1.0f, 1.0f);		// Right Of Triangle (Left)

  glEnd();					// Done Drawing The Pyramid
}

void green_draw_pyramid()
{

  // draw a pyramid (in smooth coloring mode)
  glBegin(GL_POLYGON);				// start drawing a pyramid

  // front face of pyramid
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f(0.0f, 1.0f, 0.0f);		        // Top of triangle (front)
  glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Blue
  glVertex3f(-1.0f,-1.0f, 1.0f);		// left of triangle (front)
  glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Blue
  glVertex3f(1.0f,-1.0f, 1.0f);		        // right of traingle (front)	

  // right face of pyramid
  glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Blue
  glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Right)
  glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Blue
  glVertex3f( 1.0f,-1.0f, 1.0f);		// Left Of Triangle (Right)
  glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Blue
  glVertex3f( 1.0f,-1.0f, -1.0f);		// Right Of Triangle (Right)

  // back face of pyramid
  glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Blue
  glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Back)
  glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Blue
  glVertex3f( 1.0f,-1.0f, -1.0f);		// Left Of Triangle (Back)
  glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Blue
  glVertex3f(-1.0f,-1.0f, -1.0f);		// Right Of Triangle (Back)

  // left face of pyramid.
  glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Blue
  glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Left)
  glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Blue
  glVertex3f(-1.0f,-1.0f,-1.0f);		// Left Of Triangle (Left)
  glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Blue
  glVertex3f(-1.0f,-1.0f, 1.0f);		// Right Of Triangle (Left)

  glEnd();					// Done Drawing The Pyramid
}


void DrawGrid()
{
	glPushMatrix();
	//	Set up some nice attributes for drawing the grid.
	glPushAttrib(GL_LINE_BIT | GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_LIGHTING);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glLineWidth(1.5f);

	//	Create the grid.

    glBegin(GL_LINES);
	
	for (int i = -10; i <= 10; i++)
    {
		glColor4f(0.2f, 0.2f, 0.2f, 0.8f);
        glVertex3f((float)i, 0, -10);
        glVertex3f((float)i, 0, 10);
        glVertex3f(-10, 0, (float)i);
        glVertex3f(10, 0, (float)i);
	}
	
	glEnd();

	glPopAttrib();

glPopMatrix();
}

void DrawAxis()
{
	glPushMatrix();
	//	Set up some nice attributes for drawing the grid.
	glPushAttrib(GL_LINE_BIT | GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT);
	glEnable(GL_LINE_SMOOTH);
//	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_LIGHTING);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glLineWidth(1.5f);

	//	Create the axies.
	glBegin(GL_LINES);

		glColor4f(1, 0, 0, 1);//red
		glVertex3f(0, 0, 0);
		glVertex3f(3, 0, 0);
		glColor4f(0, 1, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 3, 0);
		glColor4f(0, 0, 1, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 3);
	glEnd();

	glPopAttrib();

glPopMatrix();
}


Object::Object(void(*_draw)(), float _angle, Vector3 _displacement) :drawfunction(_draw), angle(_angle), displacement(_displacement)
{
}

void Object::draw()
{
  glPushMatrix();

  GLfloat oglm[16];
  ToOpenGLMat(m, oglm);
  glLoadMatrixf(oglm);

{
printf("m:\n");
printf("%+.2f,%+.2f,%+.2f,%+.2f \n\
%+.2f,%+.2f,%+.2f,%+.2f \n\
%+.2f,%+.2f,%+.2f,%+.2f \n\
%+.2f,%+.2f,%+.2f,%+.2f \n",
m.m[0], m.m[1], m.m[2], m.m[3],
m.m[4], m.m[5], m.m[6], m.m[7],
m.m[8], m.m[9], m.m[10], m.m[11],
m.m[12], m.m[13], m.m[14], m.m[15]);

}

  drawfunction();

  for (list<Object*>::iterator it = children.begin(); it != children.end(); ++it)
  {
    (*it)->draw();
  }

  glPopMatrix();
}

void Object::update()
{
  m.identity();
  m.rotateY(angle);
{
printf("fter rotation:\n");
printf("%+.2f,%+.2f,%+.2f,%+.2f \n\
%+.2f,%+.2f,%+.2f,%+.2f \n\
%+.2f,%+.2f,%+.2f,%+.2f \n\
%+.2f,%+.2f,%+.2f,%+.2f \n",
m.m[0], m.m[1], m.m[2], m.m[3],
m.m[4], m.m[5], m.m[6], m.m[7],
m.m[8], m.m[9], m.m[10], m.m[11],
m.m[12], m.m[13], m.m[14], m.m[15]);

}
  m.translate(displacement);
{
printf("after translation:\n");
printf("%+.2f,%+.2f,%+.2f,%+.2f \n\
%+.2f,%+.2f,%+.2f,%+.2f \n\
%+.2f,%+.2f,%+.2f,%+.2f \n\
%+.2f,%+.2f,%+.2f,%+.2f \n",
m.m[0], m.m[1], m.m[2], m.m[3],
m.m[4], m.m[5], m.m[6], m.m[7],
m.m[8], m.m[9], m.m[10], m.m[11],
m.m[12], m.m[13], m.m[14], m.m[15]);

}
}

void Pyramid::update()
{
	angle += 1.f;
	Object::update();
}


void Cube::update()
{
	angle += 1.5f;
	Object::update();
}

