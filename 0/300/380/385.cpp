/*
 * @Author: sanjusss
 * @Date: 2022-04-15 08:49:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-15 09:11:15
 * @FilePath: \0\300\380\385.cpp
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
    NestedInteger deserialize(string s) {
        int n = s.size();
        function<int(int, NestedInteger&)> dfs = [&](int i, NestedInteger& node) -> int {
            if (i == n) {
                return i;
            }
            else if (s[i] != '[') {
                int sign = 1;
                if (s[i] == '-') {
                    ++i;
                    sign = -1;
                }

                int val = 0;
                while (i < n && isdigit(s[i])) {
                    val *= 10;
                    val += s[i] - '0';
                    ++i;
                } 

                node.setInteger(sign * val);
                return i;
            }

            ++i;
            while (i < n) {
                if (s[i] == ']') {
                    ++i;
                    break;
                }

                if (s[i] == ',') {
                    ++i;
                }

                NestedInteger child;
                i = dfs(i, child);
                node.add(child);
            }

            return i;
        };
        NestedInteger ans;
        dfs(0, ans);
        return ans;
    }
};