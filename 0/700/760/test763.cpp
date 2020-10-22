#include "763.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string S = params[0];
    auto expected = toIntArray(params[1]);

    Solution sln;
    auto actual = sln.partitionLabels(S);

    AREEQUAL(expected, actual);
}