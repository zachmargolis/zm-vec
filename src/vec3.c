/*
 *  vec3.c
 *  Created by Zach Margolis on 10/10/10.
 *
 */

#include "vec3.h"

#import <math.h>
#import <stdio.h>

const vec3 vec3Zero = {0.0f, 0.0f, 0.0f};
const vec3 vec3UnitVectorX = {1.0f, 0.0f, 0.0f};
const vec3 vec3UnitVectorY = {0.0f, 1.0f, 0.0f};
const vec3 vec3UnitVectorZ = {0.0f, 0.0f, 1.0f};

vec3 vec3Make(const GLfloat x, const GLfloat y, const GLfloat z)
{
    vec3 retVec = {x, y, z};
    return retVec;
}

int vec3Equal(const vec3 aVec, const vec3 bVec)
{
    return (aVec.x == bVec.x &&
            aVec.y == bVec.y &&
            aVec.z == bVec.z);
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

vec3 vec3Subtract(const vec3 aVec, const vec3 bVec)
{
    return vec3Add(aVec, vec3Scale(-1., bVec));
}

vec3 vec3Cross(const vec3 aVec, const vec3 bVec)
{
    return vec3Make((aVec.y * bVec.z) - (bVec.y * aVec.z),
                    (bVec.x * aVec.z) - (aVec.x * bVec.z),
                    (aVec.x * bVec.y) - (bVec.x * aVec.y));

}

vec3 vec3Mix(const vec3 aVec, const vec3 bVec, const GLfloat blend)
{
    return vec3Add(vec3Scale(blend, aVec),
                   vec3Scale(1. - blend, bVec));
}

char *vec3ToString(const vec3 vec, char *str)
{
    sprintf(str, "<%g, %g, %g>", vec.x, vec.y, vec.z);
    
    return str;
}
