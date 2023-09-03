#include "leetcode.h"

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> mins(n);
        for (int i = 0; i < n; ++i) {
            mins[i] = (dist[i] + speed[i] - 1) / speed[i];
        }

        sort(mins.begin(), mins.end());
        int ans = 0;
        for (int i : mins) {
            if (i > ans) {
                ++ans;
            }
            else {
                break;
            }
        }   

        return ans;
    }
};