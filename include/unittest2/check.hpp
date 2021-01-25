#pragma once
#include <string>
#include <utility>

#include "equal.hpp"
#include "fromstring.hpp"
#include "tostring.hpp"

namespace unittest {

template <class T>
inline std::pair<bool, std::string> areEqual(const T& actual, const std::string& expectedString) {
    using namespace std;
    auto expected = FromString<T>::convert(expectedString);
    if (Equal<T>::equal(expected, actual)) {
        return { true, string() };
    }
    else {
        return { false, "Not equal, expected: \"" + ToString<T>::convert(expected) + "\", actual: \"" +
                            ToString<T>::convert(actual) + "\"." };
    }
}

}  // namespace unittest