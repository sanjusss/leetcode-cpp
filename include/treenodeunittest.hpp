#pragma once

#include <memory>
#include <queue>
#include <stdexcept>
#include <string>
#include <vector>

#include "treenode.h"

namespace leetcode {
inline void freeTreeNode(const TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<const TreeNode*> q({root});
    while (q.empty() == false) {
        auto node = q.front();
        if (node->left != nullptr) {
            q.push(node->left);
        }

        if (node->right != nullptr) {
            q.push(node->right);
        }

        q.pop();
        delete node;
    }
}

inline std::vector<std::shared_ptr<TreeNode>> createTreeNodeAutoRemovers(
    TreeNode* root) {
    std::vector<std::shared_ptr<TreeNode>> removers;
    if (root == nullptr) {
        return removers;
    }

    std::queue<TreeNode*> q({root});
    while (q.empty() == false) {
        auto node = q.front();
        if (node->left != nullptr) {
            q.push(node->left);
        }

        if (node->right != nullptr) {
            q.push(node->right);
        }

        q.pop();
        removers.push_back(std::shared_ptr<TreeNode>(node));
    }

    return removers;
}

inline std::wstring ToString(const TreeNode* t) {
    return L"\nuse \"TreeNode\" or \"shared_ptr<TreeNode>\" instead of "
           L"\"TreeNode*\" in Assert::areEqual or Assert::notEqual !\n";
}

inline std::wstring ToString(TreeNode* t) {
    return L"\nuse \"TreeNode\" or \"shared_ptr<TreeNode>\" instead of "
           L"\"TreeNode*\" in Assert::areEqual or Assert::notEqual !\n";
}

inline std::wstring ToString(const TreeNode& root) {
    std::queue<const TreeNode*> q({&root});
    std::wstring mid;
    while (q.empty() == false) {
        if (mid.empty() == false) {
            mid += L",";
        }

        auto node = q.front();
        if (node == nullptr) {
            mid += L"null";
        } else {
            mid += std::to_wstring(node->val);
            q.push(node->left);
            q.push(node->right);
        }

        q.pop();
    }

    return L"[" + mid + L"]";
}

inline bool operator==(const TreeNode& a, const TreeNode& b) {
    return ToString(a) == ToString(b);
}

inline bool operator!=(const TreeNode& a, const TreeNode& b) {
    return ToString(a) != ToString(b);
}

inline std::wstring ToString(const std::shared_ptr<TreeNode>& node) {
    return ToString(*node);
}

inline bool operator==(const std::shared_ptr<TreeNode>& a,
                       const std::shared_ptr<TreeNode>& b) {
    return ToString(a) == ToString(b);
}

inline bool operator!=(const std::shared_ptr<TreeNode>& a,
                       const std::shared_ptr<TreeNode>& b) {
    return ToString(a) != ToString(b);
}
}  // namespace leetcode