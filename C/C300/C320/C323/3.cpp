/*
 * @Author: sanjusss
 * @Date: 2022-12-11 10:19:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-11 10:59:58
 * @FilePath: \C\C300\C320\C323\3.cpp
 */
#include "leetcode.h"

class Allocator {
public:
    Allocator(int n) : m_n(n), m_len(n), m_own(n) {
        for (int i = n - 1; i >= 0; --i) {
            m_len[i] = n - i;
        }
    }
    
    int allocate(int size, int mID) {
        int res = -1;
        for (int i = 0; i < m_n; ++i) {
            if (m_len[i] >= size) {
                res = i;
                break;
            }
        }

        if (res < 0) {
            return -1;
        }

        for (int i = 0; i < size; ++i) {
            m_len[res + i] = 0;
            m_own[res + i] = mID;
        }

        return res;
    }
    
    int free(int mID) {
        int cnt = 0;
        for (int i = m_n - 1; i >= 0; --i) {
            if (m_own[i] == mID) {
                ++cnt;
                m_own[i] = 0;
                m_len[i] = 1;
            }

            if (m_len[i] > 0 && i + 1 < m_n) {
                m_len[i] = m_len[i + 1] + 1;
            }
        }

        return cnt;
    }

private:
    const int m_n;
    vector<int> m_len;
    vector<int> m_own;
};