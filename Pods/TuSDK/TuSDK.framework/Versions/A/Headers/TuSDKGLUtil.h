//
//  TuSDKGLUtil.h
//  TuSDKVideo
//
//  Created by Yanlin Qiu on 01/12/2016.
//  Copyright © 2016 TuSDK. All rights reserved.
//

#ifndef TuSDKGLUtil_h
#define TuSDKGLUtil_h

#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGLES/ES3/gl.h>
#else
#include <GLES3/gl3.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#endif
#ifdef __cplusplus

extern "C" {
#endif


typedef struct
{
    GLfloat   m[4][4];
} lasqueGLMatrix;
    
//
/// \brief multiply matrix specified by result with a scaling matrix and return new matrix in result
/// \param result Specifies the input matrix.  Scaled matrix is returned in result.
/// \param sx, sy, sz Scale factors along the x, y and z axes respectively
//
void lasqueGLScale ( lasqueGLMatrix *result, GLfloat sx, GLfloat sy, GLfloat sz );

//
/// \brief multiply matrix specified by result with a translation matrix and return new matrix in result
/// \param result Specifies the input matrix.  Translated matrix is returned in result.
/// \param tx, ty, tz Scale factors along the x, y and z axes respectively
//
void lasqueGLTranslate ( lasqueGLMatrix *result, GLfloat tx, GLfloat ty, GLfloat tz );

//
/// \brief multiply matrix specified by result with a rotation matrix and return new matrix in result
/// \param result Specifies the input matrix.  Rotated matrix is returned in result.
/// \param angle Specifies the angle of rotation, in degrees.
/// \param x, y, z Specify the x, y and z coordinates of a vector, respectively
//
void lasqueGLRotate ( lasqueGLMatrix *result, GLfloat angle, GLfloat x, GLfloat y, GLfloat z );

//
// \brief multiply matrix specified by result with a perspective matrix and return new matrix in result
/// \param result Specifies the input matrix.  new matrix is returned in result.
/// \param left, right Coordinates for the left and right vertical clipping planes
/// \param bottom, top Coordinates for the bottom and top horizontal clipping planes
/// \param nearZ, farZ Distances to the near and far depth clipping planes.  Both distances must be positive.
//
void lasqueGLFrustum ( lasqueGLMatrix *result, float left, float right, float bottom, float top, float nearZ, float farZ );

//
/// \brief multiply matrix specified by result with a perspective matrix and return new matrix in result
/// \param result Specifies the input matrix.  new matrix is returned in result.
/// \param fovy Field of view y angle in degrees
/// \param aspect Aspect ratio of screen
/// \param nearZ Near plane distance
/// \param farZ Far plane distance
//
void lasqueGLPerspective ( lasqueGLMatrix *result, float fovy, float aspect, float nearZ, float farZ );

//
/// \brief multiply matrix specified by result with a perspective matrix and return new matrix in result
/// \param result Specifies the input matrix.  new matrix is returned in result.
/// \param left, right Coordinates for the left and right vertical clipping planes
/// \param bottom, top Coordinates for the bottom and top horizontal clipping planes
/// \param nearZ, farZ Distances to the near and far depth clipping planes.  These values are negative if plane is behind the viewer
//
void lasqueGLOrtho ( lasqueGLMatrix *result, float left, float right, float bottom, float top, float nearZ, float farZ );

//
/// \brief perform the following operation - result matrix = srcA matrix * srcB matrix
/// \param result Returns multiplied matrix
/// \param srcA, srcB Input matrices to be multiplied
//
void lasqueGLMatrixMultiply ( lasqueGLMatrix *result, lasqueGLMatrix *srcA, lasqueGLMatrix *srcB );
    
//
//// \brief return an indentity matrix
//// \param result returns identity matrix
//
void lasqueGLMatrixLoadIdentity ( lasqueGLMatrix *result );

#ifdef __cplusplus
}
#endif

#endif /* TuSDKGLUtil_h */
