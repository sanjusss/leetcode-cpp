#include "860.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto bills = toIntArray(params[0]);
    bool expected = stob(params[1]);

    Solution sln;
    bool actual = sln.lemonadeChange(bills);

    AREEQUAL(expected, actual);
}