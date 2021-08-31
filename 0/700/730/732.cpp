/*
 * @Author: sanjusss
 * @Date: 2021-08-31 13:13:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-31 13:26:28
 * @FilePath: \0\700\730\732.cpp
 */
#include "leetcode.h"

// struct Node {
//     int book = 0;  //范围内的预定最多的一个时间点的预定数
//     int mark = 0;  //子节点需要增加的预定数量
//     Node* left = nullptr;
//     Node* right = nullptr;
// };
// Node nodes[100000];
// int nodei = 0;
// void reset() {
//     memset(nodes, 0, sizeof(nodes));
//     nodei = 0;
// }
// Node* newNode() {
//     return &nodes[nodei++];
// }

// class MyCalendarThree {
// public:
//     MyCalendarThree() {
//         reset();
//         root = newNode();
//     }

//     int book(int start, int end) {
//         int left = start;
//         int right = end - 1;
//         expandRoot(right);
//         return add(left, right, 0, rightEnd - 1, root);;
//     }

// private:
//     void expandRoot(int right) {
//         while (rightEnd <= right) {
//             rightEnd *= 2;
//             Node* node = newNode();
//             node->left = root;
//             node->book = root->book;
//             root = node;
//         }
//     }

//     int add(int ql, int qr, int cl, int cr, Node* node) {
//         if (ql > cr || qr < cl) {
//             return node->book;
//         }

//         if (cl >= ql && cr <= qr) {
//             ++node->mark;
//             return ++node->book;
//         }

//         pull(cl, cr, node);
//         int mid = (cl + cr) / 2;
//         node->book = max(add(ql, qr, cl, mid, node->left), add(ql, qr, mid + 1, cr, node->right));
//         return node->book;
//     }

//     void pull(int cl, int cr, Node* node) {
//         if (cl == cr) {
//             return;
//         }

//         pullChild(node->left, node->mark);
//         pullChild(node->right, node->mark);
//         node->mark = 0;
//     }

//     void pullChild(Node*& node, int mark) {
//         if (node == nullptr) {
//             node = newNode();
//         }

//         node->book += mark;
//         node->mark += mark;
//     }

// private:
//     int rightEnd = 1;
//     Node* root = nullptr;
// };

class MyCalendarThree {
public:
    MyCalendarThree() {

    }
    
    int book(int start, int end) {
        int ans = 0;
        int cnt = 0;
        ++books[start];
        --books[end];
        for (auto [_, c] : books) {
            cnt += c;
            ans = max(ans, cnt);
        }

        return ans;
    }

private:
    map<int, int> books;
};

int main(int, char**) {
    MyCalendarThree t;
    cout << t.book(0,1) << endl;
    cout << t.book(0,1) << endl;
    cout << t.book(2,3) << endl;
    return 0;
}