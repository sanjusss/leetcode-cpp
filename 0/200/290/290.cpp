#include "290.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string pattern = params[0];
    string s = params[1];
    bool expected = stob(params[2]);

    Solution sln;
    bool actual = sln.wordPattern(pattern, s);

    AREEQUAL(expected, actual);
}