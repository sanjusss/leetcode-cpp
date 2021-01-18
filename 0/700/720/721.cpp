#include "721.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto accounts = toString2DArray(params[0]);
    auto expected = toString2DArray(params[1]);

    Solution sln;
    auto actual = sln.accountsMerge(accounts);

    auto cmp = [](const vector<string>& a, const vector<string>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        else {
            return a[0] < b[0];
        }
    };
    testCheckEquivalent(expected, actual, cmp);
}