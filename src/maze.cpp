#include "maze.h"

void maze::init( int _edge )
{
	edge = _edge;
	colors = new float3 *[edge];
	for( int i=0; i<edge; i++ )
		colors[i] = new float3[edge];

	//test
	colors[0][0] = float3(1,0,0);
	colors[0][1] = float3(0,1,0);
	colors[1][0] = float3(0,0,1);
	colors[1][1] = float3(1,1,0);
}