#pragma once

#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>

#include "listnode.h"

namespace std {
inline std::string to_string(const ListNode* t) {
    return "\nuse \"ListNode\" or \"shared_ptr<ListNode>\" instead of "
           "\"ListNode*\" in Assert::areEqual or Assert::notEqual !\n";
}

inline std::string to_string(ListNode* t) {
    return "\nuse \"ListNode\" or \"shared_ptr<ListNode>\" instead of "
           "\"ListNode*\" in Assert::areEqual or Assert::notEqual !\n";
}

inline std::string to_string(const ListNode& node) {
    std::string res;
    res += "[";

    const ListNode* head = &node;
    while (head != nullptr) {
        res += std::to_string(head->val);
        if (head->next != nullptr) {
            res += ",";
        }

        head = head->next;
    }

    res += "]";
    return res;
}

inline std::string to_string(const std::shared_ptr<ListNode>& node) { return std::to_string(*node); }

inline std::ostream& operator<<(std::ostream& os, const ListNode& node) { return os << to_string(node); }

inline std::ostream& operator<<(std::ostream& os, const std::shared_ptr<ListNode>& node) {
    return os << to_string(node);
}

}  // namespace std

namespace leetcode {
inline void freeListNode(const ListNode* head) {
    while (head != nullptr) {
        auto temp = head;
        head = head->next;
        delete temp;
    }
}

inline std::vector<std::shared_ptr<ListNode>> createListNodeAutoRemovers(ListNode* head) {
    std::vector<std::shared_ptr<ListNode>> removers;
    while (head != nullptr) {
        removers.push_back(std::shared_ptr<ListNode>(head));
        head = head->next;
    }

    return removers;
}

inline std::vector<int> toIntArray(ListNode* head) {
    std::vector<int> res;
    while (head != nullptr) {
        res.push_back(head->val);
        head = head->next;
    }

    return res;
}

inline std::vector<ListNode*> toListNodeArray(ListNode* head) {
    vector<ListNode*> nodes;
    while (head != nullptr) {
        nodes.push_back(head);
        head = head->next;
    }

    return nodes;
}
}  // namespace leetcode

inline bool operator==(const ListNode& a, const ListNode& b) { return std::to_string(a) == std::to_string(b); }

inline bool operator!=(const ListNode& a, const ListNode& b) { return std::to_string(a) != std::to_string(b); }

inline bool operator==(const std::shared_ptr<ListNode>& a, const std::shared_ptr<ListNode>& b) {
    return std::to_string(a) == std::to_string(b);
}

inline bool operator!=(const std::shared_ptr<ListNode>& a, const std::shared_ptr<ListNode>& b) {
    return std::to_string(a) != std::to_string(b);
}
