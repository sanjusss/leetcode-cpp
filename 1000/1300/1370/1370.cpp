#include "1370.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string s = params[0];
    string expected = params[1];

    Solution sln;
    string actual = sln.sortString(expected);

    AREEQUAL(expected, actual);
}