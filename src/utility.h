#ifndef UTILITY_H
#define UTILITY_H

struct float3 
{
	float x,y,z;
	float3( float _x, float _y, float _z )
	{
		x=_x, y=_y, z=_z;
	}
	float3()
	{
		x=0.0f, y=0.0f, z=0.0f;
	}
};

#endif