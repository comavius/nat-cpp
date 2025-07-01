#include "nat.hpp"

template <Nat L, Nat R>
struct AddImpl;

template <Nat R>
struct AddImpl<Zero, R> {
    using type = R;
};

template <Nat L, Nat R>
struct AddImpl {
    using type = AddImpl<typename L::Prev, Succ<R>>::type;
};

template <Nat L, Nat R>
using Add = typename AddImpl<L, R>::type;