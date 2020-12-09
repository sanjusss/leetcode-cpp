#include "62.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    int m = stoi(params[0]);
    int n = stoi(params[1]);
    int expected = stoi(params[2]);

    Solution sln;
    int actual = sln.uniquePaths(m, n);

    AREEQUAL(expected, actual);
}