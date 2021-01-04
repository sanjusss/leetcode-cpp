#include "509_20210104.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    int n = stoi(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.fib(n);

    AREEQUAL(expected, actual);
}