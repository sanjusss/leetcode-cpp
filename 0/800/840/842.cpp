#include "842.hpp"

#include "unittest.h"

DEFINE_TESTS(params, index) {
    string S = params[0];
    auto expected = toIntArray(params[1]);

    Solution sln;
    auto actual = sln.splitIntoFibonacci(S);

    try {
        AREEQUAL(expected, actual);
    } catch (TestException&) {
        AREEQUAL(true, actual.size() >= 3);
        string conn;
        for (int i = 0; i < actual.size(); ++i) {
            conn += to_string(actual[i]);
            if (i > 1) {
                AREEQUAL((int64_t)actual[i - 2] + (int64_t)actual[i - 1], (int64_t)actual[i]);
            }
        }

        AREEQUAL(S, conn);
    }
}