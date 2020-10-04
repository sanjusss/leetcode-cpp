#include "771.hpp"
#include "unittest.h"

void test_function(const vector<string>& params, int index) {
    string J = params[0];
    string S = params[1];
    int expected = stoi(params[2]);
    Solution sln;
    int actual = sln.numJewelsInStones(J, S);
    testCheckEqual(expected, actual);
}

DEFINE_TESTS_SUITE