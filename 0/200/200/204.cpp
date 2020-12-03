#include "204_20201203.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    int n = stoi(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.countPrimes(n);

    AREEQUAL(expected, actual);
}