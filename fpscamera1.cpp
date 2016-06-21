

//local_camera_pos = camera_pos

Matrix4 mtx_world_camera;
int mtx_world_camera_initialized=0;

void print(const char *name,Matrix4 &rot)
{
    printf("%s:\n",name);
    printf("\
    \t%+4.2f,%+4.2f,%+4.2f,%+4.2f \n\
    \t%+4.2f,%+4.2f,%+4.2f,%+4.2f \n\
    \t%+4.2f,%+4.2f,%+4.2f,%+4.2f \n\
    \t%+4.2f,%+4.2f,%+4.2f,%+4.2f \n",
    rot[0], rot[1], rot[2], rot[3],
    rot[4], rot[5], rot[6], rot[7],
    rot[8], rot[9], rot[10], rot[11],
    rot[12], rot[13], rot[14], rot[15]);

}


void fpscamera1()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
    glLoadIdentity();				// Reset The View

    float cm_ogl[16];
    Matrix4 rot;

    if(mtx_world_camera_initialized==0)
    {
        mtx_world_camera_initialized=1;
        
        //set the initial position of the camera
        Vector3 initPos(0,1,0);
        Matrix4 tr;
        tr.translate(initPos.x,initPos.y,initPos.z);
        mtx_world_camera *= tr;
    }

    rot.rotateY(yrot);
    yrot=0; //reinit angle so it doesn't continue adding up
    
    Matrix4 tr;
    tr.translate(camera_pos.x,camera_pos.y,camera_pos.z);
    camera_pos.set(0,0,0); //reinit pos so it doesn't continue adding up

    mtx_world_camera *= tr;
    mtx_world_camera *= rot;

    Matrix4 m = mtx_world_camera;
    
    m.invert();
    ToOpenGLMat(m,cm_ogl);
/*
    print("rot", rot);
    print("tr", tr);
    print("world mtx", mtx_world_camera);
*/

    glLoadMatrixf(cm_ogl);



    DrawGrid();
    DrawAxis();

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


    // swap the buffers to display, since double buffering is used.
    glutSwapBuffers();
}
