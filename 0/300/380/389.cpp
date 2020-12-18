#include "389.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string s = params[0];
    string t = params[1];
    char expected = params[2][0];

    Solution sln;
    char actual = sln.findTheDifference(s, t);

    AREEQUAL(expected, actual);
}