#include "leetcode.h"

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int> lefts;
        vector<int> rights;
        int n = nums.size();
        createAll(nums, 0, n / 2, lefts);
        createAll(nums, n / 2, n, rights);
        sort(lefts.begin(), lefts.end());
        sort(rights.rbegin(), rights.rend());
        int ans = INT_MAX;
        auto l = lefts.begin();
        auto r = rights.begin();
        while (l != lefts.end() && r != rights.end() && ans > 0) {
            ans = min(ans, abs(*l + *r - goal));
            if (*l + *r > goal) {
                ++r;
            }
            else {
                ++l;
            }
        }

        return ans;
    }

private:
    void createAll(const vector<int>& nums, int begin, int end, vector<int>& out) {
        out.reserve(1 << (end - begin));
        out.push_back(0);
        for (int i = begin; i < end; ++i) {
            for (int j = out.size() - 1; j >= 0; --j) {
                out.push_back(out[j] + nums[i]);
            }
        }
    }
};

TEST(&Solution::minAbsDifference)