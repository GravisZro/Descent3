#include "load_gl.h"

// System
#include <stdio.h>

#ifndef OPENGLLIB
#ifdef __unix__
  constexpr const char* const OPENGLLIB = "libGL.so";
#elif defined(_WIN32) || defined(__CYGWIN__)
  constexpr const char* const OPENGLLIB = "opengl32.dll";
#endif
#endif

#ifdef HAVE_WGL
namespace wgl
{
#if defined(WIN32)
  HGLRC (STDCALL *CreateContext)(HDC) = nullptr;
  BOOL  (STDCALL *DeleteContext)(HGLRC) = nullptr;
  BOOL  (STDCALL *MakeCurrent)(HDC, HGLRC) = nullptr;
  PROC  (STDCALL *GetProcAddress)(LPCSTR) = nullptr;
#else
  void* (STDCALL *CreateContext)(void*) = nullptr;
  bool  (STDCALL *DeleteContext)(void*) = nullptr;
  bool  (STDCALL *MakeCurrent)(void*, void*) = nullptr;
  void* (STDCALL *GetProcAddress)(void*) = nullptr;
#endif

  bool unload(void);

  bool load(module::handle_t handle)
  {
    if(!module::load_symbol(CreateContext, handle, "wglCreateContext", 255) ||
       !module::load_symbol(DeleteContext, handle, "wglDeleteContext", 255) ||
       !module::load_symbol(MakeCurrent, handle, "wglMakeCurrent", 255) ||
       !module::load_symbol(GetProcAddress, handle, "wglGetProcAddress", 255))
    {
      fprintf(stderr, "Unable to load OpenGL extensions: WindowsGL");
      unload();
      return false;
    }
    return true;
  }

  bool unload()
  {
    CreateContext = nullptr;
    DeleteContext = nullptr;
    MakeCurrent = nullptr;
    GetProcAddress = nullptr;
    return true;
  }
}
#endif

#ifdef HAVE_GLX
namespace glX
{
  Bool (*QueryExtension)(Display *dpy, int *errorb, int *event) = nullptr;
  GLXContext (*CreateContext)(Display *dpy, XVisualInfo *vis, GLXContext shareList, Bool direct) = nullptr;
  Bool (*MakeCurrent)(Display *dpy, GLXDrawable drawable, GLXContext ctx) = nullptr;
  void (*SwapBuffers)(Display *dpy, GLXDrawable drawable) = nullptr;
  int (*GetConfig)(Display *dpy, XVisualInfo *visual, int attrib, int *value) = nullptr;
  XVisualInfo *(*ChooseVisual)(Display *dpy, int screen, int *attribList) = nullptr;
  void (*DestroyContext)(Display *dpy, GLXContext ctx) = nullptr;
  void (*WaitGL)(void) = nullptr;

  bool unload(void);

  bool load(module::handle_t handle)
  {
    if(!module::load_symbol(QueryExtension, handle, "glXQueryExtension", 255) ||
      !module::load_symbol(CreateContext, handle, "glXCreateContext", 255) ||
      !module::load_symbol(MakeCurrent, handle, "glXMakeCurrent", 255) ||
      !module::load_symbol(SwapBuffers, handle, "glXSwapBuffers", 255) ||
      !module::load_symbol(GetConfig, handle, "glXGetConfig", 255) ||
      !module::load_symbol(ChooseVisual, handle, "glXChooseVisual", 255) ||
      !module::load_symbol(DestroyContext, handle, "glXDestroyContext", 255) ||
      !module::load_symbol(WaitGL, handle, "glXWaitGL", 255))
    {
      fprintf(stderr, "Unable to load OpenGL extensions: X11GL");
      unload();
      return false;
    }
    return true;
  }

  bool unload()
  {
    QueryExtension = nullptr;
    CreateContext = nullptr;
    MakeCurrent = nullptr;
    SwapBuffers = nullptr;
    GetConfig = nullptr;
    ChooseVisual = nullptr;
    DestroyContext = nullptr;
    WaitGL = nullptr;
    return true;
  }
}
#endif

namespace gl
{  
  void (STDCALL *AlphaFunc)(GLenum func, GLclampf ref) = nullptr;
  void (STDCALL *Begin)(GLenum mode) = nullptr;
  void (STDCALL *BindTexture)(GLenum target, GLuint texture) = nullptr;
  void (STDCALL *BlendFunc)(GLenum sfactor, GLenum dfactor) = nullptr;
  void (STDCALL *Clear)(GLbitfield mask) = nullptr;
  void (STDCALL *ClearColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) = nullptr;
  void (STDCALL *ClearDepth)(GLclampd depth) = nullptr;
  void (STDCALL *Color3ub)(GLubyte red, GLubyte green, GLubyte blue) = nullptr;
  void (STDCALL *Color4ub)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) = nullptr;
  void (STDCALL *Color4f)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = nullptr;
  void (STDCALL *ColorPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) = nullptr;
  void (STDCALL *NormalPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) = nullptr;
  void (STDCALL *DeleteTextures)(GLsizei n, const GLuint *textures) = nullptr;
  void (STDCALL *DepthFunc)(GLenum func) = nullptr;
  void (STDCALL *DepthMask)(GLboolean flag) = nullptr;
  void (STDCALL *DepthRange)(GLclampd zNear, GLclampd zFar) = nullptr;
  void (STDCALL *Disable)(GLenum cap) = nullptr;
  void (STDCALL *DisableClientState)(GLenum array) = nullptr;
  void (STDCALL *DrawArrays)(GLenum mode, GLint first, GLsizei count) = nullptr;
  void (STDCALL *DrawElements)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices) = nullptr;
  void (STDCALL *DrawPixels)(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) = nullptr;
  void (STDCALL *Enable)(GLenum cap) = nullptr;
  void (STDCALL *EnableClientState)(GLenum array) = nullptr;
  void (STDCALL *End)(void) = nullptr;
  void (STDCALL *Flush)(void) = nullptr;
  void (STDCALL *Fogf)(GLenum pname, GLfloat param) = nullptr;
  void (STDCALL *Fogfv)(GLenum pname, const GLfloat *params) = nullptr;
  void (STDCALL *Fogi)(GLenum pname, GLint param) = nullptr;
  GLenum(STDCALL *GetError)(void) = nullptr;
  const GLubyte *(STDCALL *GetString)(GLenum name) = nullptr;
  void (STDCALL *Hint)(GLenum target, GLenum mode) = nullptr;
  void (STDCALL *LoadIdentity)(void) = nullptr;
  void (STDCALL *MatrixMode)(GLenum mode) = nullptr;
  void (STDCALL *LoadMatrixf)(const GLfloat *m) = nullptr;
  void (STDCALL *Ortho)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble) = nullptr;
  void (STDCALL *PixelStorei)(GLenum pname, GLint param) = nullptr;
  void (STDCALL *PixelTransferi)(GLenum pname, GLint param) = nullptr;
  void (STDCALL *PolygonOffset)(GLfloat factor, GLfloat units) = nullptr;
  void (STDCALL *ReadPixels)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *) = nullptr;
  void (STDCALL *Scissor)(GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;
  void (STDCALL *ShadeModel)(GLenum mode) = nullptr;
  void (STDCALL *TexCoordPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) = nullptr;
  void (STDCALL *TexEnvf)(GLenum target, GLenum pname, GLfloat param) = nullptr;
  void (STDCALL *TexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) = nullptr;
  void (STDCALL *TexParameteri)(GLenum target, GLenum pname, GLint param) = nullptr;
  void (STDCALL *TexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) = nullptr;
  void (STDCALL *Vertex2i)(GLint, GLint) = nullptr;
  void (STDCALL *Vertex3f)(GLfloat, GLfloat, GLfloat) = nullptr;
  void (STDCALL *VertexPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) = nullptr;
  void (STDCALL *Viewport)(GLint x, GLint y, GLsizei width, GLsizei height) = nullptr;
  void (STDCALL *Color4fv)(const GLfloat *v) = nullptr;
  void (STDCALL *Vertex3fv)(const GLfloat *v) = nullptr;
  void (STDCALL *TexCoord4fv)(const GLfloat *v) = nullptr;
  void (STDCALL *TexCoord2f)(const GLfloat p1, const GLfloat p2) = nullptr;
  void (STDCALL *GetIntegerv)(GLenum pname, GLint *params) = nullptr;
  GLuint(STDCALL *GenLists)(GLsizei range) = nullptr;
  void (STDCALL *NewList)(GLuint list, GLenum mode) = nullptr;
  void (STDCALL *EndList)(void) = nullptr;
  void (STDCALL *CallLists)(GLsizei n, GLenum type, const GLvoid *lists) = nullptr;
  void (STDCALL *ListBase)(GLuint base) = nullptr;
  void (STDCALL *PushAttrib)(GLbitfield mask) = nullptr;
  void (STDCALL *PopAttrib)(void) = nullptr;
  void (STDCALL *Color3f)(GLfloat red, GLfloat green, GLfloat blue) = nullptr;
  void (STDCALL *RasterPos2i)(GLint x, GLint y) = nullptr;
  void (STDCALL *Bitmap)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap) = nullptr;

  /* ARB_multitexture */
  void (STDCALL *MultiTexCoord1d)(GLenum target, GLdouble s) = nullptr;
  void (STDCALL *MultiTexCoord1f)(GLenum target, GLfloat s) = nullptr;
  void (STDCALL *MultiTexCoord1i)(GLenum target, GLint s) = nullptr;
  void (STDCALL *MultiTexCoord1s)(GLenum target, GLshort s) = nullptr;

  void (STDCALL *MultiTexCoord2d)(GLenum target, GLdouble s, GLdouble t) = nullptr;
  void (STDCALL *MultiTexCoord2f)(GLenum target, GLfloat s, GLfloat t) = nullptr;
  void (STDCALL *MultiTexCoord2i)(GLenum target, GLint s, GLint t) = nullptr;
  void (STDCALL *MultiTexCoord2s)(GLenum target, GLshort s, GLshort t) = nullptr;

  void (STDCALL *MultiTexCoord3d)(GLenum target, GLdouble s, GLdouble t, GLdouble r) = nullptr;
  void (STDCALL *MultiTexCoord3f)(GLenum target, GLfloat s, GLfloat t, GLfloat r) = nullptr;
  void (STDCALL *MultiTexCoord3i)(GLenum target, GLint s, GLint t, GLint r) = nullptr;
  void (STDCALL *MultiTexCoord3s)(GLenum target, GLshort s, GLshort t, GLshort r) = nullptr;

  void (STDCALL *MultiTexCoord4d)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) = nullptr;
  void (STDCALL *MultiTexCoord4f)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) = nullptr;
  void (STDCALL *MultiTexCoord4i)(GLenum target, GLint s, GLint t, GLint r, GLint q) = nullptr;
  void (STDCALL *MultiTexCoord4s)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) = nullptr;

  void (STDCALL *MultiTexCoord1dv)(GLenum target, const GLdouble *v) = nullptr;
  void (STDCALL *MultiTexCoord1fv)(GLenum target, const GLfloat *v) = nullptr;
  void (STDCALL *MultiTexCoord1iv)(GLenum target, const GLint *v) = nullptr;
  void (STDCALL *MultiTexCoord1sv)(GLenum target, const GLshort *v) = nullptr;

  void (STDCALL *MultiTexCoord2dv)(GLenum target, const GLdouble *v) = nullptr;
  void (STDCALL *MultiTexCoord2fv)(GLenum target, const GLfloat *v) = nullptr;
  void (STDCALL *MultiTexCoord2iv)(GLenum target, const GLint *v) = nullptr;
  void (STDCALL *MultiTexCoord2sv)(GLenum target, const GLshort *v) = nullptr;

  void (STDCALL *MultiTexCoord3dv)(GLenum target, const GLdouble *v) = nullptr;
  void (STDCALL *MultiTexCoord3fv)(GLenum target, const GLfloat *v) = nullptr;
  void (STDCALL *MultiTexCoord3iv)(GLenum target, const GLint *v) = nullptr;
  void (STDCALL *MultiTexCoord3sv)(GLenum target, const GLshort *v) = nullptr;

  void (STDCALL *MultiTexCoord4dv)(GLenum target, const GLdouble *v) = nullptr;
  void (STDCALL *MultiTexCoord4fv)(GLenum target, const GLfloat *v) = nullptr;
  void (STDCALL *MultiTexCoord4iv)(GLenum target, const GLint *v) = nullptr;
  void (STDCALL *MultiTexCoord4sv)(GLenum target, const GLshort *v) = nullptr;

  void (STDCALL *ActiveTexture)(GLenum target) = nullptr;
  void (STDCALL *ClientActiveTexture)(GLenum target) = nullptr;

  bool have(extensions_t option)
  {
    switch(option)
    {
#ifdef HAVE_WGL
    case WGL:
      return wgl::CreateContext != nullptr;
#endif
#ifdef HAVE_GLX
    case XGL:
      return glX::CreateContext != nullptr;
#endif
    case ActiveTextureARB:
      return gl::ActiveTexture != nullptr;
    }
    return false;
  }

  static module::handle_t handle = nullptr;

  bool load(void)
  {
    if(handle != nullptr)
      return true;

    // Load the library
    if (!module::load(handle, OPENGLLIB, MODF_LAZY | MODF_GLOBAL))
    {
      fprintf(stderr, "Library Load Failed: %s\n", OPENGLLIB);
      unload();
      return false;
    }

    if(!module::load_symbol(AlphaFunc, handle, "glAlphaFunc", 255) ||
      !module::load_symbol(Begin, handle, "glBegin", 255) ||
      !module::load_symbol(BindTexture, handle, "glBindTexture", 255) ||
      !module::load_symbol(BlendFunc, handle, "glBlendFunc", 255) ||
      !module::load_symbol(Clear, handle, "glClear", 255) ||
      !module::load_symbol(ClearColor, handle, "glClearColor", 255) ||
      !module::load_symbol(ClearDepth, handle, "glClearDepth", 255) ||
      !module::load_symbol(Color3ub, handle, "glColor3ub", 255) ||
      !module::load_symbol(Color4ub, handle, "glColor4ub", 255) ||
      !module::load_symbol(Color4f, handle, "glColor4f", 255) ||
      !module::load_symbol(ColorPointer, handle, "glColorPointer", 255) ||
      !module::load_symbol(NormalPointer, handle, "glNormalPointer", 255) ||
      !module::load_symbol(DeleteTextures, handle, "glDeleteTextures", 255) ||
      !module::load_symbol(DepthFunc, handle, "glDepthFunc", 255) ||
      !module::load_symbol(DepthMask, handle, "glDepthMask", 255) ||
      !module::load_symbol(DepthRange, handle, "glDepthRange", 255) ||
      !module::load_symbol(Disable, handle, "glDisable", 255) ||
      !module::load_symbol(DisableClientState, handle, "glDisableClientState", 255) ||
      !module::load_symbol(DrawArrays, handle, "glDrawArrays", 255) ||
      !module::load_symbol(DrawElements, handle, "glDrawElements", 255) ||
      !module::load_symbol(DrawPixels, handle, "glDrawPixels", 255) ||
      !module::load_symbol(Enable, handle, "glEnable", 255) ||
      !module::load_symbol(EnableClientState, handle, "glEnableClientState", 255) ||
      !module::load_symbol(End, handle, "glEnd", 255) ||
      !module::load_symbol(Flush, handle, "glFlush", 255) ||
      !module::load_symbol(Fogf, handle, "glFogf", 255) ||
      !module::load_symbol(Fogfv, handle, "glFogfv", 255) ||
      !module::load_symbol(Fogi, handle, "glFogi", 255) ||
      !module::load_symbol(GetError, handle, "glGetError", 255) ||
      !module::load_symbol(GetString, handle, "glGetString", 255) ||
      !module::load_symbol(Hint, handle, "glHint", 255) ||
      !module::load_symbol(LoadIdentity, handle, "glLoadIdentity", 255) ||
      !module::load_symbol(LoadMatrixf, handle, "glLoadMatrixf", 255) ||
      !module::load_symbol(MatrixMode, handle, "glMatrixMode", 255) ||
      !module::load_symbol(Ortho, handle, "glOrtho", 255) ||
      !module::load_symbol(PixelStorei, handle, "glPixelStorei", 255) ||
      !module::load_symbol(PixelTransferi, handle, "glPixelTransferi", 255) ||
      !module::load_symbol(PolygonOffset, handle, "glPolygonOffset", 255) ||
      !module::load_symbol(ReadPixels, handle, "glReadPixels", 255) ||
      !module::load_symbol(Scissor, handle, "glScissor", 255) ||
      !module::load_symbol(ShadeModel, handle, "glShadeModel", 255) ||
      !module::load_symbol(TexCoordPointer, handle, "glTexCoordPointer", 255) ||
      !module::load_symbol(TexEnvf, handle, "glTexEnvf", 255) ||
      !module::load_symbol(TexImage2D, handle, "glTexImage2D", 255) ||
      !module::load_symbol(TexParameteri, handle, "glTexParameteri", 255) ||
      !module::load_symbol(TexSubImage2D, handle, "glTexSubImage2D", 255) ||
      !module::load_symbol(Vertex2i, handle, "glVertex2i", 255) ||
      !module::load_symbol(Vertex3f, handle, "glVertex3f", 255) ||
      !module::load_symbol(VertexPointer, handle, "glVertexPointer", 255) ||
      !module::load_symbol(Viewport, handle, "glViewport", 255) ||
      !module::load_symbol(Color4fv, handle, "glColor4fv", 255) ||
      !module::load_symbol(Vertex3fv, handle, "glVertex3fv", 255) ||
      !module::load_symbol(TexCoord4fv, handle, "glTexCoord4fv", 255))
    {
      fprintf(stderr, "Library Symbol Resolve Error: %s\n", OPENGLLIB);
      unload();
      return false;
    }

    if(!module::load_symbol(MultiTexCoord1d, handle, "glMultiTexCoord1d", 255) ||
      !module::load_symbol(MultiTexCoord1f, handle, "glMultiTexCoord1f", 255) ||
      !module::load_symbol(MultiTexCoord1i, handle, "glMultiTexCoord1i", 255) ||
      !module::load_symbol(MultiTexCoord1s, handle, "glMultiTexCoord1s", 255) ||

      !module::load_symbol(MultiTexCoord2d, handle, "glMultiTexCoord2d", 255) ||
      !module::load_symbol(MultiTexCoord2f, handle, "glMultiTexCoord2f", 255) ||
      !module::load_symbol(MultiTexCoord2i, handle, "glMultiTexCoord2i", 255) ||
      !module::load_symbol(MultiTexCoord3s, handle, "glMultiTexCoord2s", 255) ||

      !module::load_symbol(MultiTexCoord3d, handle, "glMultiTexCoord3d", 255) ||
      !module::load_symbol(MultiTexCoord3f, handle, "glMultiTexCoord3f", 255) ||
      !module::load_symbol(MultiTexCoord3i, handle, "glMultiTexCoord3i", 255) ||
      !module::load_symbol(MultiTexCoord3s, handle, "glMultiTexCoord3s", 255) ||

      !module::load_symbol(MultiTexCoord4d, handle, "glMultiTexCoord4d", 255) ||
      !module::load_symbol(MultiTexCoord4f, handle, "glMultiTexCoord4f", 255) ||
      !module::load_symbol(MultiTexCoord4i, handle, "glMultiTexCoord4i", 255) ||
      !module::load_symbol(MultiTexCoord4s, handle, "glMultiTexCoord4s", 255) ||

      !module::load_symbol(MultiTexCoord1dv, handle, "glMultiTexCoord1dv", 255) ||
      !module::load_symbol(MultiTexCoord1fv, handle, "glMultiTexCoord1fv", 255) ||
      !module::load_symbol(MultiTexCoord1iv, handle, "glMultiTexCoord1iv", 255) ||
      !module::load_symbol(MultiTexCoord1sv, handle, "glMultiTexCoord1sv", 255) ||

      !module::load_symbol(MultiTexCoord2dv, handle, "glMultiTexCoord2dv", 255) ||
      !module::load_symbol(MultiTexCoord2fv, handle, "glMultiTexCoord2fv", 255) ||
      !module::load_symbol(MultiTexCoord2iv, handle, "glMultiTexCoord2iv", 255) ||
      !module::load_symbol(MultiTexCoord3sv, handle, "glMultiTexCoord2sv", 255) ||

      !module::load_symbol(MultiTexCoord3dv, handle, "glMultiTexCoord3dv", 255) ||
      !module::load_symbol(MultiTexCoord3fv, handle, "glMultiTexCoord3fv", 255) ||
      !module::load_symbol(MultiTexCoord3iv, handle, "glMultiTexCoord3iv", 255) ||
      !module::load_symbol(MultiTexCoord3sv, handle, "glMultiTexCoord3sv", 255) ||

      !module::load_symbol(MultiTexCoord4dv, handle, "glMultiTexCoord4dv", 255) ||
      !module::load_symbol(MultiTexCoord4fv, handle, "glMultiTexCoord4fv", 255) ||
      !module::load_symbol(MultiTexCoord4iv, handle, "glMultiTexCoord4iv", 255) ||
      !module::load_symbol(MultiTexCoord4sv, handle, "glMultiTexCoord4sv", 255) ||

      !module::load_symbol(ActiveTexture, handle, "glActiveTexture", 255) ||
      !module::load_symbol(ClientActiveTexture, handle, "glClientActiveTexture", 255))
    {
      fprintf(stderr, "Unable to load OpenGL extensions: Active Texture");
    }

#ifdef HAVE_WGL
    wgl::load(handle);
#endif
#ifdef HAVE_GLX
    glX::load(handle);
#endif
    return true;
  }

  bool unload(void)
  {
    AlphaFunc = nullptr;
    Begin = nullptr;
    BindTexture = nullptr;
    BlendFunc = nullptr;
    Clear = nullptr;
    ClearColor = nullptr;
    ClearDepth = nullptr;
    Color3ub = nullptr;
    Color4ub = nullptr;
    Color4f = nullptr;
    ColorPointer = nullptr;
    NormalPointer = nullptr;
    DeleteTextures = nullptr;
    DepthFunc = nullptr;
    DepthMask = nullptr;
    DepthRange = nullptr;
    Disable = nullptr;
    DisableClientState = nullptr;
    DrawArrays = nullptr;
    DrawElements = nullptr;
    DrawPixels = nullptr;
    Enable = nullptr;
    EnableClientState = nullptr;
    End = nullptr;
    Flush = nullptr;
    Fogf = nullptr;
    Fogfv = nullptr;
    Fogi = nullptr;
    GetError = nullptr;
    GetString = nullptr;
    Hint = nullptr;
    LoadIdentity = nullptr;
    LoadMatrixf = nullptr;
    MatrixMode = nullptr;
    Ortho = nullptr;
    PixelStorei = nullptr;
    PixelTransferi = nullptr;
    PolygonOffset = nullptr;
    ReadPixels = nullptr;
    Scissor = nullptr;
    ShadeModel = nullptr;
    TexCoordPointer = nullptr;
    TexEnvf = nullptr;
    TexImage2D = nullptr;
    TexParameteri = nullptr;
    TexSubImage2D = nullptr;
    Vertex2i = nullptr;
    Vertex3f = nullptr;
    VertexPointer = nullptr;
    Viewport = nullptr;
    Color4fv = nullptr;
    Vertex3fv = nullptr;
    TexCoord4fv = nullptr;

    MultiTexCoord1d = nullptr;
    MultiTexCoord1f = nullptr;
    MultiTexCoord1i = nullptr;
    MultiTexCoord1s = nullptr;

    MultiTexCoord2d = nullptr;
    MultiTexCoord2f = nullptr;
    MultiTexCoord2i = nullptr;
    MultiTexCoord3s = nullptr;

    MultiTexCoord3d = nullptr;
    MultiTexCoord3f = nullptr;
    MultiTexCoord3i = nullptr;
    MultiTexCoord3s = nullptr;

    MultiTexCoord4d = nullptr;
    MultiTexCoord4f = nullptr;
    MultiTexCoord4i = nullptr;
    MultiTexCoord4s = nullptr;

    MultiTexCoord1dv = nullptr;
    MultiTexCoord1fv = nullptr;
    MultiTexCoord1iv = nullptr;
    MultiTexCoord1sv = nullptr;

    MultiTexCoord2dv = nullptr;
    MultiTexCoord2fv = nullptr;
    MultiTexCoord2iv = nullptr;
    MultiTexCoord3sv = nullptr;

    MultiTexCoord3dv = nullptr;
    MultiTexCoord3fv = nullptr;
    MultiTexCoord3iv = nullptr;
    MultiTexCoord3sv = nullptr;

    MultiTexCoord4dv = nullptr;
    MultiTexCoord4fv = nullptr;
    MultiTexCoord4iv = nullptr;
    MultiTexCoord4sv = nullptr;

    ActiveTexture = nullptr;
    ClientActiveTexture = nullptr;

#ifdef HAVE_WGL
    wgl::unload();
#endif
#ifdef HAVE_GLX
    glX::unload();
#endif
    return true;
  }
}
