#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k);
        int start = max(0, k - (int)nums2.size());
        int end = min((int)nums1.size(), k);
        for (int i = start; i <= end; ++i) {
            auto a = maxSubArray(nums1, i);
            auto b = maxSubArray(nums2, k - i);
            auto temp = merge(a, b);
            if (greaterThan(temp, 0, ans, 0)) {
                ans = move(temp);
            }
        }

        return ans;
    }

private:
    vector<int> maxSubArray(const vector<int>& nums, int k) {
        vector<int> ans;
        int d = nums.size() - k;
        for (int i : nums) {
            while (!ans.empty() && ans.back() < i && d > 0) {
                --d;
                ans.pop_back();
            }

            ans.push_back(i);
        }

        while (d > 0) {                
            --d;
            ans.pop_back();
        }

        return ans;
    }

    vector<int> merge(const vector<int>& a, const vector<int>& b) {
        vector<int> ans;
        int ai = 0;
        int ae = a.size();
        int bi = 0;
        int be = b.size();
        while (ai < ae && bi < be) {
            if (greaterThan(a, ai, b, bi)) {
                ans.push_back(a[ai++]);
            }
            else {
                ans.push_back(b[bi++]);
            }
        }

        while (ai < ae) {
            ans.push_back(a[ai++]);
        }

        while (bi < be) {
            ans.push_back(b[bi++]);
        }

        return ans;
    }

    bool greaterThan(const vector<int>& a, int ai, const vector<int>& b, int bi) {
        int n = a.size();
        int ae = a.size();
        int be = b.size();
        while (ai < ae && bi < be) {
            if (a[ai] != b[bi]) {
                return a[ai] > b[bi];
            }

            ++ai;
            ++bi;
        }

        return ai < ae;
    }
};