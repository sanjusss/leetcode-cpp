#include "1192.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    int n = stoi(params[0]);
    auto connections = toInt2DArray(params[1]);
    auto expected = toInt2DArray(params[2]);

    Solution sln;
    auto actual = sln.criticalConnections(n, connections);

    testCheckEquivalentWithPrepare(expected, actual, [](vector<vector<int>>& arr) {
        for (auto& i : arr) {
            tie(i[0], i[1]) = make_pair(min(i[0], i[1]), max(i[0], i[1]));
        }

        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            else {
                return a[0] < b[0];
            }
        });
    });
}