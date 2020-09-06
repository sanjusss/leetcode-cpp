#pragma once
#include "leetcode.h"

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        ans += calc(nums1, nums2);
        ans += calc(nums2, nums1);
        return ans;
    }

private:
    int calc(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int lastI = 0;
        int lastCount = 0;
        for (int i : nums1) {
            if (i == lastI) {
                ans += lastCount;
                continue;
            }

            lastCount = 0;
            lastI = i;
            int64_t target = (int64_t)i * (int64_t)i;
            int left = 0;
            int right = nums2.size() - 1;
            while (left < right) {
                int64_t tmp = (int64_t)nums2[left] * (int64_t)nums2[right];
                if (tmp == target) {
                    if (nums2[left] == nums2[right]) {
                        lastCount += (right - left + 1) * (right - left) / 2;
                        break;
                    }
                    else {
                        int leftCount = 1;
                        while (nums2[left] == nums2[left + 1]) {
                            ++leftCount;
                            ++left;
                        }
                        
                        int rightCount = 1;
                        while (nums2[right] == nums2[right - 1]) {
                            ++rightCount;
                            --right;
                        }

                        lastCount += leftCount * rightCount;
                        ++left;
                    }
                }
                else if (tmp > target) {
                    --right;
                }
                else {
                    ++left;
                }
            }

            ans += lastCount;
        }

        return ans;
    }
};