/*
 * @Author: sanjusss
 * @Date: 2022-05-26 14:16:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-26 16:55:32
 * @FilePath: \0\600\690\699_20220526.cpp
 */
#include "leetcode.h"

struct Node {
    int left = 1;
    int right = 1;
    int height = 0;       // 当前区段最高点
    bool update = false;  // 区段是否需要更新
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans;
        for (auto& pt : positions) {
            int left = pt[0];
            int height = pt[1];
            int right = left + height - 1;
            initRoot(right);
            int base = find(left, right);
            height += base;
            update(left, right, height);
            ans.push_back(m_root->height);
        }

        return ans;
    }

private:
    void initRoot(int right) {
        while (m_root->right < right) {
            Node* node = new Node();
            node->right = m_root->right * 2;
            node->height = m_root->height;
            node->leftChild = m_root;
            m_root = node;
        }
    }

    int find(int left, int right, Node* node = nullptr) {
        if (node == nullptr) {
            node = m_root;
        }

        check(node);
        if (left <= node->left && right >= node->right) {
            return node->height;
        }

        int mid = (node->left + node->right) / 2;
        int h = 0;
        if (mid >= left) {
            if (node->leftChild != nullptr) {
                h = max(h, find(max(left, node->left), min(mid, right), node->leftChild));
            }
        }

        if (mid < right) {
            if (node->rightChild != nullptr) {
                h = max(h, find(max(left, mid + 1), min(right, node->right), node->rightChild));
            }
        }
        return h;
    }

    void update(int left, int right, int height, Node* node = nullptr) {
        if (node == nullptr) {
            node = m_root;
        }

        check(node);
        node->height = max(node->height, height);
        if (left <= node->left && right >= node->right) {
            node->update = true;
            return;
        }

        int mid = (node->left + node->right) / 2;
        if (mid >= left) {
            update(max(left, node->left), min(mid, right), height, node->leftChild);
        }

        if (mid < right) {
            update(max(left, mid + 1), min(right, node->right), height, node->rightChild);
        }
    }

    void check(Node* node) {
        int mid = (node->left + node->right) / 2;
        if (node->leftChild == nullptr) {
            node->leftChild = new Node();
            node->leftChild->left = node->left;
            node->leftChild->right = mid;
        }

        if (node->rightChild == nullptr) {
            node->rightChild = new Node();
            node->rightChild->left = mid + 1;
            node->rightChild->right = node->right;
        }
        
        if (node->update == false || node->left == node->right) {
            return;
        }


        node->leftChild->update = true;
        node->leftChild->height = node->height;

        node->rightChild->update = true;
        node->rightChild->height = node->height;
        node->update = false;
    }

private:
    Node* m_root = new Node();
};

TEST(&Solution::fallingSquares)