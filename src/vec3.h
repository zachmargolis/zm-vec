/*
 *  vec3.h
 *  Created by Zach Margolis on 10/10/10.
 *
 */

#ifndef VEC3_H_INCLUDED
#define VEC3_H_INCLUDED

// TODO: change importing so that defs.h doesn't have to be included, and we can link to the OpenGL frameworks
#include "defs.h"
//#import <OpenGLES/ES1/gl.h>
//#import <OpenGLES/ES2/gl.h>



typedef struct {
	GLfloat x;
	GLfloat y;
	GLfloat z;
} vec3;

extern const vec3 vec3Zero;
extern const vec3 vec3UnitVectorX;
extern const vec3 vec3UnitVectorY;
extern const vec3 vec3UnitVectorZ;

vec3 vec3Make(const GLfloat x, const GLfloat y, const GLfloat z); 

int vec3Equal(const vec3 aVec, const vec3 bVec);

GLfloat vec3Magnitude(const vec3 inVec);
GLfloat vec3Dot(const vec3 aVec, const vec3 bVec);

vec3 vec3Scale(const GLfloat scalar, const vec3 inVec);
vec3 vec3Normalize(const vec3 inVec);
vec3 vec3Add(const vec3 aVec, const vec3 bVec);
vec3 vec3Subtract(const vec3 aVec, const vec3 bVec);
vec3 vec3Cross(const vec3 aVec, const vec3 bVec);
vec3 vec3Mix(const vec3 aVec, const vec3 bVec, const GLfloat blend);

char *vec3ToString(const vec3 vec, char *str);



#endif // VEC3_H_INCLUDED
