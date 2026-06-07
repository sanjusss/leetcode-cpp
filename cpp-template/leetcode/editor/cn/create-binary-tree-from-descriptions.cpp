/*
 * @lc app=leetcode.cn id=2196 lang=cpp
 * @lcpr version=30403
 *
 * [2196] 根据描述创建二叉树
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>


using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
//         unordered_map<int, vector<int>> p2c;
//         unordered_set<int> children;
//         for (auto&& des : descriptions) {
//             p2c[des[0]].push_back(des[1]);
//             p2c[des[0]].push_back(des[2]);
//             children.insert(des[1]);
//         }

//         TreeNode* root = nullptr;
//         for (auto&& [p, _] : p2c) {
//             if (children.count(p) == 0) {
//                 root = new TreeNode(p);
//                 break;
//             }
//         }

//         if (!root) {
//             return nullptr;
//         }

//         queue<TreeNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             auto node = q.front();
//             q.pop();
//             auto& c = p2c[node->val];
//             for (int i = 0; i < c.size(); i += 2) {
//                 TreeNode* n = new TreeNode(c[i]);
//                 q.push(n);
//                 if (c[i + 1]) {
//                     node->left = n;
//                 } else {
//                     node->right = n;
//                 }
//             }
//         }

//         return root;
//     }
// };
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // 由于值互不相同，可以用值来查找节点
        unordered_map<int, bool> isRoot;
        unordered_map<int, TreeNode*> v2n;
        for (auto&& des : descriptions) {
            int p = des[0];
            int c = des[1];
            bool isLeft = des[2];

            if (isRoot.count(p) == 0) {
                isRoot[p] = true;
            }

            isRoot[c] = false;
            auto& np = v2n[p];
            if (!np) {
                np = new TreeNode(p);
            }

            auto& nc = v2n[c];
            if (!nc) {
                nc = new TreeNode(c);
            }

            if (isLeft) {
                np->left = nc;
            } else {
                np->right = nc;
            }
        }

        for (auto&& [v, is] : isRoot) {
            if (is) {
                return v2n[v];
            }
        }

        return nullptr;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,1],[2,3,0],[3,4,1]]\n
// @lcpr case=end

 */
