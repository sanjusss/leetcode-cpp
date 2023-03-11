#include "leetcode.h"

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        unordered_map<int, int> pre;
        pre[0] = 0;
        int diff = 0;
        int start = 0;
        int end = 0;
        for (int i = 0; i < n; ++i) {
            if (array[i][0] >= '0' && array[i][0] <= '9') {
                ++diff;
            }
            else {
                --diff;
            }
            
            if (pre.count(diff)) {
                int p = pre[diff];
                if (i + 1 - p > end - start) {
                    start = p;
                    end = i + 1;
                }
            }
            else {
                pre[diff] = i + 1;
            }
        }

        return { array.begin() + start, array.begin() + end };
    }
};