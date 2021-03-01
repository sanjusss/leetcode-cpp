#include "leetcode.h"

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty()) {
                if (cars[s.top()][1] >= cars[i][1]) {
                    s.pop();
                }
                else if (ans[s.top()] < 0 || ans[s.top()] * (cars[i][1] - cars[s.top()][1]) >= cars[s.top()][0] - cars[i][0]) {
                    break;
                }
                else {
                    s.pop();
                }
            }

            if (s.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = (double)(cars[s.top()][0] - cars[i][0]) / (double)(cars[i][1] - cars[s.top()][1]);
            }

            s.push(i);
        }

        return ans;
    }
};

TEST(&Solution::getCollisionTimes)