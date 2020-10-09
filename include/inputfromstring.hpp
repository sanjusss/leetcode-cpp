#pragma once

#include "listnode.h"
#include "string2array.hpp"
#include "stringconvert.hpp"
#include "treenode.h"

namespace leetcode {

inline std::vector<int> toIntArray(std::string s) { return toArray<int>(s); }

inline std::vector<std::vector<int>> toInt2DArray(std::string s) {
    return to2DArray<int>(s);
}

inline std::vector<std::string> toStringArray(std::string s) {
    return toArray<std::string>(s);
}

inline std::vector<std::vector<std::string>> toString2DArray(std::string s) {
    return to2DArray<std::string>(s);
}

inline std::vector<char> toCharArray(std::string s) { return toArray<char>(s); }

inline std::vector<std::vector<char>> toChar2DArray(std::string s) {
    return to2DArray<char>(s);
}

inline ListNode* toListNode(std::vector<int>& arr,
                            std::vector<ListNode*>* nodes = nullptr) {
    std::shared_ptr<ListNode> root(new ListNode(0));
    auto head = root.get();
    for (auto i : arr) {
        head->next = new ListNode(i);
        head = head->next;

        if (nodes != nullptr) {
            nodes->push_back(head);
        }
    }

    return root->next;
}

inline ListNode* toListNode(std::string s,
                            std::vector<ListNode*>* nodes = nullptr) {
    auto arr = toIntArray(s);
    return toListNode(arr, nodes);
}

inline std::vector<ListNode*> toListNodeArray(
    std::string s, std::vector<std::vector<ListNode*>>* nodes = nullptr) {
    std::vector<ListNode*> res;
    auto arrs = toInt2DArray(s);
    for (auto& arr : arrs) {
        if (nodes == nullptr) {
            res.push_back(toListNode(arr));
        }
        else {
            std::vector<ListNode*> row;
            res.push_back(toListNode(arr, &row));
            nodes->push_back(move(row));
        }
    }

    return res;
}

inline TreeNode* toTreeNode(std::string data) {
    data = data.substr(1, data.size() - 2);
    std::vector<TreeNode*> nodes;

    std::string::size_type prev_pos = 0;
    std::string::size_type pos = 0;
    while ((pos = data.find(',', pos)) != std::string::npos) {
        std::string sub = data.substr(prev_pos, pos - prev_pos);
        ++pos;
        prev_pos = pos;
        if (sub == "null") {
            nodes.push_back(nullptr);
        } else {
            nodes.push_back(new TreeNode(stoi(sub)));
        }
    }

    std::string last = data.substr(prev_pos);
    if (last.empty() == false) {
        if (last == "null") {
            nodes.push_back(nullptr);
        } else {
            nodes.push_back(new TreeNode(stoi(last)));
        }
    }

    int prevLevelTwiceIndex = 0;
    for (int i = 1; i < nodes.size(); ++i) {
        while (nodes[prevLevelTwiceIndex / 2] == nullptr) {
            ++prevLevelTwiceIndex;
        }

        if (prevLevelTwiceIndex % 2 == 0) {
            nodes[prevLevelTwiceIndex / 2]->left = nodes[i];
        } else {
            nodes[prevLevelTwiceIndex / 2]->right = nodes[i];
        }

        ++prevLevelTwiceIndex;
    }

    return nodes.empty() ? nullptr : nodes.front();
}
}  // namespace leetcode