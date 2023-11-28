#include "leetcode.h"

// class FrontMiddleBackQueue {
// public:
//     FrontMiddleBackQueue() {

//     }
    
//     void pushFront(int val) {
//         m_nums.push_front(val);
//     }
    
//     void pushMiddle(int val) {
//         int mid = m_nums.size() / 2;
//         auto p = next(m_nums.begin(), mid);
//         m_nums.insert(p, val);
//     }
    
//     void pushBack(int val) {
//         m_nums.push_back(val);
//     }
    
//     int popFront() {
//         if (m_nums.empty()) {
//             return -1;
//         }

//         int val = m_nums.front();
//         m_nums.pop_front();
//         return val;
//     }
    
//     int popMiddle() {
//         if (m_nums.empty()) {
//             return -1;
//         }

//         int mid = (m_nums.size() - 1) / 2;
//         auto p = next(m_nums.begin(), mid);
//         int val = *p;
//         m_nums.erase(p);
//         return val;
//     }
    
//     int popBack() {
//         if (m_nums.empty()) {
//             return -1;
//         }

//         int val = m_nums.back();
//         m_nums.pop_back();
//         return val;
//     }

// private:
//     list<int> m_nums;
// };

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {

    }
    
    void pushFront(int val) {
        m_lefts.push_front(val);
        if (m_lefts.size() > m_rights.size() + 1) {
            m_rights.push_front(m_lefts.back());
            m_lefts.pop_back();
        }
    }
    
    void pushMiddle(int val) {
        if (m_lefts.size() > m_rights.size()) {
            m_rights.push_front(m_lefts.back());
            m_lefts.pop_back();
        }

        m_lefts.push_back(val);
    }
    
    void pushBack(int val) {
        m_rights.push_back(val);
        if (m_lefts.size() < m_rights.size()) {
            m_lefts.push_back(m_rights.front());
            m_rights.pop_front();
        }
    }
    
    int popFront() {
        if (m_lefts.empty()) {
            return -1;
        }

        int val = m_lefts.front();
        m_lefts.pop_front();
        if (m_lefts.size() < m_rights.size()) {
            m_lefts.push_back(m_rights.front());
            m_rights.pop_front();
        }

        return val;
    }
    
    int popMiddle() {
        if (m_lefts.empty()) {
            return -1;
        }

        int val = m_lefts.back();
        m_lefts.pop_back();
        if (m_lefts.size() < m_rights.size()) {
            m_lefts.push_back(m_rights.front());
            m_rights.pop_front();
        }

        return val;
    }
    
    int popBack() {
        if (m_rights.empty()) {
            if (m_lefts.empty()) {
                return -1;
            }
            else {
                int val = m_lefts.back();
                m_lefts.pop_back();
                return val;
            }
        }

        int val = m_rights.back();
        m_rights.pop_back();
        if (m_lefts.size() > m_rights.size() + 1) {
            m_rights.push_front(m_lefts.back());
            m_lefts.pop_back();
        }

        return val;
    }

private:
    deque<int> m_lefts;
    deque<int> m_rights;
};