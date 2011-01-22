/*
 *  vec2.h
 *  Created by Zach Margolis on 01/22/11.
 *
 */

#include "vec2.h"
#include <math.h>
#include <stdio.h>

const vec2 vec2Zero = {0.0f, 0.0f};
const vec2 vec2UnitVectorX = {1.0f, 0.0f};
const vec2 vec2UnitVectorY = {0.0f, 1.0f};

vec2 vec2Make(const GLfloat x, const GLfloat y)
{
    vec2 retVec = {x, y};
    return retVec;
}

int vec2Equal(const vec2 aVec, const vec2 bVec)
{
    return (aVec.x == bVec.x &&
            aVec.y == bVec.y);
}

GLfloat vec2Magnitude(const vec2 inVec)
{
    return sqrt((inVec.x * inVec.x) +
                (inVec.y * inVec.y) );
}

GLfloat vec2Dot(const vec2 aVec, const vec2 bVec)
{
    return (aVec.x * bVec.x) + 
           (aVec.y * bVec.y);
}

vec2 vec2Scale(const GLfloat scalar, const vec2 inVec)
{
    return vec2Make(scalar * inVec.x,
                    scalar * inVec.y);
}

vec2 vec2Normalize(const vec2 inVec)
{
    return vec2Scale(1.0f/vec2Magnitude(inVec), inVec);
}

vec2 vec2Add(const vec2 aVec, const vec2 bVec)
{
    return vec2Make(aVec.x + bVec.x,
                    aVec.y + bVec.y);
}

vec2 vec2Subtract(const vec2 aVec, const vec2 bVec)
{
    return vec2Add(aVec, vec2Scale(-1., bVec));
}

vec2 vec2Mix(const vec2 aVec, const vec2 bVec, const GLfloat blend)
{
    return vec2Add(vec2Scale(blend, aVec),
                   vec2Scale(1. - blend, bVec));
}

char *vec2ToString(const vec2 vec, char *str)
{
    sprintf(str, "<%g, %g>", vec.x, vec.y);
    
    return str;
}