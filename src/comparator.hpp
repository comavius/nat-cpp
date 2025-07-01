#pragma once
#include <concepts>
#include "nat.hpp"
#include "rel.hpp"

template <typename T>
struct EqualImpl {
    static constexpr bool value =
        Nat<typename T::LeftType> &&
        Nat<typename T::RightType> &&
        (
            (
                std::same_as<typename T::LeftType, Zero>
                && std::same_as<typename T::RightType, Zero>
            ) 
            || EqualImpl<BinaryRel<
                 typename T::LeftType::Prev,
                 typename T::RightType::Prev
            >>::value
        );
};

template <typename T>
concept Equal = EqualImpl<T>::value;

template <typename T>
struct GreaterImpl {
    static constexpr bool value =
        Nat<typename T::LeftType> &&
        Nat<typename T::RightType> &&
        (
            (
                !std::same_as<typename T::LeftType, Zero>
                && std::same_as<typename T::RightType, Zero>
            )
            || GreaterImpl<BinaryRel<
                 typename T::LeftType::Prev,
                 typename T::RightType::Prev
            >>::value
        );
};

template <typename T>
concept Greater = GreaterImpl<T>::value;
