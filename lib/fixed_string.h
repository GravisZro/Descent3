#ifndef FIXED_STRING_H
#define FIXED_STRING_H

#include <array>
#include <string>
#include <string_view>
#include <cstring>
#include <algorithm>
#include <istream>
#include <ostream>
#include <iterator>
#include <cassert>
#include "linux_fix.h"

template<std::size_t length>
struct fixed_string_t : std::array<char, length>
{
  constexpr fixed_string_t(const char* const data) noexcept
  {
    std::array<char, length>::fill('\0');
    strncpy(std::array<char, length>::data(), data, length);
  }

  constexpr fixed_string_t(std::string_view data) noexcept
  {
    std::array<char, length>::fill('\0');
    std::copy(std::begin(data), std::end(data), std::begin(*this));
  }

  constexpr fixed_string_t(char fill_with = '\0') noexcept
    { std::array<char, length>::fill(fill_with); }

  constexpr void clear(void) { std::array<char, length>::fill('\0'); }

  constexpr bool empty(void) const { return std::array<char, length>::at(0) == '\0'; }

  constexpr std::size_t size(void) const
    { return std::distance(std::begin(*this), terminator()); }

  inline std::string string(void) const
    { return std::string(std::begin(*this), terminator()); }

  constexpr auto terminator(void) const
    { return std::find(std::begin(*this), std::end(*this), '\0'); }

  constexpr void operator = (const fixed_string_t<length>& other)
    { std::copy(std::begin(other), std::end(other), std::begin(*this)); }

  inline void operator =(const std::string& other)
  {
    std::array<char, length>::fill('\0');
    std::copy_n(std::begin(other), std::min(length, other.size()), std::begin(*this));
  }

  inline void operator =(const char* other)
  {
    assert(std::strlen(other) < length);
    std::array<char, length>::fill('\0');
    strncpy(std::data(*this), other, length);
  }

  template<typename T> bool operator != (const T& other) const { return !operator ==(other); }

  template<std::size_t other_length>
  bool operator == (const fixed_string_t<other_length>& other) const
    { return !stricmp(std::data(*this), std::data(other)); }

  bool operator == (const char* other) const { return !stricmp(std::data(*this), other); }
};

template<std::size_t length>
constexpr std::ostream& operator <<(std::ostream& output, const fixed_string_t<length>& fs)
{
  std::copy_n(std::begin(fs), length, std::ostream_iterator<char>(output));
  return output;
}

template<std::size_t length>
constexpr std::istream& operator >>(std::istream& input, fixed_string_t<length>& fs)
{
  std::copy_n(std::istream_iterator<char>(input), length, std::begin(fs));
  return input;
}

#endif // FIXED_STRING_H
