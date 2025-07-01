#pragma once
#include <concepts>


struct Undefined {
    using Prev = Undefined;
};

struct Zero {
    using Prev = Undefined;
};

template <typename T>
struct Succ {
    using Prev = T;
};

template <typename T>
concept Nat = std::same_as<T, Zero> || std::same_as<T, Succ<typename T::Prev>>;
