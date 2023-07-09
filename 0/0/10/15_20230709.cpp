#include "leetcode.h"

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         unordered_set<int> vs;
//         unordered_set<int> twice;
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         bool zero3 = false;
//         for (int i = 0; i < n; ++i) {
//             if (i > 0 && nums[i] == nums[i - 1]) {
//                 if (twice.insert(nums[i] * 2).second == false && nums[i] == 0) {
//                     zero3 = true;
//                 }

//                 continue;
//             }

//             if (twice.count(-nums[i])) {
//                 ans.push_back({ -nums[i] / 2, -nums[i] / 2, nums[i] });
//             }
//             for (int j = i + 1; j < n; ++j) {
//                 if (nums[j] == nums[j - 1] && j - 1 != i) {
//                     continue;
//                 }

//                 if (vs.count(-nums[i] - nums[j])) {
//                     ans.push_back({ -nums[i] - nums[j], nums[i], nums[j] });
//                 }
//             }

//             vs.insert(nums[i]);
//         }

//         if (zero3) {
//             ans.push_back({ 0, 0, 0 });
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];
            while (left < right) {
                int cur = nums[left] + nums[right];
                if (cur <= target) {
                    if (cur == target) {
                        ans.push_back({ nums[i], nums[left], nums[right] });
                    }

                    do {
                        ++left;
                    } while (left < right && nums[left] == nums[left - 1]);
                }
                else {
                    do {
                        --right;
                    } while (left < right && nums[right] == nums[right + 1]);
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::threeSum)