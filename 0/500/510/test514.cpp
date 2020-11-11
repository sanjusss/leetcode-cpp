#include "514.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string ring = params[0];
    string key = params[1];
    int expected = stoi(params[2]);

    Solution sln;
    int actual = sln.findRotateSteps(ring, key);

    AREEQUAL(expected, actual);
}