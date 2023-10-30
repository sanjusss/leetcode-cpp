#include "leetcode.h"

class LockingTree {
public:
    LockingTree(vector<int>& parent) : m_count(parent.size()), m_parent(parent), m_children(parent.size()), m_locker(parent.size()) {
        for (int i = 1; i < m_count; ++i) {
            m_children[m_parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (m_locker[num] > 0) {
            return false;
        }
        else {
            m_locker[num] = user;
            return true;
        }
    }
    
    bool unlock(int num, int user) {
        if (m_locker[num] == user) {
            m_locker[num] = 0;
            return true;
        }
        else {
            return false;
        }
    }
    
    bool upgrade(int num, int user) {
        for (int i = num; i >= 0; i = m_parent[i]) {
            if (m_locker[i] > 0) {
                return false;
            }
        }

        bool has = false;
        queue<int> q;
        q.push(num);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (m_locker[i] > 0) {
                has = true;
                m_locker[i] = 0;
            }

            for (int j : m_children[i]) {
                q.push(j);
            }
        }

        if (has) {
            m_locker[num] = user;
            return true;
        }
        else {
            return false;
        }
    }

private:
    int m_count;
    vector<int> m_parent;
    vector<vector<int>> m_children;
    vector<int> m_locker;
};