#include "973.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto points = toInt2DArray(params[0]);
    int K = stoi(params[1]);
    auto expected = toInt2DArray(params[2]);

    Solution sln;
    auto actual = sln.kClosest(points, K);

    auto cmp = [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        else {
            return a[0] < b[0];
        }
    };

    testCheckEquivalent(expected, actual, cmp);
}