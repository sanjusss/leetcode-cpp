#include "leetcode.h"

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int ans = 0;
        int cur = 0;
        int sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            sum += satisfaction[i];
            cur += sum;
            ans = max(ans, cur);
        }

        return ans;
    }
};