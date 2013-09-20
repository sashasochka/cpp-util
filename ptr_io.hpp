#ifndef UTIL_PTR_IO_HPP
#define UTIL_PTR_IO_HPP

#include <iostream>
#include "ptr.hpp"

namespace util {
template <typename T>
inline std::ostream& operator <<(std::ostream& out, ptr<T> p) {
    return out << p.get();
}
} // namespace util

#endif // ndef UTIL_PTR_IO_HPP

