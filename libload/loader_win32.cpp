#include "loader.h"

#if defined(_WIN32)

#include <ntinterface/native.h>

namespace dl
{
  handle_t open(const char* modfilename)
  {
    return nullptr;
  }

  bool close(handle_t handle)
  {
    return false;
  }

  symaddr_t sym(handle_t handle, const char* symstr)
  {
    return nullptr;
  }

  const char* const error_string(void)
  {
    return nullptr;
  }
}

#endif
