#ifndef LOAD_LIB_LOADER_H
#define LOAD_LIB_LOADER_H

//System
#include <stdint.h>
#include <string>

// Project
//#include <utils/osdetect.h>

#ifdef _MSC_VER // MSVC Build
# define STDCALL __stdcall
#else // Non-MS compilers
# if defined(__i386__) || defined(_X86_) || defined(__THW_INTEL__) // if x86
#  define STDCALL __attribute__((stdcall))
# else
#  define STDCALL
# endif
#endif

// based on POSIX.1-2001
class dl
{
public:
#ifdef WIN32
  typedef FARPROC symaddr_t;
  typedef HINSTANCE handle_t;
#else
  typedef void* symaddr_t;
  typedef void* handle_t;
#endif

  bool open(const char* modfilename);
  bool close(void);

  constexpr bool is_open(void) const { return m_instance != nullptr; }

  symaddr_t sym(const char* symstr);

  template<typename RType>
  inline bool sym(RType& value, const char* const symstr)
    { return (value = reinterpret_cast<RType>(sym(symstr))) != nullptr; }

  const char* const error_string(void) const { return m_last_error.c_str(); }
  bool have_error(void) const { return m_last_error.empty(); }

private:
  std::string m_last_error;
  handle_t m_instance = nullptr;
};

#endif
