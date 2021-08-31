/*
 * @Author: sanjusss
 * @Date: 2021-08-31 10:12:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-31 13:12:48
 * @FilePath: \0\700\730\731.cpp
 */
#include "leetcode.h"

struct Node {
    int book = 0;  //范围内的预定最多的一个时间点的预定数
    int mark = 0;  //子节点需要增加的预定数量
    Node* left = nullptr;
    Node* right = nullptr;
};
Node nodes[100000];
int nodei = 0;
void reset() {
    memset(nodes, 0, sizeof(nodes));
    nodei = 0;
}
Node* newNode() {
    return &nodes[nodei++];
}

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        reset();
        root = newNode();
    }

    bool book(int start, int end) {
        int left = start;
        int right = end - 1;
        expandRoot(right);
        if (query(left, right, 0, rightEnd - 1, root) >= 2) {
            return false;
        }

        add(left, right, 0, rightEnd - 1, root);
        return true;
    }

private:
    void expandRoot(int right) {
        while (rightEnd <= right) {
            rightEnd *= 2;
            Node* node = newNode();
            node->left = root;
            root = node;
        }
    }
    //查询范围[ql,qr]内的预定最多的一个时间点的预定数
    int query(int ql, int qr, int cl, int cr, Node* node) {
        if (ql > cr || qr < cl) {
            return 0;
        }

        if (cl >= ql && cr <= qr) {
            return node->book;
        }

        pull(cl, cr, node);
        int mid = (cl + cr) / 2;
        return max(query(ql, qr, cl, mid, node->left), query(ql, qr, mid + 1, cr, node->right));
    }

    int add(int ql, int qr, int cl, int cr, Node* node) {
        if (ql > cr || qr < cl) {
            return node->book;
        }

        if (cl >= ql && cr <= qr) {
            ++node->mark;
            return ++node->book;
        }

        pull(cl, cr, node);
        int mid = (cl + cr) / 2;
        node->book = max(add(ql, qr, cl, mid, node->left), add(ql, qr, mid + 1, cr, node->right));
        return node->book;
    }

    void pull(int cl, int cr, Node* node) {
        if (cl == cr) {
            return;
        }

        pullChild(node->left, node->mark);
        pullChild(node->right, node->mark);
        node->mark = 0;
    }

    void pullChild(Node*& node, int mark) {
        if (node == nullptr) {
            node = newNode();
        }

        node->book += mark;
        node->mark += mark;
    }

private:
    int rightEnd = 1;
    Node* root = nullptr;
};

int main(int, char**) {
    MyCalendarTwo t;
    cout << t.book(89, 100) << endl;
    cout << t.book(92, 100) << endl;
    cout << t.book(78, 89) << endl;
    cout << t.book(86, 96) << endl;
    return 0;
}