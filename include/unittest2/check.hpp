#pragma once
#include <string>
#include <tuple>

#include "equal.hpp"
#include "fromstring.hpp"
#include "tostring.hpp"

namespace unittest {

template <class T>
inline std::tuple<bool, std::string, unittest::FreeHandler> areEqual(const T& actual,
                                                                     const std::string& expectedString) {
    using namespace std;
    auto p = FromString<T>::convert(expectedString);
    if (Equal<T>::equal(std::get<0>(p), actual)) {
        return { true, string(), std::get<1>(p) };
    }
    else {
        return { false,
                 "Not equal, expected: \"" + ToString<T>::convert(std::get<0>(p)) + "\", actual: \"" +
                     ToString<T>::convert(actual) + "\".",
                 std::get<1>(p) };
    }
}

}  // namespace unittest