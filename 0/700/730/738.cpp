#include "738.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    int N = stoi(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.monotoneIncreasingDigits(N);

    AREEQUAL(expected, actual);
}