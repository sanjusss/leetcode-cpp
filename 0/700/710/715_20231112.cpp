#include "leetcode.h"

class RangeModule {
public:
    RangeModule() {
    }

    void addRange(int left, int right) {
        auto p = m_r.upper_bound(right);
        while (p != m_r.begin()) {
            p = prev(p);
            if (left <= p->second) {
                left = min(left, p->first);
                right = max(right, p->second);
                p = m_r.erase(p);
            }
            else {
                break;
            }
        }

        m_r[left] = right;
    }

    bool queryRange(int left, int right) {
        auto p = m_r.lower_bound(right);
        if (p == m_r.begin()) {
            return false;
        }

        p = prev(p);
        return p->first <= left && p->second >= right;
    }

    void removeRange(int left, int right) {
        auto p = m_r.lower_bound(right);
        while (p != m_r.begin()) {
            p = prev(p);
            if (p->second <= left) {
                break;
            }

            if (p->second > right) {
                m_r[right] = p->second;
            }
            
            if (p->first >= left) {
                p = m_r.erase(p);
            }
            else {
                p->second = left;
                break;
            }
        }
    }

private:
    map<int, int> m_r;
};