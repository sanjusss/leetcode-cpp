#include "leetcode.h"

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (int i : nums) {
            q.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            int v = q.top();
            q.pop();
            ans += v;
            q.push((v + 3 - 1) / 3);
        }

        return ans;
    }
};