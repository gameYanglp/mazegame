#include <stdio.h>
#include <Windows.h>
#include "render.h"
#include "maze.h"
#include "../inc/glew.h"
#include "../inc/freeglut.h"

maze g_maze;
render g_render;

void display()
{
	g_render.run(g_maze.getColors(), g_maze.getEdge());
}

void keyboard_func( unsigned char key, int x, int y )
{
	switch ( key )
	{
	case 27:
		exit(0);
		break;

	}
}

void mouse_click (int button, int state, int x, int y)
{
   if( button==GLUT_LEFT_BUTTON && state == GLUT_DOWN )
   {
	   POINT pt;
	   GetCursorPos(&pt);
	   //x=pt.y;
	  // y=pt.x;
	  // printf("%d,%d\n",x,y);
	   g_maze.changecolor(y/300,x/300);
   }
}

void mouse_move ( int x, int y)
{

}

void mousewheel( int button, int dir, int x, int y )
{
	
}

void initopengl(int argc, char **argv)
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowPosition( 0, 0 );
	glutInitWindowSize( 600, 600 );
	glutCreateWindow("SpraySimulation");
	GLenum err = glewInit();
	if( err != GLEW_OK )
		printf("\nGLEW is not available!!!\n\n");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard_func);
	glutMouseFunc(mouse_click);
	glutMotionFunc(mouse_move);
	glutMouseWheelFunc(mousewheel );
}

int main( int argc, char **argv )
{
	initopengl(argc, argv);
	
	g_maze.init(5);

	glutMainLoop();
	
	return 0;
}