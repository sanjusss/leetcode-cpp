/*
 * @Author: sanjusss
 * @Date: 2021-10-19 08:41:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-19 09:05:39
 * @FilePath: \0\200\210\211.cpp
 */
#include "leetcode.h"

// class WordDictionary {
//     struct Node {
//         bool end = false;
//         unordered_map<char, Node*> children;
//     };

// public:
//     WordDictionary() {
//     }

//     void addWord(string word) {
//         Node* node = &root;
//         for (char i : word) {
//             if (node->children[i] == nullptr) {
//                 node->children[i] = new Node();
//             }

//             node = node->children[i];
//         }

//         node->end = true;
//     }

//     bool search(string word) {
//         return search(word, 0, &root);
//     }

// private:
//     bool search(string_view word, int i, Node* node) {
//         while (i < word.size()) {
//             if (word[i] == '.') {
//                 for (auto [_, child] : node->children) {
//                     if (search(word, i + 1, child)) {
//                         return true;
//                     }
//                 }

//                 return false;
//             }
//             else {
//                 if (node->children.find(word[i]) != node->children.end()) {
//                     return false;
//                 }

//                 node = node->children[word[i++]];
//             }
//         }

//         return i == word.size() && node->end;
//     }

// private:
//     Node root;
// };

class WordDictionary {
    struct Node {
        bool end = false;
        Node* children[26] = { 0 };
    };

public:
    WordDictionary() {
    }

    void addWord(string word) {
        Node* node = &root;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new Node();
            }

            node = node->children[i];
        }

        node->end = true;
    }

    bool search(string word) {
        return search(word, 0, &root);
    }

private:
    bool search(string_view word, int i, Node* node) {
        while (i < word.size()) {
            if (word[i] == '.') {
                for (auto child : node->children) {
                    if (child != nullptr && search(word, i + 1, child)) {
                        return true;
                    }
                }

                return false;
            }
            else {
                int j = word[i++] - 'a';
                if (node->children[j] == nullptr) {
                    return false;
                }

                node = node->children[j];
            }
        }

        return i == word.size() && node->end;
    }

private:
    Node root;
};
