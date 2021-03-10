#include "leetcode.h"

// class Solution {
// public:
//     int calculate(string s) {
//         stack<char> op;
//         stack<int64_t> values;
//         auto calc = [&op, &values]() {
//             while (!op.empty() && op.top() != '(') {
//                 int64_t b = values.top();
//                 values.pop();
//                 int64_t a = values.top();
//                 values.pop();
//                 if (op.top() == '+') {
//                     values.push(a + b);
//                 }
//                 else {
//                     values.push(a - b);
//                 }

//                 op.pop();
//             }
//         };

//         char prev = 0;
//         for (char i : s) {
//             if (i == '(') {
//                 op.push(i);
//             }
//             else if (i == '+' || i == '-') {
//                 if (!isdigit(prev) && prev != ')') {
//                     values.push(0);
//                 }

//                 calc();
//                 op.push(i);
//             }
//             else if (i == ')') {
//                 calc();
//                 op.pop();
//                 calc();
//             }
//             else if (isdigit(i)) {
//                 if (isdigit(prev)) {
//                     values.top() = values.top() * 10 + i - '0';
//                 }
//                 else {
//                     values.push(i - '0');
//                 }
//             }
//             else {
//                 continue;
//             }

//             prev = i;
//         }

//         calc();
//         return values.top();
//     }
// };

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int ans = 0;
        int sign = 1;
        stack<int> ops;
        ops.push(1);
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                int num = 0;
                do {
                    num = num * 10 + (s[i++] - '0');
                } while (i < n && isdigit(s[i]));
                ans += sign * num;
                --i;
            }
            else if (s[i] == '+') {
                sign = ops.top();
            }
            else if (s[i] == '-') {
                sign = -ops.top();
            }
            else if (s[i] == '(') {
                ops.push(sign);
            }
            else if (s[i] == ')') {
                ops.pop();
            }
        }

        return ans;
    }
};

TEST(&Solution::calculate)