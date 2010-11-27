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
    vec4 cVec = vec4Make(0., 0., 0., 1.);
    
    // Since these are structs, it's easy to access the components
    aVec.x = 10.;
    aVec.z = bVec.z;
    
    // There are some constants for commonly used vecs
    vec3 zero = vec3Zero;
    vec3 yUp = vec3UnitVectorY;
    vec4 zAxis = vec4UnitVectorZ;
    
    // Most common vector operations are currently supported
    GLfloat scalar = 1.;
    vec3 resultVec = vec3Zero;
    GLfloat resultF = 0.;

    resultVec = vec3Add(aVec, bVec);
    resultVec = vec3Subtract(zero, yUp);
    resultVec = vec3Scale(scalar, aVec);
    resultVec = vec3Normalize(aVec);
    resultVec = vec3Cross(aVec, bVec);
    resultVec = vec3Mix(aVec, bVec, scalar);
    
    resultF = vec3Magnitude(aVec);
    resultF = vec3Dot(aVec, bVec);
     
    
    // There are some helper functions for moving between vec3's and vec4's
    vec3 aVec3 = vec3Make(4., 5., 6.);
    vec4 aVec4 = vec4MakeFromVec3(aVec3, 7);
    vec3 bVec3 = vec3TruncateVec4(aVec4);
    
    // There are convenience functions for printing, too.
    // Given a char* address, they will the string to that address, and return the
    // address of the string. The simplest solution for printing so far is to give 
    // the vecXToString functions a char[] array allocated on the stack.
    //
    // We guess that 128 chars is probably safe for most vectors.

    vec3 pVec3 = vec3Make(2., 4., 6.);
    char pVec3Chars[128];
    printf("pVec3: %s\n", vec3ToString(pVec3, pVec3Chars));
    
    vec4 pVec4 = vec4Make(1., .5, .125, .0625);
    char pVec4Chars[128];
    printf("pVec4: %s\n", vec4ToString(pVec4, pVec4Chars));
    
    // Equality
    aVec = vec3Make(0., 1., 2.);
    bVec = vec3Make(0., 2., 2.);
    char aVecChars[128];
    char bVecChars[128];
    
    printf("\n");
    printf("aVec: %s\nbVec: %s\n", vec3ToString(aVec, aVecChars), vec3ToString(bVec, bVecChars));
    
    if(vec3Equal(aVec, bVec))
    {
        printf("aVec is equal to bVec\n");
    }
    else
    {
        printf("aVec is NOT equal to bVec\n");
    }
    
    
    return 0;
}
