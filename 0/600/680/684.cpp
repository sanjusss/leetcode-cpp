#include "684.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto edges = toInt2DArray(params[0]);
    auto expected = toIntArray(params[1]);

    Solution sln;
    auto actual = sln.findRedundantConnection(edges);

    AREEQUAL(expected, actual);
}