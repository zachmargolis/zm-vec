/*
 *  vec3.c
 *  VectorPad
 *
 *  Created by Zach Margolis on 10/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "vec3.h"

#import <math.h>

const vec3 vec3Zero = {0.0f, 0.0f, 0.0f};
const vec3 vec3UnitVectorX = {1.0f, 0.0f, 0.0f};
const vec3 vec3UnitVectorY = {0.0f, 1.0f, 0.0f};
const vec3 vec3UnitVectorZ = {0.0f, 0.0f, 1.0f};

vec3 vec3Make(GLfloat x, GLfloat y, GLfloat z)
{
	vec3 retVec = {x, y, z};
	return retVec;
}

vec3 vec3Set(vec3 vec, const GLfloat x, const GLfloat y, const GLfloat z)
{
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return vec;
}

GLfloat vec3Magnitude(const vec3 inVec)
{
	return sqrt((inVec.x * inVec.x) +
				(inVec.y * inVec.y) +
				(inVec.z * inVec.z) );
}

GLfloat vec3Dot(const vec3 aVec, const vec3 bVec)
{
	return (aVec.x * bVec.x) + 
		   (aVec.y * bVec.y) + 
		   (aVec.z * bVec.z);
}

vec3 vec3Scale(const GLfloat scalar, const vec3 inVec)
{
	return vec3Make(scalar * inVec.x,
				    scalar * inVec.y,
				    scalar * inVec.z);
}

vec3 vec3Normalize(const vec3 inVec)
{
	return vec3Scale(1.0f/vec3Magnitude(inVec), inVec);
}

vec3 vec3Add(const vec3 aVec, const vec3 bVec)
{
	return vec3Make(aVec.x + bVec.x,
				    aVec.y + bVec.y,
				    aVec.z + bVec.z);
}

vec3 vec3Cross(const vec3 aVec, const vec3 bVec)
{
    return vec3Make((aVec.y * bVec.z) - (bVec.y * aVec.z),
                    (bVec.x * aVec.z) - (aVec.x * bVec.z),
                    (aVec.x * bVec.y) - (bVec.x * aVec.y));

}
