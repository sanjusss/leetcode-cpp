#include "649.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string senate = params[0];
    string expected = params[1];

    Solution sln;
    string actual = sln.predictPartyVictory(senate);

    AREEQUAL(expected, actual);
}