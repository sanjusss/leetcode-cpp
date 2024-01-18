#include "leetcode.h"

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long sum = accumulate(beans.begin(), beans.end(), 0ll);
        long long ans = sum;
        long long pre = 0;
        int n = beans.size();
        for (int i = 0; i < n; ++i) {
            long long v = beans[i];
            long long sub = pre;
            pre += v;
            sub += sum - pre - v * (n - 1 - i);
            ans = min(ans, sub);
        }

        return ans;
    }
};