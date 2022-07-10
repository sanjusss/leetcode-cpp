/*
 * @Author: sanjusss
 * @Date: 2022-07-10 10:33:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-10 10:36:54
 * @FilePath: \C\C300\C300\C301\2.cpp
 */
#include "leetcode.h"

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {

    }
    
    int popSmallest() {
        if (m_adds.empty()) {
            return m_cur++;
        }
        else {
            int res = *m_adds.begin();
            m_adds.erase(m_adds.begin());
            return res;
        }
    }
    
    void addBack(int num) {
        if (num < m_cur) {
            m_adds.insert(num);
        }
    }

private:
    set<int> m_adds;
    int m_cur = 1;
};