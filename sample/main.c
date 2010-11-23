/*
 *  main.c
 *  sample
 *
 *  Created by Zach Margolis on 11/22/10.
 */

#include <stdio.h>

#include "defs.h"

#include "vec3.h"
#include "vec4.h"

int main(int argc, char **argv)
{
    // The constructors are of the form vecXMake(...);
    vec3 aVec = vec3Make(1., 2., 3.);
    vec3 bVec = vec3Make(-1., -2., 3.);
    
    // Since these are structs, it's easy to access the components
    aVec.x = 10.;
    aVec.z = bVec.z;
    
    // There are some constants for commonly used vecs
    vec3 zero = vec3Zero;
    vec3 yUp = vec3UnitVectorY;
    
    // Most common vector operations are currently supported
    GLfloat scalar = 1.;
    vec3 resultVec = vec3Zero;
    GLfloat resultF = 0.;

    resultVec = vec3Add(aVec, bVec);
    resultVec = vec3Subtract(zero, yUp);
    resultVec = vec3Scale(scalar, aVec);
    resultVec = vec3Normalize(aVec);
    resultVec = vec3Cross(aVec, bVec);
    
    resultF = vec3Magnitude(aVec);
    resultF = vec3Dot(aVec, bVec);
     
    
    // There are some helper functions for moving between vec3's and vec4's
    vec3 aVec3 = vec3Make(4., 5., 6.);
    vec4 aVec4 = vec4MakeFromVec3(aVec3, 7);
    vec3 bVec3 = vec3TruncateVec4(aVec4);
    
    // There are convenience functions for printing, too
    vec3 pVec3 = vec3Make(2., 4., 6.);
    printf("pVec3: %s\n", vec3AsString(pVec3));
    
    vec4 pVec4 = vec4Make(1., .5, .125, .0625);
    printf("pVec4: %s\n", vec4AsString(pVec4));
    
    
    return 0;
}
