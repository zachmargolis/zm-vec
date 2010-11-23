/*
 *  vec4.c
 *  VectorPad
 *
 *  Created by Zach Margolis on 10/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "vec4.h"

#import <math.h>

const vec4 vec4Zero = {0.0f, 0.0f, 0.0f, 0.0f};
const vec4 vec4UnitVectorX = {1.0f, 0.0f, 0.0f, 0.0f};
const vec4 vec4UnitVectorY = {0.0f, 1.0f, 0.0f, 0.0f};
const vec4 vec4UnitVectorZ = {0.0f, 0.0f, 1.0f, 0.0f};
const vec4 vec4UnitVectorW = {0.0f, 0.0f, 0.0f, 1.0f};

vec4 vec4Make(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	vec4 retVec = {x, y, z, w};
	return retVec;
}

vec4 vec4MakeFromVec3(vec3 vec, GLfloat w)
{
    return vec4Make(vec.x, vec.y, vec.z, w);
}


vec3 vec3TruncateVec4(vec4 vec)
{
    return vec3Make(vec.x, vec.y, vec.z);
}

GLfloat vec4Magnitude(vec4 inVec)
{
	return sqrt((inVec.x * inVec.x) +
				(inVec.y * inVec.y) +
				(inVec.z * inVec.z) +
				(inVec.w * inVec.w) );
}

GLfloat vec4Dot(vec4 aVec, vec4 bVec)
{
	return (aVec.x * bVec.x) + 
		   (aVec.y * bVec.y) + 
		   (aVec.z * bVec.z) + 
		   (aVec.w * bVec.w);
}

vec4 vec4Scale(GLfloat scalar, vec4 inVec)
{
	return vec4Make(scalar * inVec.x,
					scalar * inVec.y,
					scalar * inVec.z,
					scalar * inVec.w);
}

vec4 vec4Normalize(vec4 inVec)
{
	return vec4Scale(1.0f/vec4Magnitude(inVec), inVec);
}

vec4 vec4Add(vec4 aVec, vec4 bVec)
{
	return vec4Make(aVec.x + bVec.x,
					aVec.y + bVec.y,
					aVec.z + bVec.z,
					aVec.w + bVec.w);
}

vec4 CATransform3DTimesVec4(CATransform3D mat, vec4 vec)
{
    return vec4Make((vec.x * mat.m11) + (vec.y * mat.m12) + (vec.z * mat.m13) + (vec.w * mat.m14),
                    (vec.x * mat.m21) + (vec.y * mat.m22) + (vec.z * mat.m23) + (vec.w * mat.m24),
                    (vec.x * mat.m31) + (vec.y * mat.m32) + (vec.z * mat.m33) + (vec.w * mat.m34),
                    (vec.x * mat.m41) + (vec.y * mat.m42) + (vec.z * mat.m43) + (vec.w * mat.m44)
                    );
}
