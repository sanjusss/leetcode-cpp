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
    auto [expected, handler] = FromString<T>::convert(expectedString);
    if (Equal<T>::equal(expected, actual)) {
        return { true, string(), handler };
    }
    else {
        return { false,
                 "Not equal, expected: \"" + expectedString + "\", actual: \"" + ToString<T>::convert(actual) + "\".",
                 handler };
    }
}

template <class T, class Pre>
inline std::tuple<bool, std::string, unittest::FreeHandler> areEquivalent(T& actual, const std::string& expectedString,
                                                                          Pre prepare) {
    using namespace std;
    string actualString = ToString<T>::convert(actual);
    auto [expected, handler] = FromString<T>::convert(expectedString);
    prepare(actual);
    prepare(expected);
    if (Equal<T>::equal(expected, actual)) {
        return { true, string(), handler };
    }
    else {
        return { false, "Not equivalent, expected: \"" + expectedString + "\", actual: \"" + actualString + "\".",
                 handler };
    }
}

template <class T>
inline std::tuple<bool, std::string, unittest::FreeHandler> areEquivalentDefault(T& actual,
                                                                                 const std::string& expectedString) {
    return areEquivalent(actual, expectedString, [](T& arr) { std::sort(arr.begin(), arr.end()); });
}

}  // namespace unittest