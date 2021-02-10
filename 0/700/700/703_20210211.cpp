#include "leetcode.h"

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : m_k(k) {
        for (int i : nums) {
            add(i);
        }
    }
    
    int add(int val) {
        if (m_q.size() < m_k) {
            m_q.push(val);
        }
        else if (m_q.top() < val) {
            m_q.pop();
            m_q.push(val);
        }

        return m_q.top();
    }

private:
    int m_k;
    priority_queue<int, vector<int>, greater<int>> m_q;
};