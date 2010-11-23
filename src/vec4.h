/*
 *  vec4.h
 *  Created by Zach Margolis on 10/10/10.
 *
 */

#ifndef VEC4_H_INCLUDED
#define VEC4_H_INCLUDED


#import "vec3.h"

// TODO: change importing so that defs.h doesn't have to be included, and we can link to the OpenGL frameworks
#include "defs.h"
//#import <OpenGLES/ES1/gl.h>
//#import <OpenGLES/ES2/gl.h>

//#import <QuartzCore/CATransform3D.h>

typedef struct {
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat w;
} vec4;

extern const vec4 vec4Zero;
extern const vec4 vec4UnitVectorX;
extern const vec4 vec4UnitVectorY;
extern const vec4 vec4UnitVectorZ;
extern const vec4 vec4UnitVectorW;

vec4 vec4Make(GLfloat x, GLfloat y, GLfloat z, GLfloat w); 
vec4 vec4MakeFromVec3(vec3 vec, GLfloat w);
vec3 vec3TruncateVec4(vec4 vec); // In this file because of some nasty forward declaration stuff

GLfloat vec4Magnitude(vec4 inVec);
GLfloat vec4Dot(vec4 aVec, vec4 bVec);

vec4 vec4Scale(GLfloat scalar, vec4 inVec);
vec4 vec4Normalize(vec4 inVec);
vec4 vec4Add(vec4 aVec, vec4 bVec);

vec4 CATransform3DTimesVec4(CATransform3D mat, vec4 vec);

char *vec4AsString(const vec4 vec);

#define vec4Subtract(aVec, bVec) vec4Add(aVec, vec4Scale(-1., bVec))

#endif // VEC4_H_INCLUDED
