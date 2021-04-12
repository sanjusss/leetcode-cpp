#include "leetcode.h"

// class Solution {
// public:
//     string largestNumber(vector<int>& nums) {
//         vector<string> strs;
//         for (int i : nums) {
//             strs.push_back(to_string(i));
//         }

//         sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
//             return a + b > b + a;
//         });
//         string ans;
//         for (auto& i : strs) {
//             ans += i;
//         }

//         if (ans.empty() || ans.front() == '0') {
//             return "0";
//         }
//         else {
//             return ans;
//         }
//     }
// };

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            int64_t aSize = 10;
            while (aSize <= a) {
                aSize *= 10;
            }

            int64_t bSize = 10;
            while (bSize <= b) {
                bSize *= 10;
            }

            return bSize * a + b > aSize * b + a;
        });

        if (nums.front() == 0) {
            return "0";
        }

        string ans;
        for (int i : nums) {
            ans += to_string(i);
        }

        return ans;
    }
};

TEST(&Solution::largestNumber)