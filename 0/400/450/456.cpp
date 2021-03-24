#include "leetcode.h"

// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         int n = nums.size();
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 2; j < n; ++j) {
//                 if (nums[j] <= nums[i]) {
//                     continue;
//                 }

//                 for (int k = i + 1; k < j; ++k) {
//                     if (nums[k] > nums[j]) {
//                         return true;
//                     }
//                 }
//             }
//         }

//         return false;
//     }
// };

// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         int n = nums.size();
//         stack<int> sj;//栈顶对应值最小
//         vector<int> vi;//对应值由大到小
//         for (int k = 0; k < n; ++k) {
//             //找出最近且比当前大的数
//             while (!sj.empty() && nums[sj.top()] <= nums[k]) {
//                 sj.pop();
//             }

//             //找出最远且比当前小的数
//             auto p = upper_bound(vi.begin(), vi.end(), k, [&nums](int a, int b) {
//                 return nums[a] > nums[b];
//             });
//             if (p != vi.end() && !sj.empty() && *p < sj.top()) {
//                 return true;
//             }

//             sj.push(k);
//             if (vi.empty() || nums[vi.back()] > nums[k]) {
//                 vi.push_back(k);
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int k = INT_MIN;
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < k) {
                return true;
            }

            while (!s.empty() && s.top() < nums[i]) {
                k = max(k, s.top());
                s.pop();
            }

            s.push(nums[i]);
        }

        return false;
    }
};

TEST(&Solution::find132pattern)