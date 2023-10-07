#include "leetcode.h"

class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
        while (!m_s.empty() && m_s.top().first <= price) {
            m_s.pop();
        }

        ++m_index;
        int ret = -1;
        if (m_s.empty()) {
            ret = m_index;
        }
        else {
            ret = m_index - m_s.top().second;
        }

        m_s.emplace(price, m_index);
        return ret;
    }

private:
    stack<pair<int, int>> m_s;
    int m_index = 0;
};
