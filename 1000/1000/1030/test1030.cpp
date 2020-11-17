#include "1030.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    int R = stoi(params[0]);
    int C = stoi(params[1]);
    int r0 = stoi(params[2]);
    int c0 = stoi(params[3]);
    vector<vector<int>> expected = toInt2DArray(params[4]);
    Solution sln;
    auto actual = sln.allCellsDistOrder(R, C, r0, c0);
    try {
        AREEQUAL(expected, actual);
    } catch (const TestException&) {
        try {
            testCheckEquivalent(expected, actual, [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0]) {
                    return a[1] < b[1];
                }
                else {
                    return a[0] < b[0];
                }
            });
        } catch (const TestException&) {
            throw TestException("Wrong points.");
        }

        int prev = INT_MIN;
        for (auto& p : actual) {
            int cur = abs(p[0] - r0) + abs(p[1] - c0);
            if (cur < prev) {
                throw TestException("Wrong order.");
            }

            prev = cur;
        }
    }
}