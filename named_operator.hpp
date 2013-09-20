#ifndef UTIL_NAMED_OPERATOR_HPP
#define UTIL_NAMED_OPERATOR_HPP

#include <utility>

namespace util {

template <typename F>
struct named_operator_wrapper {
    F f;
};

template <typename T, typename F>
struct named_operator_lhs {
    F f;
    T& value;
};

template <typename T, typename F>
named_operator_lhs<T, F> operator <(T& lhs, named_operator_wrapper<F> rhs) {
    return {rhs.f, lhs};
}

template <typename T, typename F>
named_operator_lhs<T const, F> operator <(T const& lhs, named_operator_wrapper<F> rhs) {
    return {rhs.f, lhs};
}

template <typename T1, typename T2, typename F>
auto operator >(named_operator_lhs<T1, F> const& lhs, T2 const& rhs)
    -> decltype(lhs.f(lhs.value, rhs))
{
    return lhs.f(lhs.value, rhs);
}

template <typename T1, typename T2, typename F>
auto operator >=(named_operator_lhs<T1, F> const& lhs, T2 const& rhs)
    -> decltype(lhs.value = lhs.f(lhs.value, rhs))
{
    return lhs.value = lhs.f(lhs.value, rhs);
}

template <typename F>
constexpr named_operator_wrapper<F> make_named_operator(F f) {
    return {f};
}

} // namespace util

#endif // ndef UTIL_NAMED_OPERATOR_HPP

