/*
 *  vec3.h
 *  VectorPad
 *
 *  Created by Zach Margolis on 10/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef VEC3_H_INCLUDED
#define VEC3_H_INCLUDED

#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES2/gl.h>

typedef struct {
	GLfloat x;
	GLfloat y;
	GLfloat z;
} vec3;

extern const vec3 vec3Zero;
extern const vec3 vec3UnitVectorX;
extern const vec3 vec3UnitVectorY;
extern const vec3 vec3UnitVectorZ;

vec3 vec3Make(GLfloat x, GLfloat y, GLfloat z); 

GLfloat vec3Magnitude(const vec3 inVec);
GLfloat vec3Dot(const vec3 aVec, const vec3 bVec);

vec3 vec3Scale(const GLfloat scalar, const vec3 inVec);
vec3 vec3Normalize(const vec3 inVec);
vec3 vec3Add(const vec3 aVec, const vec3 bVec);
vec3 vec3Cross(const vec3 aVec, const vec3 bVec);

#define vec3Subtract(aVec, bVec) vec3Add(aVec, vec3Scale(-1., bVec))

#endif // VEC3_H_INCLUDED