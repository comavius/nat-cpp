#include "nat.hpp"

template <Nat T>
int to_int() {
    if constexpr (std::same_as<T, Zero>) {
        return 0;
    } else {
        return 1 + to_int<typename T::Prev>();
    }
}

template <int I>
struct FromIntImpl;

template <>
struct FromIntImpl<0> {
    using type = Zero;
};

template <int I>
struct FromIntImpl {
    using type = Succ<typename FromIntImpl<I - 1>::type>;
};

template <int I>
using FromInt = typename FromIntImpl<I>::type;