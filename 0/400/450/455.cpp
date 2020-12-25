#include "455.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto g = toIntArray(params[0]);
    auto s = toIntArray(params[1]);
    int expected = stoi(params[2]);

    Solution sln;
    int actual = sln.findContentChildren(g, s);

    AREEQUAL(expected, actual);
}