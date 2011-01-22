/*
 *  vec2.h
 *  Created by Zach Margolis on 01/22/11.
 *
 */

#ifndef VEC2_H_INCLUDED
#define VEC2_H_INCLUDED

// TODO: change importing so that defs.h doesn't have to be included, and we can link to the OpenGL frameworks
#include "defs.h"
//#import <OpenGLES/ES1/gl.h>
//#import <OpenGLES/ES2/gl.h>



typedef struct {
	GLfloat x;
	GLfloat y;
} vec2;

extern const vec2 vec2Zero;
extern const vec2 vec2UnitVectorX;
extern const vec2 vec2UnitVectorY;

vec2 vec2Make(const GLfloat x, const GLfloat y); 

int vec2Equal(const vec2 aVec, const vec2 bVec);

GLfloat vec2Magnitude(const vec2 inVec);
GLfloat vec2Dot(const vec2 aVec, const vec2 bVec);

vec2 vec2Scale(const GLfloat scalar, const vec2 inVec);
vec2 vec2Normalize(const vec2 inVec);
vec2 vec2Add(const vec2 aVec, const vec2 bVec);
vec2 vec2Subtract(const vec2 aVec, const vec2 bVec);
vec2 vec2Mix(const vec2 aVec, const vec2 bVec, const GLfloat blend);

char *vec2ToString(const vec2 vec, char *str);



#endif // VEC2_H_INCLUDED
