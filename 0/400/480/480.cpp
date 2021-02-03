#include "leetcode.h"

class Solution {
    class Median {
    public:
        void insert(int i) {
            if (m_small.empty() || i <= m_small.top()) {
                m_small.push(i);
                ++m_smallSize;
            }
            else {
                m_large.push(i);
                ++m_largeSize;
            }

            balance();
        }

        void erase(int i) {
            ++removes[i];            
            if (i <= m_small.top()) {
                --m_smallSize;
                if (i == m_small.top()) {
                    prune(m_small);
                }
            }
            else {
                --m_largeSize;
                if (i == m_large.top()) {
                    prune(m_large);
                }
            }

            balance();
        }

        double median() const {
            if ((m_smallSize + m_largeSize) % 2 == 0) {
                return ((double)m_small.top() + (double)m_large.top()) / 2.0;
            }
            else {
                return m_small.top();
            }
        }

    private:
        void balance() {
            if (m_smallSize > m_largeSize + 1) {
                m_large.push(m_small.top());
                m_small.pop();
                --m_smallSize;
                ++m_largeSize;
                prune(m_small);
            }
            else if (m_smallSize < m_largeSize) {
                m_small.push(m_large.top());
                m_large.pop();
                ++m_smallSize;
                --m_largeSize;
                prune(m_large);
            }
        }

        template <class T>
        void prune(T& q) {
            while (!q.empty()) {
                auto p = removes.find(q.top());
                if (p == removes.end()) {
                    break;
                }

                q.pop();
                if (--p->second == 0) {
                    removes.erase(p);
                }
            }
        }

    private:
        priority_queue<int> m_small;
        int m_smallSize = 0;
        priority_queue<int, vector<int>, greater<>> m_large;
        int m_largeSize = 0;
        unordered_map<int, int> removes;
    };

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        Median m;
        for (int i = 0; i < k; ++i) {
            m.insert(nums[i]);
        }

        int n = nums.size();
        vector<double> ans;
        ans.push_back(m.median());
        for (int i = k; i < n; ++i) {
            m.insert(nums[i]);
            m.erase(nums[i - k]);
            ans.push_back(m.median());
        }

        return ans;
    }
};

TEST(&Solution::medianSlidingWindow)