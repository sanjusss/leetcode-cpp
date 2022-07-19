#include "leetcode.h"

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger& ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const;
};

// class Solution {
// public:
//     int depthSumInverse(vector<NestedInteger>& nestedList) {
//         int depth = 0;
//         queue<const NestedInteger*> q;
//         for (auto& ni : nestedList) {
//             q.emplace(&ni);
//         }

//         while (!q.empty()) {
//             ++depth;
//             for (int i = q.size(); i > 0; --i) {
//                 auto n = q.front();
//                 q.pop();
//                 if (n->isInteger()) {
//                     continue;
//                 }

//                 for (auto& ni : n->getList()) {
//                     q.emplace(&ni);
//                 }
//             }
//         }

//         int ans = 0;
//         int maxDepth = depth;
//         depth = 0;
//         for (auto& ni : nestedList) {
//             q.emplace(&ni);
//         }

//         while (!q.empty()) {
//             ++depth;
//             for (int i = q.size(); i > 0; --i) {
//                 auto n = q.front();
//                 q.pop();
//                 if (n->isInteger()) {
//                     ans += n->getInteger() * (maxDepth - depth + 1);
//                 }
//                 else {
//                     for (auto& ni : n->getList()) {
//                         q.emplace(&ni);
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        queue<const NestedInteger*> q;
        int ans = 0;
        int rowSum = 0;
        for (auto& ni : nestedList) {
            q.emplace(&ni);
        }

        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                auto n = q.front();
                q.pop();
                if (n->isInteger()) {
                    rowSum += n->getInteger();
                }
                else {
                    for (auto& ni : n->getList()) {
                        q.emplace(&ni);
                    }
                }
            }

            ans += rowSum;
        }

        return ans;
    }
};