#include "989.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto A = toIntArray(params[0]);
    int K = stoi(params[1]);
    auto expected = toIntArray(params[2]);

    Solution sln;
    auto actual = sln.addToArrayForm(A, K);

    AREEQUAL(expected, actual);
}