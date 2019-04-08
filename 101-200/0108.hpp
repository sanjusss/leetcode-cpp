#pragma once
#include "leetcode.h"

class Solution 
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }

        int mid = (end - start) / 2 + start;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, start, mid - 1);
        node->right = sortedArrayToBST(nums, mid + 1,end);
        return node;
    }
};