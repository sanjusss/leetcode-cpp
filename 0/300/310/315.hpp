#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    vector<int> countSmaller(vector<int>& nums) 
//    {
//        int size = nums.size();
//        vector<int> ans(size);
//        for (int i = size - 2; i >= 0; --i)
//        {
//            for (int j = i + 1; j < size; ++j)
//            {
//                if (nums[i] > nums[j])
//                {
//                    ++ans[i];
//                }
//                else if (nums[i] == nums[j])
//                {
//                    ans[i] += ans[j];
//                    break;
//                }
//            }
//        }
//
//        return ans;
//    }
//};

//class Solution
//{
//public:
//    vector<int> countSmaller(vector<int>& nums)
//    {
//        int size = nums.size();
//        vector<int> ans(size);
//        map<int, int> rights;//value：右侧小于等于key的数字数量
//        for (int i = size - 1; i >= 0; --i)
//        {
//            auto j = rights.lower_bound(nums[i]);
//            if (j == rights.begin())
//            {
//                ans[i] = 0;
//            }
//            else
//            {
//                ans[i] = prev(j)->second;
//            }
//
//            if (j == rights.end() || j->first != nums[i])
//            {
//                rights[nums[i]] = ans[i] + 1;
//            }
//
//            for (; j != rights.end(); ++j)
//            {
//                j->second++;
//            }
//        }
//
//        return ans;
//    }
//};

class Solution
{
    struct BSTNode
    {
        int val = 0;
        int count = 0;//所有经过当前节点，且小于等于当前节点的节点数量。
        BSTNode* left = nullptr;
        BSTNode* right = nullptr;
    };

public:
    vector<int> countSmaller(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> ans(size);
        if (size > 0)
        {
            vector<BSTNode> nodes(size);
            BSTNode* root = &(nodes.back());
            root->val = nums.back();
            BSTNode* node;
            for (int i = size - 2; i >= 0; --i)
            {
                node = &(nodes[i]);
                node->val = nums[i];
                insertNode(root, node, ans[i]);
            }
        }

        return ans;
    }

private:
    void insertNode(BSTNode* node, BSTNode* target, int& ans)
    {
        if (target->val > node->val)
        {
            ans += node->count + 1;
            if (node->right == nullptr)
            {
                node->right = target;
            }
            else
            {
                insertNode(node->right, target, ans);
            }
        }
        else
        {
            ++node->count;
            if (node->left == nullptr)
            {
                node->left = target;
            }
            else
            {
                insertNode(node->left, target, ans);
            }
        }
    }
};

//class Solution {
//public:
//    vector<int> countSmaller(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> ans(n);
//        vector<int> sorting(n);
//        vector<int> temp(n);
//        for (int i = 0; i < n; ++i) {
//            sorting[i] = i;
//        }
//
//        mergeSort(0, n - 1, nums, sorting, ans, temp);
//        return ans;
//    }
//
//private:
//    void mergeSort(int left, int right, vector<int>& nums, vector<int>& sorting, vector<int>& ans, vector<int>& temp) {
//        if (left >= right) {
//            return;
//        }
//
//        int mid = (left + right) / 2;
//        mergeSort(left, mid, nums, sorting, ans, temp);
//        mergeSort(mid + 1, right, nums, sorting, ans, temp);
//        copy(sorting.begin() + left, sorting.begin() + right + 1, temp.begin() + left);
//        int i = left;
//        int j = mid + 1;
//        int cur = left;
//        while (i <= mid && j <= right) {
//            if (nums[temp[i]] > nums[temp[j]]) {
//                ans[temp[i]] += right - j + 1;
//                sorting[cur++] = temp[i++];
//            }
//            else {
//                sorting[cur++] = temp[j++];
//            }
//        }
//
//        while (i <= mid) {
//            sorting[cur++] = temp[i++];
//        }
//
//        while (j <= right) {
//            sorting[cur++] = temp[j++];
//        }
//    }
//};