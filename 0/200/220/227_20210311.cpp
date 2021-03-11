#include "leetcode.h"

// class Solution {
// public:
//     int calculate(string s) {
//         stack<int64_t> value;
//         stack<char> op;
//         int n = s.size();
//         for (int i = 0; i < n; ++i) {
//             if (isdigit(s[i])) {
//                 int num = 0;
//                 do {
//                     num = num * 10 + (s[i] - '0');
//                     ++i;
//                 } while (i < n && isdigit(s[i]));
//                 --i;
//                 if (!op.empty() && (op.top() == '*' || op.top() == '/')) {
//                     int64_t a = value.top();
//                     value.pop();
//                     if (op.top() == '*') {
//                         value.push(a * num);
//                     }
//                     else {
//                         value.push(a / num);
//                     }

//                     op.pop();
//                 }
//                 else {
//                     if (!op.empty() && op.top() == '-') {
//                         value.push(-num);
//                     }
//                     else {
//                         value.push(num);
//                     }
//                 }
//             }
//             else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
//                 op.push(s[i]);
//             }
//         }

//         int64_t ans = 0;
//         while (!value.empty()) {
//             ans += value.top();
//             value.pop();
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        char prevOp = '+';
        int n = 0;
        for (char i : s) {
            if (isdigit(i)) {
                n = n * 10 + (i - '0');
            }
            else if (i != ' ') {
                switch (prevOp) {
                    case '*':
                        nums.back() *= n;
                        break;

                    case '/':
                        nums.back() /= n;
                        break;

                    case '-':
                        nums.push_back(-n);
                        break;

                    case '+':
                    default:
                        nums.push_back(n);
                        break;
                }

                prevOp = i;
                n = 0;
            }
        }

        switch (prevOp) {
            case '*':
                nums.back() *= n;
                break;

            case '/':
                nums.back() /= n;
                break;

            case '-':
                nums.push_back(-n);
                break;

            case '+':
            default:
                nums.push_back(n);
                break;
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};

TEST(&Solution::calculate)