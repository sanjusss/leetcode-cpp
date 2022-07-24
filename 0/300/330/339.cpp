/*
 * @Author: sanjusss
 * @Date: 2022-07-08 09:05:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-08 09:27:57
 * @FilePath: \0\300\330\339.cpp
 */
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
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    int depthSum(vector<NestedInteger> &nestedList) {
        int ans = 0;
        queue<const NestedInteger *> q;
        for (auto &node : nestedList) {
            q.push(&node);
        }

        for (int depth = 1; !q.empty(); ++depth) {
            for (int i = q.size(); i > 0; --i) {
                auto node = q.front();
                q.pop();
                if (node->isInteger()) {
                    ans += depth * node->getInteger();
                }
                else {
                    for (auto& next : node->getList()) {
                        q.push(&next);
                    }
                }
            }
        }

        return ans;
    }
};