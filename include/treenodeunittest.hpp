#pragma once

#include <memory>
#include <queue>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>

#include "treenode.h"

namespace std {
inline std::string to_string(const TreeNode* t) {
    return "\nuse \"TreeNode\" or \"shared_ptr<TreeNode>\" instead of "
           "\"TreeNode*\" in Assert::areEqual or Assert::notEqual !\n";
}

inline std::string to_string(TreeNode* t) {
    return "\nuse \"TreeNode\" or \"shared_ptr<TreeNode>\" instead of "
           "\"TreeNode*\" in Assert::areEqual or Assert::notEqual !\n";
}

inline std::string to_string(const TreeNode& root) {
    std::queue<const TreeNode*> q({&root});
    std::string mid;
    while (q.empty() == false) {
        if (mid.empty() == false) {
            mid += ",";
        }

        auto node = q.front();
        if (node == nullptr) {
            mid += "null";
        } else {
            mid += std::to_string(node->val);
            q.push(node->left);
            q.push(node->right);
        }

        q.pop();
    }

    return "[" + mid + "]";
}

inline std::string to_string(const std::shared_ptr<TreeNode>& node) {
    return to_string(*node);
}

inline std::ostream& operator<<(std::ostream& os, const TreeNode& node) {
    return os << to_string(node);
}

inline std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TreeNode>& node) {
    return os << to_string(node);
}
}  // namespace std

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
}  // namespace leetcode

inline bool operator==(const TreeNode& a, const TreeNode& b) {
    return std::to_string(a) == std::to_string(b);
}

inline bool operator!=(const TreeNode& a, const TreeNode& b) {
    return std::to_string(a) != std::to_string(b);
}

inline std::string to_string(const std::shared_ptr<TreeNode>& node) {
    return std::to_string(*node);
}

inline bool operator==(const std::shared_ptr<TreeNode>& a,
                       const std::shared_ptr<TreeNode>& b) {
    return std::to_string(a) == std::to_string(b);
}

inline bool operator!=(const std::shared_ptr<TreeNode>& a,
                       const std::shared_ptr<TreeNode>& b) {
    return std::to_string(a) != std::to_string(b);
}