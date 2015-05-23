#include "render.h"
#include "../inc/glew.h"
#include "../inc/GL.h"
#include "../inc/freeglut.h"

void render::run(float3** colors, int n)
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective( 90, 1, 0.1, 10 );
	glOrtho(-0.5f, 0.5f, -0.5f, 0.5f, 0, 12.0f );

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt( 0.5, -0.5, 1.5, 0.5, -0.5, 0, 0, 1, 0 );

	glViewport(0,0,600,600);

	//n=1;
	float cell = 1.0f/n;
	//render the rectangles here.
	for( int i=0; i<n; i++ ) for( int j=0; j<n; j++ )
	{
		glColor3f( colors[i][j].x, colors[i][j].y, colors[i][j].z );
		
		glBegin(GL_POLYGON);
		glVertex3f(j*cell, -i*cell, 0.0);
		glVertex3f(j*cell+cell,-i*cell, 0.0);
		glVertex3f(j*cell+cell,-i*cell-cell, 0.0);
		glVertex3f(j*cell, -i*cell-cell, 0.0);
		glEnd();
	}
	glPopMatrix();

	glutPostRedisplay();
	glutSwapBuffers();
}

