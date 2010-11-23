/*
 *  defs.h
 *  sample
 *
 *  Created by Zach Margolis on 11/22/10.
 *
 */

#ifndef ZM_VEC_DEFS_H_INCLUDED
#define ZM_VEC_DEFS_H_INCLUDED

/*
 * These definitions only exist to let this project exist on its own,
 * independently of the GL/CoreAnimation libraries
 */
 
typedef float GLfloat;

typedef struct {
    GLfloat m11, m12, m13, m14;
    GLfloat m21, m22, m23, m24;
    GLfloat m31, m32, m33, m34;
    GLfloat m41, m42, m43, m44;
    } CATransform3D;

#endif // ZM_VEC_DEFS_H_INCLUDED
