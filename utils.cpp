

#include "soho/Matrices.h"


void ToOpenGLMat(Matrix4 &cm, float cm_ogl[])
{
cm_ogl[ 0]=cm.m[ 0]; cm_ogl[ 1]=cm.m[ 4]; cm_ogl[ 2]=cm.m[ 8]; cm_ogl[ 3]=cm.m[ 3];
cm_ogl[ 4]=cm.m[ 1]; cm_ogl[ 5]=cm.m[ 5]; cm_ogl[ 6]=cm.m[ 9]; cm_ogl[ 7]=cm.m[ 7];
cm_ogl[ 8]=cm.m[ 2]; cm_ogl[ 9]=cm.m[ 6]; cm_ogl[10]=cm.m[10]; cm_ogl[11]=cm.m[11];
cm_ogl[12]=cm.m[12]; cm_ogl[13]=cm.m[13]; cm_ogl[14]=cm.m[14]; cm_ogl[15]=cm.m[15];

}

void ToSohoMat(float cm_ogl[], Matrix4 &cm)
{
cm.m[ 0]=cm_ogl[ 0]; cm.m[ 1]=cm_ogl[ 4]; cm.m[ 2]=cm_ogl[ 8]; cm.m[ 3]=cm_ogl[ 3];
cm.m[ 4]=cm_ogl[ 1]; cm.m[ 5]=cm_ogl[ 5]; cm.m[ 6]=cm_ogl[ 9]; cm.m[ 7]=cm_ogl[ 7];
cm.m[ 8]=cm_ogl[ 2]; cm.m[ 9]=cm_ogl[ 6]; cm.m[10]=cm_ogl[10]; cm.m[11]=cm_ogl[11];
cm.m[12]=cm_ogl[12]; cm.m[13]=cm_ogl[13]; cm.m[14]=cm_ogl[14]; cm.m[15]=cm_ogl[15];

}
/*
void ToOpenGLMat(Matrix4 &cm, float cm_ogl[])
{
    Matrix3 m3(	cm.m[ 0], cm.m[ 1], cm.m[ 2],
				cm.m[ 3], cm.m[ 4], cm.m[ 5],
				cm.m[ 6], cm.m[ 7], cm.m[ 8]);
	m3.invert();

cm_ogl[ 0]=m3.m[ 0]; cm_ogl[ 1]=m3.m[ 1]; cm_ogl[ 2]=m3.m[ 2]; cm_ogl[ 3]=m3.m[ 3];
cm_ogl[ 4]=m3.m[ 3]; cm_ogl[ 5]=m3.m[ 5]; cm_ogl[ 6]=m3.m[ 8]; cm_ogl[ 7]=m3.m[ 3];
cm_ogl[ 8]=m3.m[ 2]; cm_ogl[ 9]=m3.m[ 6]; cm_ogl[10]=m3.m[ 8]; cm_ogl[11]=m3.m[ 3];
cm_ogl[12]=cm.m[ 0]; cm_ogl[13]=cm.m[ 4]; cm_ogl[14]=cm.m[ 8]; cm_ogl[15]=cm.m[ 3];

}
*/


