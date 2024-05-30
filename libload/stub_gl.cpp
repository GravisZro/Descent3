#include "stub_gl.h"

// System
#include <cstdio>

#ifndef OPENGLLIB
#ifdef __unix__
  constexpr const char* const OPENGLLIB = "libGL.so";
#elif defined(_WIN32) || defined(__CYGWIN__)
  constexpr const char* const OPENGLLIB = "opengl32.dll";
#endif
#endif

static dl lib;

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

  bool load(void)
  {
    if(!lib.sym(CreateContext, "wglCreateContext") ||
       !lib.sym(DeleteContext, "wglDeleteContext") ||
       !lib.sym(MakeCurrent, "wglMakeCurrent") ||
       !lib.sym(GetProcAddress, "wglGetProcAddress"))
    {
      std::fprintf(stderr, "Unable to load OpenGL extensions: WindowsGL\nError: %s\n",
                   lib.error_string());
      unload();
      return false;
    }
    return true;
  }

  bool unload(void)
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

  bool load(void)
  {
    if(!lib.sym(QueryExtension, "glXQueryExtension") ||
      !lib.sym(CreateContext, "glXCreateContext") ||
      !lib.sym(MakeCurrent, "glXMakeCurrent") ||
      !lib.sym(SwapBuffers, "glXSwapBuffers") ||
      !lib.sym(GetConfig, "glXGetConfig") ||
      !lib.sym(ChooseVisual, "glXChooseVisual") ||
      !lib.sym(DestroyContext, "glXDestroyContext") ||
      !lib.sym(WaitGL, "glXWaitGL"))
    {
      std::fprintf(stderr, "Unable to load OpenGL extensions: X11GL\nError: %s\n",
                   lib.error_string());
      unload();
      return false;
    }
    return true;
  }

  bool unload(void)
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

  static dl lib;

  bool load(void)
  {
    if(lib.is_open())
      return true;

    std::fprintf(stdout, "Loading Library %s\n", OPENGLLIB);

    // Load the library
    if (!lib.open(OPENGLLIB))
    {
      std::fprintf(stderr, "Library Load Failed: %s\nError: %s\n",
                   OPENGLLIB,
                   lib.error_string());
      unload();
      return false;
    }

    if(!lib.sym(AlphaFunc, "glAlphaFunc") ||
      !lib.sym(Begin, "glBegin") ||
      !lib.sym(BindTexture, "glBindTexture") ||
      !lib.sym(BlendFunc, "glBlendFunc") ||
      !lib.sym(Clear, "glClear") ||
      !lib.sym(ClearColor, "glClearColor") ||
      !lib.sym(ClearDepth, "glClearDepth") ||
      !lib.sym(Color3ub, "glColor3ub") ||
      !lib.sym(Color4ub, "glColor4ub") ||
      !lib.sym(Color4f, "glColor4f") ||
      !lib.sym(ColorPointer, "glColorPointer") ||
      !lib.sym(NormalPointer, "glNormalPointer") ||
      !lib.sym(DeleteTextures, "glDeleteTextures") ||
      !lib.sym(DepthFunc, "glDepthFunc") ||
      !lib.sym(DepthMask, "glDepthMask") ||
      !lib.sym(DepthRange, "glDepthRange") ||
      !lib.sym(Disable, "glDisable") ||
      !lib.sym(DisableClientState, "glDisableClientState") ||
      !lib.sym(DrawArrays, "glDrawArrays") ||
      !lib.sym(DrawElements, "glDrawElements") ||
      !lib.sym(DrawPixels, "glDrawPixels") ||
      !lib.sym(Enable, "glEnable") ||
      !lib.sym(EnableClientState, "glEnableClientState") ||
      !lib.sym(End, "glEnd") ||
      !lib.sym(Flush, "glFlush") ||
      !lib.sym(Fogf, "glFogf") ||
      !lib.sym(Fogfv, "glFogfv") ||
      !lib.sym(Fogi, "glFogi") ||
      !lib.sym(GetError, "glGetError") ||
      !lib.sym(GetString, "glGetString") ||
      !lib.sym(Hint, "glHint") ||
      !lib.sym(LoadIdentity, "glLoadIdentity") ||
      !lib.sym(LoadMatrixf, "glLoadMatrixf") ||
      !lib.sym(MatrixMode, "glMatrixMode") ||
      !lib.sym(Ortho, "glOrtho") ||
      !lib.sym(PixelStorei, "glPixelStorei") ||
      !lib.sym(PixelTransferi, "glPixelTransferi") ||
      !lib.sym(PolygonOffset, "glPolygonOffset") ||
      !lib.sym(ReadPixels, "glReadPixels") ||
      !lib.sym(Scissor, "glScissor") ||
      !lib.sym(ShadeModel, "glShadeModel") ||
      !lib.sym(TexCoordPointer, "glTexCoordPointer") ||
      !lib.sym(TexEnvf, "glTexEnvf") ||
      !lib.sym(TexImage2D, "glTexImage2D") ||
      !lib.sym(TexParameteri, "glTexParameteri") ||
      !lib.sym(TexSubImage2D, "glTexSubImage2D") ||
      !lib.sym(Vertex2i, "glVertex2i") ||
      !lib.sym(Vertex3f, "glVertex3f") ||
      !lib.sym(VertexPointer, "glVertexPointer") ||
      !lib.sym(Viewport, "glViewport") ||
      !lib.sym(Color4fv, "glColor4fv") ||
      !lib.sym(Vertex3fv, "glVertex3fv") ||
      !lib.sym(TexCoord4fv, "glTexCoord4fv"))
    {
      std::fprintf(stderr, "Library Symbol Resolve Error: %s\nError: %s\n",
                   OPENGLLIB,
                   lib.error_string());
      unload();
      return false;
    }

    if(!lib.sym(MultiTexCoord1d, "glMultiTexCoord1d") ||
      !lib.sym(MultiTexCoord1f, "glMultiTexCoord1f") ||
      !lib.sym(MultiTexCoord1i, "glMultiTexCoord1i") ||
      !lib.sym(MultiTexCoord1s, "glMultiTexCoord1s") ||

      !lib.sym(MultiTexCoord2d, "glMultiTexCoord2d") ||
      !lib.sym(MultiTexCoord2f, "glMultiTexCoord2f") ||
      !lib.sym(MultiTexCoord2i, "glMultiTexCoord2i") ||
      !lib.sym(MultiTexCoord3s, "glMultiTexCoord2s") ||

      !lib.sym(MultiTexCoord3d, "glMultiTexCoord3d") ||
      !lib.sym(MultiTexCoord3f, "glMultiTexCoord3f") ||
      !lib.sym(MultiTexCoord3i, "glMultiTexCoord3i") ||
      !lib.sym(MultiTexCoord3s, "glMultiTexCoord3s") ||

      !lib.sym(MultiTexCoord4d, "glMultiTexCoord4d") ||
      !lib.sym(MultiTexCoord4f, "glMultiTexCoord4f") ||
      !lib.sym(MultiTexCoord4i, "glMultiTexCoord4i") ||
      !lib.sym(MultiTexCoord4s, "glMultiTexCoord4s") ||

      !lib.sym(MultiTexCoord1dv, "glMultiTexCoord1dv") ||
      !lib.sym(MultiTexCoord1fv, "glMultiTexCoord1fv") ||
      !lib.sym(MultiTexCoord1iv, "glMultiTexCoord1iv") ||
      !lib.sym(MultiTexCoord1sv, "glMultiTexCoord1sv") ||

      !lib.sym(MultiTexCoord2dv, "glMultiTexCoord2dv") ||
      !lib.sym(MultiTexCoord2fv, "glMultiTexCoord2fv") ||
      !lib.sym(MultiTexCoord2iv, "glMultiTexCoord2iv") ||
      !lib.sym(MultiTexCoord3sv, "glMultiTexCoord2sv") ||

      !lib.sym(MultiTexCoord3dv, "glMultiTexCoord3dv") ||
      !lib.sym(MultiTexCoord3fv, "glMultiTexCoord3fv") ||
      !lib.sym(MultiTexCoord3iv, "glMultiTexCoord3iv") ||
      !lib.sym(MultiTexCoord3sv, "glMultiTexCoord3sv") ||

      !lib.sym(MultiTexCoord4dv, "glMultiTexCoord4dv") ||
      !lib.sym(MultiTexCoord4fv, "glMultiTexCoord4fv") ||
      !lib.sym(MultiTexCoord4iv, "glMultiTexCoord4iv") ||
      !lib.sym(MultiTexCoord4sv, "glMultiTexCoord4sv") ||

      !lib.sym(ActiveTexture, "glActiveTexture") ||
      !lib.sym(ClientActiveTexture, "glClientActiveTexture"))
    {
      std::fprintf(stderr, "Unable to load OpenGL extensions: Active Texture\nError: %s\n",
                   lib.error_string());
    }

#ifdef HAVE_WGL
    wgl::load();
#endif
#ifdef HAVE_GLX
    glX::load();
#endif
    return true;
  }

  bool unload(void)
  {
    std::fprintf(stdout, "Unloading Library %s\n", OPENGLLIB);

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
