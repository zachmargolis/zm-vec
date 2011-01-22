/*
 *  vec4.h
 *  Created by Zach Margolis on 10/10/10.
 *
 */

#ifndef VEC4_H_INCLUDED
#define VEC4_H_INCLUDED



// TODO: change importing so that defs.h doesn't have to be included, and we can link to the OpenGL frameworks
#include "defs.h"
//#import <OpenGLES/ES1/gl.h>
//#import <OpenGLES/ES2/gl.h>

//#import <QuartzCore/CATransform3D.h>
#include "vec3.h"

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

vec4 vec4Make(const GLfloat x, const GLfloat y, const GLfloat z, const GLfloat w); 
vec4 vec4MakeFromVec2(const vec2 vec, GLfloat z, GLfloat w);
vec4 vec4MakeFromVec3(const vec3 vec, GLfloat w);
vec2 vec2TruncateVec4(const vec4 vec);
vec3 vec3TruncateVec4(const vec4 vec);

int vec4Equal(const vec4 aVec, const vec4 bVec);

GLfloat vec4Magnitude(const vec4 inVec);
GLfloat vec4Dot(const vec4 aVec, const vec4 bVec);

vec4 vec4Scale(const GLfloat scalar, const vec4 inVec);
vec4 vec4Normalize(const vec4 inVec);
vec4 vec4Add(const vec4 aVec, const vec4 bVec);
vec4 vec4Subtract(const vec4 aVec, const vec4 bVec);
vec4 vec4Mix(const vec4 aVec, const vec4 bVec, const GLfloat blend);

vec4 CATransform3DTimesVec4(const CATransform3D mat, const vec4 vec);

char *vec4ToString(const vec4 vec, char *str);

#endif // VEC4_H_INCLUDED
