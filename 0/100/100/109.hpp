#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    TreeNode* sortedListToBST(ListNode* head) {
//        if (head == nullptr) {
//            return nullptr;
//        }
//
//        vector<TreeNode*> nodes;
//        while (head != nullptr) {
//            nodes.push_back(new TreeNode(head->val));
//            head = head->next;
//        }
//
//        return createBST(nodes, 0, nodes.size() - 1);
//    }
//
//private:
//    TreeNode* createBST(vector<TreeNode*>& nodes, int left, int right) {
//        if (left > right) {
//            return nullptr;
//        }
//
//        int mid = (left + right) / 2;
//        nodes[mid]->left = createBST(nodes, left, mid - 1);
//        nodes[mid]->right = createBST(nodes, mid + 1, right);
//        return nodes[mid];
//    }
//};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        auto cur = head;
        int count = 0;
        while (cur != nullptr) {
            cur = cur->next;
            ++count;
        }

        return createBST(head, 1, count);
    }

private:
    TreeNode* createBST(ListNode*& head, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = (left + right) / 2;
        TreeNode* leftNode = createBST(head, left, mid - 1);
        TreeNode* node = new TreeNode(head->val);
        head = head->next;
        node->left = leftNode;
        node->right = createBST(head, mid + 1, right);
        return node;
    }
};