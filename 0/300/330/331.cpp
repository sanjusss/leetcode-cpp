#include "leetcode.h"

// class Solution {
// public:
//     bool isValidSerialization(string preorder) {
//         if (preorder.empty()) {
//             return false;
//         }

//         stack<int> s;
//         bool hasRoot = false;
//         char prev = 0;
//         for (char i : preorder) {
//             if (i == ',') {
//                 if (prev == '#') {
//                     if (s.empty()) {
//                         return false;
//                     }
//                     else if (++s.top() == 2) {
//                         s.pop();
//                     }
//                 }
//                 else {
//                     if (hasRoot) {
//                         if (s.empty()) {
//                             return false;
//                         }
//                         else if (++s.top() == 2) {
//                             s.pop();
//                         }

//                         s.push(0);
//                     }
//                     else {
//                         hasRoot = true;
//                         s.push(0);
//                     }
//                 }
//             }

//             prev = i;
//         }

//         if (prev == '#') {
//             if (hasRoot) {
//                 return s.size() == 1 && s.top() == 1;
//             }
//             else {
//                 return s.empty();
//             }
//         }
//         else {
//             return false;
//         }
//     }
// };

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        for (int i = 0; i < preorder.size(); ++i) {
            if (slots == 0) {
                return false;
            }

            if (preorder[i] == ',') {
                continue;
            }
            else if (preorder[i] == '#') {
                --slots;
            }
            else {
                do {
                    ++i;
                } while (i < preorder.size() && preorder[i] != ',');
                --i;
                slots += -1 + 2;
            }
        }

        return slots == 0;
    }
};

TEST(&Solution::isValidSerialization)