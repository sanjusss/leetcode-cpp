#include "leetcode.h"

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> wins(n);
        int step = 0;
        for (int i = 0; wins[i] == false; i = (i + step) % n) {
            wins[i] = true;
            step = (step + k) % n;
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (wins[i] == false) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};