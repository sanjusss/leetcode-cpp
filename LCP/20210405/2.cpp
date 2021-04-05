/*
 * @Author: sanjusss
 * @Date: 2021-04-05 15:10:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-05 17:44:27
 * @FilePath: \LCP\20210405\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        int64_t circleNumber = min({ xPos, yPos, num - 1 - xPos, num - 1 - yPos });
        int64_t cur = 0;
        if (circleNumber > 0) {
            cur = (((num - 1ll) * 4ll) + ((num - 1ll - 2ll * (circleNumber - 1ll)) * 4ll)) * circleNumber / 2ll;
        }

        int64_t edge = (num - 1ll - 2ll * circleNumber);
        int64_t ans;
        if (circleNumber == xPos) {
            ans = (cur + yPos + 1ll - circleNumber);
        }
        else if (circleNumber == num - 1ll - yPos) {
            cur = cur + edge; 
            ans = (cur + xPos + 1ll - circleNumber);
        }
        else if (circleNumber == num - 1ll - xPos) {
            cur = cur + edge * 2ll; 
            ans = (cur + num - yPos - circleNumber);
        }
        else {
            cur = cur + edge * 3ll; 
            ans = (cur + num - xPos - circleNumber);
        }

        ans = ans % 9;
        if (ans == 0) {
            return 9;
        }
        else {
            return ans;
        }
    }
};

TEST(&Solution::orchestraLayout)