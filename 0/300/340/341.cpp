#include "leetcode.h"

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// class NestedIterator {
// public:
//     NestedIterator(vector<NestedInteger> &nestedList) {
//         for (auto i = nestedList.rbegin(); i != nestedList.rend(); ++i) {
//             m_s.push(ref<const NestedInteger>(*i));
//         }
//     }
    
//     int next() {
//         int value = m_s.top().get().getInteger();
//         m_s.pop();
//         return value;
//     }
    
//     bool hasNext() {
//         while (!m_s.empty()) {
//             auto& l = m_s.top().get();
//             if (l.isInteger()) {
//                 return true;
//             }

//             auto& vec = l.getList();
//             m_s.pop();
//             for (auto i = vec.rbegin(); i != vec.rend(); ++i) {
//                 m_s.push(ref(*i));
//             }
//         }

//         return false;
//     }

// private:
//     stack<reference_wrapper<const NestedInteger>> m_s;
// };

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        m_s.emplace(nestedList.cbegin(), nestedList.cend());
    }
    
    int next() {
        return (m_s.top().first++)->getInteger();
    }
    
    bool hasNext() {
        while (!m_s.empty()) {
            auto& p = m_s.top();
            if (p.first == p.second) {
                m_s.pop();
            }
            else if (p.first->isInteger()) {
                return true;
            }
            else {
                auto& vec = (p.first++)->getList();
                m_s.emplace(vec.cbegin(), vec.cend());
            }
        }

        return false;
    }

private:
    stack<pair<vector<NestedInteger>::const_iterator, vector<NestedInteger>::const_iterator>> m_s;
};