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
        int val;
        int count = 0;//所有经过当前节点，且小于等于当前节点的节点数量。
        BSTNode* left = nullptr;
        BSTNode* right = nullptr;
        BSTNode(int n) : val(n) {}
        ~BSTNode()
        {
            delete left;
            delete right;
        }
    };

public:
    vector<int> countSmaller(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> ans(size);
        if (size > 0)
        {
            BSTNode* root = new BSTNode(nums.back());
            for (int i = size - 2; i >= 0; --i)
            {
                insertNode(root, new BSTNode(nums[i]), ans[i]);
            }

            delete root;
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