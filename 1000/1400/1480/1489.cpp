#include "1489.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    int n = stoi(params[0]);
    auto edges = toInt2DArray(params[1]);
    auto expected = toInt2DArray(params[2]);

    Solution sln;
    auto actual = sln.findCriticalAndPseudoCriticalEdges(n, edges);

    testCheckEquivalentWithPrepare(expected, actual, [](vector<vector<int>>& arr) {
        sort(arr[0].begin(), arr[0].end());
        sort(arr[1].begin(), arr[1].end());
    });
}