#include "leetcode.h"

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int64_t ans = 0;
        deque<int> qMin;
        deque<int> qMax;
        int n = nums.size();
        for (int left = 0, right = 0; left < n; ++left) {
            while (right < n) {
                if (qMin.empty() == false && abs(nums[right] - qMin.front()) > 2) {
                    break;
                }

                if (qMax.empty() == false && abs(nums[right] - qMax.front()) > 2) {
                    break;
                }

                while (qMin.empty() == false && qMin.back() > nums[right]) {
                    qMin.pop_back();
                }

                qMin.push_back(nums[right]);

                while (qMax.empty() == false && qMax.back() < nums[right]) {
                    qMax.pop_back();
                }

                qMax.push_back(nums[right]);

                ++right;
            }

            ans += right - left;
            if (qMin.empty() == false && qMin.front() == nums[left]) {
                qMin.pop_front();
            }

            if (qMax.empty() == false && qMax.front() == nums[left]) {
                qMax.pop_front();
            }
        }

        return ans;
    }
};