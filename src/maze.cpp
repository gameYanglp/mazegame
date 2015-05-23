#include "maze.h"
#include <stdlib.h>
#include <stdio.h>
void maze::init( int _edge )
{
	edge = _edge;
	colors = new float3 *[edge];
	for( int i=0; i<edge; i++ )
	{
		colors[i] = new float3[edge];
		for(int j=0;j<edge;j++)
		{
			float x,y,z;
			x=rand()%10;
			y=rand()%10;
			z=rand()%10;
			double a,b,c;
			a=x/10;
			b=y/10;
			c=z/10;
			colors[i][j]=float3(a,b,c);
		}
	}
	////test
	//colors[0][0] = float3(1,0,0);
	//colors[0][1] = float3(0,1,0);
	//colors[1][0] = float3(0,0,1);
	//colors[1][1] = float3(1,1,0);
}
void maze::changecolor(int i,int j)
{
	float3** colors;
	float a,b,c;
	colors=maze::getColors();
	a=colors[i][j].x;
	b=colors[i][j].y;
	c=colors[i][j].z;
	colors[i][j]=float3(1.0-a,1.0-b,1.0-c);
}