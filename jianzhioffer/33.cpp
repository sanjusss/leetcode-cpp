/*
 * @Author: sanjusss
 * @Date: 2021-08-25 10:28:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-25 11:11:46
 * @FilePath: \jianzhioffer\33.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool verifyPostorder(vector<int>& postorder) {
//         function<bool(int, int, int)> split = [&](int left, int right, int end) -> bool {
//             if (left > right) {
//                 return true;
//             }
//             if (left == right) {
//                 return postorder[left] < end;
//             }

//             int i = right;
//             while (--i >= left && postorder[i] > postorder[right]);
//             return split(left, i, min(postorder[right], end)) && split(i + 1, right - 1, end);
//         };

//         return split(0, postorder.size() - 1, INT_MAX);
//     }
// };

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int nearBigger = INT_MAX;
        stack<int> s;
        for (int i = postorder.size() - 1; i >= 0; --i) {
            if (postorder[i] > nearBigger) {
                return false;
            }

            while (!s.empty() && s.top() > postorder[i]) {
                nearBigger = s.top();
                s.pop();
            }

            s.push(postorder[i]);
        }
        
        return true;
    }
};