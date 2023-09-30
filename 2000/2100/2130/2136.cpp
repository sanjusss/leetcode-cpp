#include "leetcode.h"

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> is(n);
        iota(is.begin(), is.end(), 0);
        sort(is.begin(), is.end(), [&growTime](int a, int b) {
            return growTime[a] > growTime[b];
        });
        int ans = 0;
        int cur = 0;
        for (int i : is) {
            cur += plantTime[i];
            ans = max(ans, cur + growTime[i]);
        }

        return ans;
    }
};