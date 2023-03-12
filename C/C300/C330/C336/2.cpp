#include "leetcode.h"

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int64_t sum = 0;
        int ans = 0;
        int zero = 0;
        vector<int> ng;
        for (int i : nums) {
            if (i > 0) {
                sum += i;
                ++ans;
            }
            else if (i == 0) {
                ++zero;
            }
            else {
                ng.push_back(i);
            }
        }

        if (sum == 0) {
            return 0;
        }

        ans += zero;
        sort(ng.begin(), ng.end(), greater<int>());
        for (int i : ng) {
            sum += i;
            if (sum > 0) {
                ++ans;
            }
            else {
                break;
            }
        }

        return ans;
    }
};