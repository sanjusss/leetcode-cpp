#include "387_20201223.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string s = params[0];
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.firstUniqChar(s);

    AREEQUAL(expected, actual);
}