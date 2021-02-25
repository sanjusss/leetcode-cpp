#pragma once
#include <any>
#include <string>
#include <tuple>

#include "equal.hpp"
#include "fromstring.hpp"
#include "tostring.hpp"

namespace unittest {

template <class T>
inline std::tuple<bool, std::string, unittest::FreeHandler> areEqual(const T& actual, const std::string& expectedString,
                                                                     std::any& _) {
    using namespace std;
    auto [expected, handler] = FromString<T>::convert(expectedString);
    if (Equal<T>::equal(expected, actual)) {
        return { true, string(), handler };
    }
    else {
        return { false,
                 "Not equal, \n\t\texpected:\t\"" + expectedString + "\", \n\t\tactual:\t\t\"" +
                     ToString<T>::convert(actual) + "\".",
                 handler };
    }
}

template <class T, class Pre>
inline std::tuple<bool, std::string, unittest::FreeHandler> areEquivalent(T& actual, const std::string& expectedString,
                                                                          Pre prepare, std::any& input) {
    using namespace std;
    string actualString = ToString<T>::convert(actual);
    auto [expected, handler] = FromString<T>::convert(expectedString);
    prepare(actual, input);
    prepare(expected, input);
    if (Equal<T>::equal(expected, actual)) {
        return { true, string(), handler };
    }
    else {
        return { false,
                 "Not equivalent, \n\t\texpected:\t\"" + expectedString + "\", \n\t\tactual:\t\t\"" + actualString +
                     "\".",
                 handler };
    }
}

template <class T>
struct SortArray {
    static void sort(std::vector<T>& arr, std::any& _) {
        std::sort(arr.begin(), arr.end());
    }
};

template <>
struct SortArray<ListNode*> {
    static void sort(std::vector<ListNode*>& arr, std::any& _) {
        std::sort(arr.begin(), arr.end(), [](ListNode* a, ListNode* b) {
            return ToString<ListNode*>::convert(a) < ToString<ListNode*>::convert(b);
        });
    }
};

template <>
struct SortArray<TreeNode*> {
    static void sort(std::vector<TreeNode*>& arr, std::any& _) {
        std::sort(arr.begin(), arr.end(), [](TreeNode* a, TreeNode* b) {
            return ToString<TreeNode*>::convert(a) < ToString<TreeNode*>::convert(b);
        });
    }
};

template <class T>
struct SortArray<std::vector<T>> {
    static void sort(std::vector<std::vector<T>>& arr, std::any& _) {
        std::sort(arr.begin(), arr.end(), [](const std::vector<T>& a, const std::vector<T>& b) {
            return ToString<std::vector<T>>::convert(a) < ToString<std::vector<T>>::convert(b);
        });
    }
};

template <class T>
inline std::tuple<bool, std::string, unittest::FreeHandler> areEquivalentDefault(T& actual,
                                                                                 const std::string& expectedString,
                                                                                 std::any& input) {
    return areEquivalent(actual, expectedString, &SortArray<typename T::value_type>::sort, input);
}

template <class T, class Verify>
inline std::tuple<bool, std::string, unittest::FreeHandler> tryVerify(T& actual, const std::string& expectedString,
                                                                      Verify verify, std::any& input) {
    using namespace std;
    string actualString = ToString<T>::convert(actual);
    auto [expected, handler] = FromString<T>::convert(expectedString);
    if (verify(actual, expected, input)) {
        return { true, string(), handler };
    }
    else {
        return { false,
                 "The validation failed, \n\t\texpected:\t\"" + expectedString + "\", \n\t\tactual:\t\t\"" +
                     actualString + "\".",
                 handler };
    }
}
}  // namespace unittest