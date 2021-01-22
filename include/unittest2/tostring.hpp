#pragma once
#include <queue>
#include <string>
#include <vector>

#include "../listnode.h"
#include "../stringconvert.hpp"
#include "../testexception.hpp"
#include "../treenode.h"

/***
 * 需要转换的类型
 * int32
 * int64
 * uint32
 * uint64
 * char
 * float
 * double
 * bool
 * string
 * listnode
 * treenode
 * vector
 */
template <class T>
struct ToString {
    static std::string convert(T i) {
        return std::to_string(i);
    }
};

template <>
struct ToString<bool> {
    static std::string convert(bool i) {
        return i ? "true" : "false";
    }
};

template <>
struct ToString<std::string> {
    static std::string convert(const std::string& s) {
        return s;
    }
};

template <>
struct ToString<ListNode*> {
    static std::string convert(ListNode* head) {
        std::string res;
        res += "[";
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
};

template <>
struct ToString<TreeNode*> {
    static std::string convert(TreeNode* root) {
        std::queue<const TreeNode*> q({ root });
        std::string mid;
        while (q.empty() == false) {
            if (mid.empty() == false) {
                mid += ",";
            }

            auto node = q.front();
            if (node == nullptr) {
                mid += "null";
            }
            else {
                mid += std::to_string(node->val);
                q.push(node->left);
                q.push(node->right);
            }

            q.pop();
        }

        return "[" + mid + "]";
    }
};

template <class T>
struct ToString<std::vector<T>> {
    static std::string convert(const std::vector<T>& arr) {
        std::string res;
        res += "[";

        int max = arr.size() - 1;
        for (int i = 0; i <= max; ++i) {
            res += ToString<T>::convert(arr[i]);
            if (i != max) {
                res += ",";
            }
        }

        res += "]";
        return res;
    }
};
