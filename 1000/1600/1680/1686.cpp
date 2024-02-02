#include "leetcode.h"

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> diff(n);
        iota(diff.begin(), diff.end(), 0);
        sort(diff.begin(), diff.end(), [&aliceValues, &bobValues](int a, int b) {
            return (aliceValues[a] + bobValues[a]) > (aliceValues[b] + bobValues[b]);
        });

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int j = diff[i];
            if (i & 1) {
                sum -= bobValues[j];
            }
            else {
                sum += aliceValues[j];
            }
        }

        if (sum > 0) {
            return 1;
        }
        else if (sum < 0) {
            return -1;
        }
        else {
            return 0;
        }
    }
};

TEST(&Solution::stoneGameVI)