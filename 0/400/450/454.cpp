#include "454_20201127.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto A = toIntArray(params[0]);
    auto B = toIntArray(params[1]);
    auto C = toIntArray(params[2]);
    auto D = toIntArray(params[3]);
    int expected = stoi(params[4]);

    Solution sln;
    int actual = sln.fourSumCount(A, B, C, D);

    AREEQUAL(expected, actual);
}