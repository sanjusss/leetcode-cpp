/*
 * @Author: sanjusss
 * @Date: 2022-07-26 13:10:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-26 13:56:03
 * @FilePath: \1000\1200\1200\1206.cpp
 */
#include "leetcode.h"

class Skiplist {
    struct Node {
        int val;
        vector<Node*> nexts;
    };
public:
    Skiplist() {
        m_head = new Node();
        m_head->val = INT_MIN;
        m_tail = new Node();
        m_tail->val = INT_MAX;
        m_head->nexts.resize(sc_maxLevel, m_tail);
        m_tail->nexts.resize(sc_maxLevel);
    }
    
    bool search(int target) {
        Node* cur = m_head;
        for (int i = sc_maxLevel - 1; i >= 0; --i) {
            while (cur->nexts[i]->val < target) {
                cur = cur->nexts[i];
            }

            if (cur->nexts[i]->val == target) {
                return true;
            }
        }

        return false;
    }
    
    void add(int num) {
        int lv = randomLevel();
        Node* node = new Node();
        node->val = num;
        node->nexts.resize(lv);
        Node* cur = m_head;
        for (int i = sc_maxLevel - 1; i >= 0; --i) {
            while (cur->nexts[i]->val < num) {
                cur = cur->nexts[i];
            }

            if (i < lv) {
                node->nexts[i] = cur->nexts[i];
                cur->nexts[i] = node;
            }
        }
    }
    
    bool erase(int num) {
        Node* cur = m_head;
        bool found = false;
        for (int i = sc_maxLevel - 1; i >= 0; --i) {
            while (cur->nexts[i]->val < num) {
                cur = cur->nexts[i];
            }

            if (cur->nexts[i]->val == num) {
                cur->nexts[i] = cur->nexts[i]->nexts[i];
                found = true;
            }
        }

        return found;
    }

private:
    static int randomLevel() {
        static constexpr int sc_factor = 4;
        static constexpr int sc_lvup = 1000;
        static constexpr int sc_lvmod = sc_factor * sc_lvup;
        int lv = 1;
        while (lv < sc_maxLevel && (rand() % sc_lvmod) < sc_lvup) {
            ++lv;
        }

        return lv;
    }

private:
    static constexpr int sc_maxLevel = 32;
    Node* m_head = nullptr;
    Node* m_tail = nullptr;;
};