#include "49_20201214.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto strs = toStringArray(params[0]);
    auto expected = toString2DArray(params[1]);

    Solution sln;
    auto actual = sln.groupAnagrams(strs);

    testCheckEquivalentWithPrepare(expected, actual, [](vector<vector<string>>& arr) {
        for (auto& i : arr) {
            sort(i.begin(), i.end());
        }

        sort(arr.begin(), arr.end(), [](const vector<string>& a, const vector<string>& b){
            if (b.empty()) {
                return false;
            }
            else if (a.empty()) {
                return true;
            }
            else {
                string a0 = a.front();
                string b0 = b.front();
                sort(a0.begin(), a0.end());
                sort(b0.begin(), b0.end());
                return a0 < b0;
            }
        });
    });
}