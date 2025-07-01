#include <iostream>

#include "nat.hpp"
#include "comparator.hpp"
#include "int.hpp"
#include "operator.hpp"

template <Nat T, Nat U>
requires Equal<BinaryRel<T, U>>
void equal() {
    std::cout << "Equal" << std::endl;
}

template <Nat T, Nat U>
requires Greater<BinaryRel<T, U>>
void greater() {
    std::cout << "Greater" << std::endl;
}


using One = Succ<Zero>;
using Two = Succ<One>;
using Three = Succ<Two>;

// #define FAILING_EXAMPLE

int main() {
    equal<Zero, Zero>();
    equal<One, One>();
    equal<FromInt<3>, Three>();
#ifdef FAILING_EXAMPLE
    equal<FromInt<4>, Four>();
#endif
    greater<FromInt<3>, Two>();
    greater<FromInt<4>, Three>();
#ifdef FAILING_EXAMPLE
    greater<Zero, One>();
#endif
    equal<FromInt<100>, FromInt<100>>();
    equal<Add<One, One>, Two>();
    equal<FromInt<100>, Add<FromInt<50>, FromInt<50>>>();
#ifdef FAILING_EXAMPLE
    equal<FromInt<1000>, FromInt<999>>();
#endif

    std::cout << "One + One = " << to_int<Add<One, One>>() << std::endl;
    std::cout << "Two + Two = " << to_int<Add<Two, Two>>() << std::endl;
    std::cout << "Three + Three = " << to_int<Add<Three, Three>>() << std::endl;

    return 0;
}
