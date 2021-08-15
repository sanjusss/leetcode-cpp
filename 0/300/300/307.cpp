/*
 * @Author: sanjusss
 * @Date: 2021-08-14 10:09:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-15 15:29:28
 * @FilePath: \0\300\300\307.cpp
 */
#include "leetcode.h"

// class NumArray {
//     struct Node {
//         int left;
//         int right;
//         int mid;
//         int sum;
//         Node* parent = nullptr;
//         Node* leftChild = nullptr;
//         Node* rightChild = nullptr;
//     };

// public:
//     NumArray(vector<int>& nums) : nodes(nums.size()) {
//         root = CreateNode(nums, 0, nums.size() - 1);
//     }
    
//     void update(int index, int val) {
//         Node* node = nodes[index];
//         int diff = val - node->sum;
//         while (node != nullptr) {
//             node->sum += diff;
//             node = node->parent;
//         }
//     }
    
//     int sumRange(int left, int right) {
//         return sumRange(left, right, root);
//     }

// private:
//     Node* CreateNode(vector<int>& nums, int left, int right) {
//         Node* node = new Node { left, right, (left + right) / 2 };
//         if (left == right) {
//             node->sum = nums[left];
//             nodes[left] = node;
//             return node;
//         }

//         node->leftChild = CreateNode(nums, left, node->mid);
//         node->rightChild = CreateNode(nums, node->mid + 1, right);
//         node->leftChild->parent = node;
//         node->rightChild->parent = node;
//         node->sum = node->leftChild->sum + node->rightChild->sum;
//         return node;
//     }

//     static int sumRange(int left, int right, Node* node) {
//         if (node->left == left && node->right == right) {
//             return node->sum;
//         }
//         else if (left > node->mid) {
//             return sumRange(left, right, node->rightChild);
//         }
//         else if (right <= node->mid) {
//             return sumRange(left, right, node->leftChild);
//         }
//         else {
//             return sumRange(left, node->mid, node->leftChild) + sumRange(node->mid + 1, right, node->rightChild);
//         }
//     }

// private:
//     vector<Node*> nodes;
//     Node* root;
// };

class NumArray {
public:
    NumArray(vector<int>& nums) : n(nums.size()), tree(2 * nums.size()) {
        for (int i = 0; i < n; ++i) {
            tree[n + i] = nums[i];
        }

        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
    
    void update(int index, int val) {
        index += n;
        int diff = val - tree[index];
        while (index > 0) {
            tree[index] += diff;
            index /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        left += n; 
        right += n;
        int res = 0;
        while (left <= right) {
            if (left % 2 == 1) {
                res += tree[left++];
            }

            if (right % 2 == 0) {
                res += tree[right--];
            }

            left /= 2;
            right /= 2;
        }

        return res;
    }

private:
    int n;
    vector<int> tree;
};
