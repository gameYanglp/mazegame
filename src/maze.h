#ifndef MAZE_H
#define MAZE_H
#include "utility.h"

class maze{
public:
	maze(){}
	void init( int _edge );

	//interface
	float3** getColors(){return colors;}
	int getEdge(){return edge;}

	~maze(){
		for( int i=0; i<edge; i++ )
			delete [] colors[i];
		delete [] colors;
	}
		
private:
	float3 **colors;		//需要绘制的矩阵，
	int edge;			//the matrix's dimension edge * edge
};

#endif