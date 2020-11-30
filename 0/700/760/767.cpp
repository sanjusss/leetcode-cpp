#include "767.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    string S = params[0];
    string expected = params[1];

    Solution sln;
    string actual = sln.reorganizeString(S);

    AREEQUIVALENT(expected, actual);
    char prev = 0;
    for (char i : actual) {
        if (i == prev) {
            throw new TestException("Same char");
        }

        prev = i;
    }
}