#include "925.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string name = params[0];
    string typed = params[1];
    bool expected = stob(params[2]);

    Solution sln;
    bool actual = sln.isLongPressedName(name, typed);

    AREEQUAL(expected, actual);
}