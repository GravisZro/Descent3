#include "loader.h"

#ifdef __unix__
#include <dlfcn.h>

bool dl::open(const char* filename)
{
  m_instance = dlopen(filename, RTLD_NOW);
  if(m_instance == nullptr)
    m_last_error = dlerror();
  return m_instance != nullptr;
}

bool dl::close(void)
{
  if(dlclose(m_instance) < 0)
    m_last_error = dlerror();
  else
    m_instance = nullptr;
  return m_instance == nullptr;
}

dl::symaddr_t dl::sym(const char* symstr)
{
  symaddr_t rval = dlsym(m_instance, symstr);
  if(rval == nullptr)
    m_last_error = dlerror();
  return rval;
}

#endif
