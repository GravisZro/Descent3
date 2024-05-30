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
#ifndef LOAD_LIB_GL
#define LOAD_LIB_GL

// Backwards compatibility
#if __cplusplus < 201703L && !defined(__has_include)
# define __has_include(x) 0
#endif

// Macros
#if defined(_WIN32) || defined(__CYGWIN__)
# define HAVE_WGL
#endif

#if __has_include(<GL/glx.h>) || defined(__unix__)
# define HAVE_GLX
#endif

// System
#include <GL/gl.h>
#ifdef HAVE_GLX
# include <GL/glx.h>
#endif

// Project
#include "loader.h"

#ifdef HAVE_WGL
namespace wgl
{
#if defined(WIN32)
  extern HGLRC (STDCALL *CreateContext)(HDC);
  extern BOOL  (STDCALL *DeleteContext)(HGLRC);
  extern BOOL  (STDCALL *MakeCurrent)(HDC, HGLRC);
  extern PROC  (STDCALL *GetProcAddress)(LPCSTR);
#else
  extern void* (STDCALL *CreateContext)(void*);
  extern bool  (STDCALL *DeleteContext)(void*);
  extern bool  (STDCALL *MakeCurrent)(void*, void*);
  extern void* (STDCALL *GetProcAddress)(void*);
#endif
}
#endif

#ifdef HAVE_GLX
namespace glX
{
  extern Bool (STDCALL *QueryExtension)(Display *dpy, int *errorb, int *event);
  extern GLXContext (STDCALL *CreateContext)(Display *dpy, XVisualInfo *vis, GLXContext shareList, Bool direct);
  extern Bool (STDCALL *MakeCurrent)(Display *dpy, GLXDrawable drawable, GLXContext ctx);
  extern void (STDCALL *SwapBuffers)(Display *dpy, GLXDrawable drawable);
  extern int (STDCALL *GetConfig)(Display *dpy, XVisualInfo *visual, int attrib, int *value);
  extern XVisualInfo* (STDCALL *glXChooseVisual)(Display *dpy, int screen, int *attribList);
  extern void (STDCALL *DestroyContext)(Display *dpy, GLXContext ctx);
  extern void (STDCALL *WaitGL)(void);
}
#endif

namespace gl
{
  enum extensions_t
  {
    WGL,
    XGL,
    ActiveTextureARB,
  };

  bool have(extensions_t option);

  bool load(void);
  bool unload(void);

  /* ARB_multitexture */
  extern void (STDCALL *MultiTexCoord1d)(GLenum target, GLdouble s);
  extern void (STDCALL *MultiTexCoord1f)(GLenum target, GLfloat s);
  extern void (STDCALL *MultiTexCoord1i)(GLenum target, GLint s);
  extern void (STDCALL *MultiTexCoord1s)(GLenum target, GLshort s);

  extern void (STDCALL *MultiTexCoord2d)(GLenum target, GLdouble s, GLdouble t);
  extern void (STDCALL *MultiTexCoord2f)(GLenum target, GLfloat s, GLfloat t);
  extern void (STDCALL *MultiTexCoord2i)(GLenum target, GLint s, GLint t);
  extern void (STDCALL *MultiTexCoord2s)(GLenum target, GLshort s, GLshort t);

  extern void (STDCALL *MultiTexCoord3d)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
  extern void (STDCALL *MultiTexCoord3f)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
  extern void (STDCALL *MultiTexCoord3i)(GLenum target, GLint s, GLint t, GLint r);
  extern void (STDCALL *MultiTexCoord3s)(GLenum target, GLshort s, GLshort t, GLshort r);

  extern void (STDCALL *MultiTexCoord4d)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
  extern void (STDCALL *MultiTexCoord4f)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
  extern void (STDCALL *MultiTexCoord4i)(GLenum target, GLint s, GLint t, GLint r, GLint q);
  extern void (STDCALL *MultiTexCoord4s)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);

  extern void (STDCALL *MultiTexCoord1dv)(GLenum target, const GLdouble *v);
  extern void (STDCALL *MultiTexCoord1fv)(GLenum target, const GLfloat *v);
  extern void (STDCALL *MultiTexCoord1iv)(GLenum target, const GLint *v);
  extern void (STDCALL *MultiTexCoord1sv)(GLenum target, const GLshort *v);

  extern void (STDCALL *MultiTexCoord2dv)(GLenum target, const GLdouble *v);
  extern void (STDCALL *MultiTexCoord2fv)(GLenum target, const GLfloat *v);
  extern void (STDCALL *MultiTexCoord2iv)(GLenum target, const GLint *v);
  extern void (STDCALL *MultiTexCoord2sv)(GLenum target, const GLshort *v);

  extern void (STDCALL *MultiTexCoord3dv)(GLenum target, const GLdouble *v);
  extern void (STDCALL *MultiTexCoord3fv)(GLenum target, const GLfloat *v);
  extern void (STDCALL *MultiTexCoord3iv)(GLenum target, const GLint *v);
  extern void (STDCALL *MultiTexCoord3sv)(GLenum target, const GLshort *v);

  extern void (STDCALL *MultiTexCoord4dv)(GLenum target, const GLdouble *v);
  extern void (STDCALL *MultiTexCoord4fv)(GLenum target, const GLfloat *v);
  extern void (STDCALL *MultiTexCoord4iv)(GLenum target, const GLint *v);
  extern void (STDCALL *MultiTexCoord4sv)(GLenum target, const GLshort *v);

  extern void (STDCALL *ActiveTexture)(GLenum target);
  extern void (STDCALL *ClientActiveTexture)(GLenum target);

  extern void (STDCALL *AlphaFunc)(GLenum func, GLclampf ref);
  extern void (STDCALL *Begin)(GLenum mode);
  extern void (STDCALL *BindTexture)(GLenum target, GLuint texture);
  extern void (STDCALL *BlendFunc)(GLenum sfactor, GLenum dfactor);
  extern void (STDCALL *Clear)(GLbitfield mask);
  extern void (STDCALL *ClearColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
  extern void (STDCALL *ClearDepth)(GLclampd depth);
  extern void (STDCALL *Color3ub)(GLubyte red, GLubyte green, GLubyte blue);
  extern void (STDCALL *Color4ub)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
  extern void (STDCALL *Color4f)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
  extern void (STDCALL *ColorPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
  extern void (STDCALL *NormalPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
  extern void (STDCALL *DeleteTextures)(GLsizei n, const GLuint *textures);
  extern void (STDCALL *DepthFunc)(GLenum func);
  extern void (STDCALL *DepthMask)(GLboolean flag);
  extern void (STDCALL *DepthRange)(GLclampd zNear, GLclampd zFar);
  extern void (STDCALL *Disable)(GLenum cap);
  extern void (STDCALL *DisableClientState)(GLenum array);
  extern void (STDCALL *DrawArrays)(GLenum mode, GLint first, GLsizei count);
  extern void (STDCALL *DrawElements)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
  extern void (STDCALL *DrawPixels)(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
  extern void (STDCALL *Enable)(GLenum cap);
  extern void (STDCALL *EnableClientState)(GLenum array);
  extern void (STDCALL *End)(void);
  extern void (STDCALL *Flush)(void);
  extern void (STDCALL *Fogf)(GLenum pname, GLfloat param);
  extern void (STDCALL *Fogfv)(GLenum pname, const GLfloat *params);
  extern void (STDCALL *Fogi)(GLenum pname, GLint param);
  extern GLenum(STDCALL *GetError)(void);
  extern const GLubyte *(STDCALL *GetString)(GLenum name);
  extern void (STDCALL *Hint)(GLenum target, GLenum mode);
  extern void (STDCALL *LoadIdentity)(void);
  extern void (STDCALL *MatrixMode)(GLenum mode);
  extern void (STDCALL *LoadMatrixf)(const GLfloat *m);
  extern void (STDCALL *Ortho)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
  extern void (STDCALL *PixelStorei)(GLenum pname, GLint param);
  extern void (STDCALL *PixelTransferi)(GLenum pname, GLint param);
  extern void (STDCALL *PolygonOffset)(GLfloat factor, GLfloat units);
  extern void (STDCALL *ReadPixels)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *);
  extern void (STDCALL *Scissor)(GLint x, GLint y, GLsizei width, GLsizei height);
  extern void (STDCALL *ShadeModel)(GLenum mode);
  extern void (STDCALL *TexCoordPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
  extern void (STDCALL *TexEnvf)(GLenum target, GLenum pname, GLfloat param);
  extern void (STDCALL *TexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
  extern void (STDCALL *TexParameteri)(GLenum target, GLenum pname, GLint param);
  extern void (STDCALL *TexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
  extern void (STDCALL *Vertex2i)(GLint, GLint);
  extern void (STDCALL *Vertex3f)(GLfloat, GLfloat, GLfloat);
  extern void (STDCALL *VertexPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
  extern void (STDCALL *Viewport)(GLint x, GLint y, GLsizei width, GLsizei height);
  extern void (STDCALL *Color4fv)(const GLfloat *v);
  extern void (STDCALL *Vertex3fv)(const GLfloat *v);
  extern void (STDCALL *TexCoord4fv)(const GLfloat *v);
  extern void (STDCALL *TexCoord2f)(const GLfloat p1, const GLfloat p2);
  extern void (STDCALL *GetIntegerv)(GLenum pname, GLint *params);
  extern GLuint(STDCALL *GenLists)(GLsizei range);
  extern void (STDCALL *NewList)(GLuint list, GLenum mode);
  extern void (STDCALL *EndList)(void);
  extern void (STDCALL *CallLists)(GLsizei n, GLenum type, const GLvoid *lists);
  extern void (STDCALL *ListBase)(GLuint base);
  extern void (STDCALL *PushAttrib)(GLbitfield mask);
  extern void (STDCALL *PopAttrib)(void);
  extern void (STDCALL *Color3f)(GLfloat red, GLfloat green, GLfloat blue);
  extern void (STDCALL *RasterPos2i)(GLint x, GLint y);
  extern void (STDCALL *Bitmap)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
}



// ryan's add. 10/04/2000
#ifdef __CHECK_FOR_TOO_SLOW_RENDERING__
  void setMinimumAcceptableRenderTime(int ms);
#endif

#endif
