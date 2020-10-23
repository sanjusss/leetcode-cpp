#include "234_20201023.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto head = toListNode(params[0]);
    bool expected = stob(params[1]);

    Solution sln;
    bool actual = sln.isPalindrome(head);

    AREEQUAL(expected, actual);
}