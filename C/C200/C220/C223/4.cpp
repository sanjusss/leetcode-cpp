#include "4.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto jobs = toIntArray(params[0]);
    int k = stoi(params[1]);
    int expected = stoi(params[2]);

    Solution sln;
    int actual = sln.minimumTimeRequired(jobs, k);

    AREEQUAL(expected, actual);
}