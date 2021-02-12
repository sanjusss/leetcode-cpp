#include "leetcode.h"

// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool> exist(n);
//         for (int i : nums) {
//             exist[i - 1] = true;
//         }

//         vector<int> ans;
//         for (int i = 0; i < n; ++i) {
//             if (!exist[i]) {
//                 ans.push_back(i + 1);
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> findDisappearedNumbers(vector<int>& nums) {
//         int n = nums.size();
//         for (int& i : nums) {
//             while (nums[i - 1] != i) {
//                 swap(nums[i - 1], i);
//             }
//         }

//         vector<int> ans;
//         for (int i = 0; i < n; ++i) {
//             if (nums[i] != i + 1) {
//                 ans.push_back(i + 1);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i : nums) {
            nums[(i - 1) % n ] += n;
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= n) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};

TEST_EQUIVALENT(&Solution::findDisappearedNumbers)