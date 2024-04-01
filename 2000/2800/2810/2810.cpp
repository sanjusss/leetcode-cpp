#include "leetcode.h"

// class Solution {
// public:
//     string finalString(string s) {
//         string ans;
//         for (char i : s) {
//             if (i == 'i') {
//                 reverse(ans.begin(), ans.end());
//             }
//             else {
//                 ans.push_back(i);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    string finalString(string s) {
        deque<char> ans;
        bool pushback = true;
        for (char i : s) {
            if (i == 'i') {
                pushback = !pushback;
            }
            else {
                if (pushback) {
                    ans.push_back(i);
                }
                else {
                    ans.push_front(i);
                }
            }
        }

        return pushback ? string(ans.begin(), ans.end()) : string(ans.rbegin(), ans.rend());
    }
};