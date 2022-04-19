#include "leetcode.h"

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n);
        int dis = n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                dis = 0;
            }
            else {
                ++dis;
            }

            ans[i] = dis;
        }

        dis = n;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == c) {
                dis = 0;
            }
            else {
                ++dis;
            }

            ans[i] = min(ans[i], dis);
        }

        return ans;
    }
};