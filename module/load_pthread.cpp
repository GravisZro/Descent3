#include "load_pthread.h"

// System
#include <stdio.h>

#ifndef PTHREADLIB
  constexpr const char* const PTHREADLIB = "libpthread.so";
#endif

namespace pthread
{
  int (*pthread_create)(pthread_t*, const pthread_attr_t* attr, void *(*)(void*), void*) = nullptr;
  void (*pthread_exit)(void*) = nullptr;
  int (*pthread_detach)(pthread_t) = nullptr;
  pthread_t (*pthread_self)(void) = nullptr;

  static module::handle_t handle = nullptr;

  bool load(void)
  {
    if(handle != nullptr)
      return true;

    // Load the library
    if (!module::load(handle, PTHREADLIB, MODF_NOW | MODF_GLOBAL))
    {
      fprintf(stderr, "Library Load Failed: %s\n", PTHREADLIB);
      unload();
      return false;
    }

     if(!module::load_symbol(pthread_create, handle, "pthread_create") ||
        !module::load_symbol(pthread_exit, handle, "pthread_exit") ||
        !module::load_symbol(pthread_detach, handle, "pthread_detach") ||
        !module::load_symbol(pthread_self, handle, "pthread_self"))
    {
      fprintf(stderr, "Library Symbol Resolve Error: %s\n", PTHREADLIB);
      unload();
      return false;
    }
    return true;
  }

  bool unload(void)
  {
    pthread_create = nullptr;
    pthread_exit = nullptr;
    pthread_detach = nullptr;
    pthread_self = nullptr;

    if(handle != nullptr)
    {
      module::unload(handle);
      fprintf(stderr, "Library Unload Failed: %s\n", PTHREADLIB);
      return false;
    }
    return true;
  }
}
