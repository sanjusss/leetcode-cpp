#pragma once
#include <queue>
#include <string>
#include <vector>

#include "../listnode.h"
#include "../treenode.h"

/***
 * 需要比较的类型
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
struct Equal {
    static bool equal(const T& a, const T& b) {
        return a == b;
    }
};

template <>
struct Equal<float> {
    static bool equal(float a, float b) {
        using namespace std;
        return a == b || (double)abs(a - b) / (double)max(abs(a), abs(b)) < 1e-6;
    }
};

template <>
struct Equal<double> {
    static bool equal(double a, double b) {
        using namespace std;
        return a == b || abs(a - b) / max(abs(a), abs(b)) < 1e-10;
    }
};

template <>
struct Equal<ListNode*> {
    static bool equal(ListNode* a, ListNode* b) {
        while (a != nullptr && b != nullptr) {
            if (a->val != b->val) {
                return false;
            }
            else {
                a = a->next;
                b = b->next;
            }
        }

        return a == nullptr && b == nullptr;
    }
};

template <>
struct Equal<TreeNode*> {
    static bool equal(TreeNode* a, TreeNode* b) {
        std::queue<TreeNode*> qa({ a });
        std::queue<TreeNode*> qb({ b });
        while (!qa.empty() && !qb.empty()) {
            a = qa.front();
            qa.pop();
            b = qb.front();
            qb.pop();

            if (a == nullptr && b == nullptr) {
                continue;
            }
            else if (a == nullptr || b == nullptr) {
                return false;
            }
            else if (a->val != b->val) {
                return false;
            }

            qa.push(a->left);
            qa.push(a->right);
            qb.push(b->left);
            qb.push(b->right);
        }

        return qa.empty() && qb.empty();
    }
};

template <class T>
struct Equal<std::vector<T>> {
    static bool equal(const std::vector<T>& a, const std::vector<T>& b) {
        if (a.size() != b.size()) {
            return false;
        }

        int n = a.size();
        for (int i = 0; i < n; ++i) {
            if (!Equal<T>::equal(a[i], b[i])) {
                return false;
            }
        }

        return true;
    }
};