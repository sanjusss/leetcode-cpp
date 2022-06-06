/*
 * @Author: sanjusss
 * @Date: 2022-06-06 08:35:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-06 09:20:47
 * @FilePath: \0\700\730\732_20220606.cpp
 */
#include "leetcode.h"

struct Node {
    int start = 0;
    int end = 1;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
    int h = 0;
    int modify = 0;
};

class MyCalendarThree {
public:
    MyCalendarThree() {
    }

    int book(int start, int end) {
        initRoot(end);
        return update(start, end, m_root);
    }

private:
    void initRoot(int end) {
        while (m_root->end < end) {
            Node* node = new Node();
            node->end = m_root->end * 2;
            node->leftChild = m_root;
            node->h = m_root->h;
            m_root = node;
        }
    }

    int update(int start, int end, Node* node) {
        if (node->start >= end || node->end <= start) {
            return node->h;
        }
        else if (node->start >= start && node->end <= end) {
            ++(node->modify);
            return ++(node->h);
        }

        int left = node->start;
        int right = node->end;
        int mid = (left + right) / 2;
        if (node->leftChild == nullptr) {
            node->leftChild = new Node();
            node->leftChild->start = left;
            node->leftChild->end = mid;
        }

        if (node->rightChild == nullptr) {
            node->rightChild = new Node();
            node->rightChild->start = mid;
            node->rightChild->end = right;
        }

        node->leftChild->h += node->modify;
        node->leftChild->modify += node->modify;
        node->rightChild->h += node->modify;
        node->rightChild->modify += node->modify;
        node->modify = 0;
        
        node->h = max(node->h, update(start, end, node->leftChild));
        node->h = max(node->h, update(start, end, node->rightChild));
        return node->h;
    }

private:
    Node* m_root = new Node();
};

/**
["MyCalendarThree","book","book","book","book","book","book"]
[[],[10,20],[50,60],[10,40],[5,15],[5,10],[25,55]]
*/

int main(int, char**) {
    MyCalendarThree m;
    cout << m.book(10, 20) << endl;
    cout << m.book(50, 60) << endl;
    cout << m.book(10, 40) << endl;
    cout << m.book(5, 15) << endl;
    cout << m.book(5, 10) << endl;
    cout << m.book(25, 55) << endl;
    return 0;
}