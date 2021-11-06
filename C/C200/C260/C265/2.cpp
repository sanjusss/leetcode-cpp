/*
 * @Author: sanjusss
 * @Date: 2021-10-31 10:29:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-31 10:43:02
 * @FilePath: \C\C200\C260\C265\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minD = INT_MAX;
        int maxD = INT_MIN;
        int lastPos = -1; // 上一个极点
        int beginPos = -1; // 第一个极点
        int p = 0;
        int prev = 0;
        int cur = 0;
        int next = 0;
        while (head != nullptr) {
            prev = cur;
            cur = next;
            next = head->val;
            head = head->next;
            if (prev > 0) {
                if ((prev < cur && cur > next) || (prev > cur && cur < next)) { // 发现极点
                    if (beginPos >= 0) {
                        maxD = p - beginPos;
                    }
                    else {
                        beginPos = p;
                    }

                    if (lastPos >= 0) {
                        minD = min(minD, p - lastPos);
                    }
                    
                    lastPos = p;
                }
            }

            ++p;
        }


        if (minD == INT_MAX || maxD == INT_MIN) {
            return { -1, -1 };
        }
        else {
            return { minD, maxD };
        }
    }
};