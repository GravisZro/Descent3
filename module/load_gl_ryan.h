/*
* Descent 3 
* Copyright (C) 2024 Parallax Software
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// ryan's add. Why wasn't this here? 04/18/2000
#ifndef LOAD_LIB_GL_RYAN
#define LOAD_LIB_GL_RYAN
// end ryan's add.

#include "gl.h"
#include "module.h"

#if defined(__unix__)
// ryan's add. 04/18/2000
typedef void (STDCALL *PFNGLACTIVETEXTUREARBPROC)(GLenum texture);
typedef void (STDCALL *PFNGLCLIENTACTIVETEXTUREARBPROC)(GLenum texture);
typedef void (STDCALL *PFNGLMULTITEXCOORD4FARBPROC)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
// end ryan's add.
#endif

// ryan's adds. 04/18/2000.
//  There was a bunch of stuff that was, I guess, not supported by
//  Mesa when Outrage did the original port. So buttloads of code
//  involving glActiveTextureARB() were #ifdef'd to only WIN32.
//  To make use of the extension more generic, platforms that can handle
//  it (Linux and Win32, as far as I care), define
//  _USE_OGL_ACTIVE_TEXTURES, and check that define instead of WIN32 when
//  using the extension.
#if !defined(_USE_OGL_ACTIVE_TEXTURES)
#if (defined(WIN32))
#define _USE_OGL_ACTIVE_TEXTURES
#endif
#endif
// end ryan's adds.

typedef void (STDCALL *glAlphaFunc_fp)(GLenum func, GLclampf ref);
typedef void (STDCALL *glBegin_fp)(GLenum mode);
typedef void (STDCALL *glBindTexture_fp)(GLenum target, GLuint texture);
typedef void (STDCALL *glBlendFunc_fp)(GLenum sfactor, GLenum dfactor);
typedef void (STDCALL *glClear_fp)(GLbitfield mask);
typedef void (STDCALL *glClearColor_fp)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
typedef void (STDCALL *glClearDepth_fp)(GLclampd depth);
typedef void (STDCALL *glColor3ub_fp)(GLubyte red, GLubyte green, GLubyte blue);
typedef void (STDCALL *glColor4ub_fp)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
typedef void (STDCALL *glColor4f_fp)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (STDCALL *glColorPointer_fp)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (STDCALL *glDeleteTextures_fp)(GLsizei n, const GLuint *textures);
typedef void (STDCALL *glDepthFunc_fp)(GLenum func);
typedef void (STDCALL *glDepthMask_fp)(GLboolean flag);
typedef void (STDCALL *glDepthRange_fp)(GLclampd zNear, GLclampd zFar);
typedef void (STDCALL *glDisable_fp)(GLenum cap);
typedef void (STDCALL *glDisableClientState_fp)(GLenum array);
typedef void (STDCALL *glDrawArrays_fp)(GLenum mode, GLint first, GLsizei count);
typedef void (STDCALL *glDrawPixels_fp)(GLsizei width, GLsizei height, GLenum format, GLenum type,
                                          const GLvoid *pixels);
typedef void (STDCALL *glEnable_fp)(GLenum cap);
typedef void (STDCALL *glEnableClientState_fp)(GLenum array);
typedef void (STDCALL *glEnd_fp)(void);
typedef void (STDCALL *glFlush_fp)(void);
typedef void (STDCALL *glFogf_fp)(GLenum pname, GLfloat param);
typedef void (STDCALL *glFogfv_fp)(GLenum pname, const GLfloat *params);
typedef void (STDCALL *glFogi_fp)(GLenum pname, GLint param);
typedef GLenum(STDCALL *glGetError_fp)(void);
typedef const GLubyte *(STDCALL *glGetString_fp)(GLenum name);
typedef void (STDCALL *glHint_fp)(GLenum target, GLenum mode);
typedef void (STDCALL *glLoadIdentity_fp)(void);
typedef void (STDCALL *glMatrixMode_fp)(GLenum mode);
typedef void (STDCALL *glOrtho_fp)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (STDCALL *glPixelStorei_fp)(GLenum pname, GLint param);
typedef void (STDCALL *glPixelTransferi_fp)(GLenum pname, GLint param);
typedef void (STDCALL *glPolygonOffset_fp)(GLfloat factor, GLfloat units);
typedef void (STDCALL *glReadPixels_fp)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *);
typedef void (STDCALL *glScissor_fp)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (STDCALL *glShadeModel_fp)(GLenum mode);
typedef void (STDCALL *glTexCoordPointer_fp)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (STDCALL *glTexEnvf_fp)(GLenum target, GLenum pname, GLfloat param);
typedef void (STDCALL *glTexImage2D_fp)(GLenum target, GLint level, GLint internalformat, GLsizei width,
                                          GLsizei height, GLint border, GLenum format, GLenum type,
                                          const GLvoid *pixels);
typedef void (STDCALL *glTexParameteri_fp)(GLenum target, GLenum pname, GLint param);
typedef void (STDCALL *glTexSubImage2D_fp)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width,
                                             GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (STDCALL *glVertex2i_fp)(GLint, GLint);
typedef void (STDCALL *glVertex3f_fp)(GLfloat, GLfloat, GLfloat);
typedef void (STDCALL *glVertexPointer_fp)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (STDCALL *glViewport_fp)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (STDCALL *glColor4fv_fp)(const GLfloat *v);
typedef void (STDCALL *glVertex3fv_fp)(const GLfloat *v);
typedef void (STDCALL *glTexCoord4fv_fp)(const GLfloat *v);
typedef void (STDCALL *glTexCoord2f_fp)(const GLfloat p1, const GLfloat p2);
typedef void (STDCALL *glGetIntegerv_fp)(GLenum pname, GLint *params);
typedef GLuint(STDCALL *glGenLists_fp)(GLsizei range);
typedef void (STDCALL *glNewList_fp)(GLuint list, GLenum mode);
typedef void (STDCALL *glEndList_fp)(void);
typedef void (STDCALL *glCallLists_fp)(GLsizei n, GLenum type, const GLvoid *lists);
typedef void (STDCALL *glListBase_fp)(GLuint base);
typedef void (STDCALL *glPushAttrib_fp)(GLbitfield mask);
typedef void (STDCALL *glPopAttrib_fp)(void);
typedef void (STDCALL *glColor3f_fp)(GLfloat red, GLfloat green, GLfloat blue);
typedef void (STDCALL *glRasterPos2i_fp)(GLint x, GLint y);
typedef void (STDCALL *glBitmap_fp)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove,
                                      GLfloat ymove, const GLubyte *bitmap);

#if defined(WIN32)
typedef HGLRC(STDCALL *wglCreateContext_fp)(HDC);
typedef BOOL(STDCALL *wglDeleteContext_fp)(HGLRC);
typedef BOOL(STDCALL *wglMakeCurrent_fp)(HDC, HGLRC);
typedef PROC(STDCALL *wglGetProcAddress_fp)(LPCSTR);

extern wglCreateContext_fp dwglCreateContext;
extern wglDeleteContext_fp dwglDeleteContext;
extern wglMakeCurrent_fp dwglMakeCurrent;
extern wglGetProcAddress_fp dwglGetProcAddress;

/* bk00614 - fuckit
#elif defined(__unix__)
typedef Bool (*glXQueryExtension_fp)( Display *dpy, int *errorb, int *event );
typedef GLXContext (*glXCreateContext_fp)( Display *dpy, XVisualInfo *vis,GLXContext shareList, Bool direct );
typedef Bool (*glXMakeCurrent_fp)( Display *dpy, GLXDrawable drawable,GLXContext ctx);
typedef void (*glXSwapBuffers_fp)( Display *dpy, GLXDrawable drawable );
typedef int (*glXGetConfig_fp)( Display *dpy, XVisualInfo *visual, int attrib, int *value );
typedef XVisualInfo* (*glXChooseVisual_fp)( Display *dpy, int screen, int *attribList );
typedef void (*glXDestroyContext_fp)( Display *dpy, GLXContext ctx );
typedef void (*glXWaitGL_fp)( void );

glXQueryExtension_fp glXQueryExtension = nullptr;
glXCreateContext_fp glXCreateContext = nullptr;
glXMakeCurrent_fp glXMakeCurrent = nullptr;
glXSwapBuffers_fp glXSwapBuffers = nullptr;
glXGetConfig_fp glXGetConfig = nullptr;
glXChooseVisual_fp glXChooseVisual = nullptr;
glXDestroyContext_fp glXDestroyContext = nullptr;
glXWaitGL_fp glXWaitGL = nullptr;
*/
#else

#endif

// bk000614 - have to fix globals
extern glAlphaFunc_fp glAlphaFunc;
extern glBegin_fp glBegin;
extern glBindTexture_fp glBindTexture;
extern glBlendFunc_fp glBlendFunc;
extern glClear_fp glClear;
extern glClearColor_fp glClearColor;
extern glClearDepth_fp glClearDepth;
extern glColor3ub_fp glColor3ub;
extern glColor4f_fp glColor4f;
extern glColor4fv_fp glColor4fv;
extern glColor4ub_fp glColor4ub;
extern glColorPointer_fp glColorPointer;
extern glDeleteTextures_fp glDeleteTextures;
extern glDepthFunc_fp glDepthFunc;
extern glDepthMask_fp glDepthMask;
extern glDepthRange_fp glDepthRange;
extern glDisable_fp glDisable;
extern glDisableClientState_fp glDisableClientState;
extern glDrawArrays_fp glDrawArrays;
extern glDrawPixels_fp glDrawPixels;
extern glEnable_fp glEnable;
extern glEnableClientState_fp glEnableClientState;
extern glEnd_fp glEnd;
extern glFlush_fp glFlush;
extern glFogf_fp glFogf;
extern glFogfv_fp glFogfv;
extern glFogi_fp glFogi;
extern glGetError_fp glGetError;
extern glGetString_fp glGetString;
extern glGetIntegerv_fp glGetIntegerv;
extern glHint_fp glHint;
extern glLoadIdentity_fp glLoadIdentity;
extern glMatrixMode_fp glMatrixMode;
extern glOrtho_fp glOrtho;
extern glPixelStorei_fp glPixelStorei;
extern glPixelTransferi_fp glPixelTransferi;
extern glPolygonOffset_fp glPolygonOffset;
extern glReadPixels_fp glReadPixels;
extern glScissor_fp glScissor;
extern glShadeModel_fp glShadeModel;
extern glTexCoord2f_fp glTexCoord2f;
extern glTexCoord4fv_fp glTexCoord4fv;
extern glTexCoordPointer_fp glTexCoordPointer;
extern glTexEnvf_fp glTexEnvf;
extern glTexImage2D_fp glTexImage2D;
extern glTexParameteri_fp glTexParameteri;
extern glTexSubImage2D_fp glTexSubImage2D;
extern glVertex2i_fp glVertex2i;
extern glVertex3f_fp glVertex3f;
extern glVertex3fv_fp glVertex3fv;
extern glVertexPointer_fp glVertexPointer;
extern glViewport_fp glViewport;

module *LoadOpenGLDLL(char *dllname);

// ryan's add. 10/04/2000
#ifdef __CHECK_FOR_TOO_SLOW_RENDERING__
void setMinimumAcceptableRenderTime(int ms);
#endif

// ryan's add. Why wasn't this here? 04/18/2000
#endif
// end ryan's add.
