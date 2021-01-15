#include "947.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto stones = toInt2DArray(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.removeStones(stones);

    AREEQUAL(expected, actual);
}