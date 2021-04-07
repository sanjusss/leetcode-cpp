#include "leetcode.h"

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int leftMin = nums[0];
        if (leftMin == target) {
            return true;
        }

        int left = 0;
        int right = nums.size() - 1;
        while (left < right && leftMin == nums[right]) {
            --right;
        }

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return true;
            }

            if (target > leftMin) {
                if (nums[mid] >= leftMin) {
                    if (target > nums[mid]) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                else {
                    right = mid - 1;
                }
            }
            else {
                if (nums[mid] >= leftMin) {
                    left = mid + 1;
                }
                else {
                    if (target > nums[mid]) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
            }
        }

        return nums[left] == target;
    }
};

TEST(&Solution::search)