#pragma once

#include <compare>

namespace pcs::math {

template <typename T>
requires std::three_way_comparable<T>
struct range {
    T min;
    T max;

    constexpr range(T min, T max) : min(min), max(max) {}
};

template <typename T>
requires std::three_way_comparable<T>
constexpr T map(T value, range<T> in_range, range<T> out_range) {
    return (value - in_range.min) * (out_range.max - out_range.min) /
        (in_range.max - in_range.min) +
        out_range.min;
}

} // namespace pcs::math
