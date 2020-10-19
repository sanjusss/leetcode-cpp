#include "844.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string S = params[0];
    string T = params[1];
    bool expected = stob(params[2]);

    Solution sln;
    bool actual = sln.backspaceCompare(S, T);

    testCheckEqual(expected, actual);
}