#pragma once
#include <memory>
#include <stack>
#include <string>
#include <vector>

#include "../listnode.h"
#include "../stringconvert.hpp"
#include "../testexception.hpp"
#include "../treenode.h"

/***
 * 需要转换的类型
 * 未知类型
 * int32
 * int64
 * uint32
 * uint64
 * char
 * float
 * double
 * bool
 * listnode
 * treenode
 * vector
 */
template <class T>
struct FromString;

template <>
struct FromString<int32_t> {
    static int32_t convert(const std::string& s) {
        return std::stoi(s);
    }
};

template <>
struct FromString<int64_t> {
    static int64_t convert(const std::string& s) {
        return std::stoll(s);
    }
};

template <>
struct FromString<uint32_t> {
    static uint32_t convert(const std::string& s) {
        return std::stoul(s);
    }
};

template <>
struct FromString<uint64_t> {
    static uint64_t convert(const std::string& s) {
        return std::stoull(s);
    }
};

template <>
struct FromString<char> {
    static char convert(const std::string& s) {
        return s.front();
    }
};

template <>
struct FromString<float> {
    static float convert(const std::string& s) {
        return std::stof(s);
    }
};

template <>
struct FromString<double> {
    static double convert(const std::string& s) {
        return std::stod(s);
    }
};

template <>
struct FromString<bool> {
    static bool convert(const std::string& s) {
        return s == "true";
    }
};

template <>
struct FromString<std::string> {
    static std::string convert(const std::string& s) {
        return s;
    }
};

template <class T>
struct FromString<std::vector<T>> {
    static std::vector<T> convert(const std::string& s) {
        std::string src = s;
        leetcode::trim(src, ' ');
        if (src.front() != '[' || src.back() != ']') {
            throw TestException("\"" + s + "\" is not an array!");
        }

        src.erase(src.begin());
        src.pop_back();
        std::vector<T> res;
        std::string temp;
        std::stack<char> st;  //符号栈 [、"、'
        for (char i : src) {
            if (st.empty() && i == ',') {
                res.emplace_back(itemValue(temp));
                continue;
            }

            temp.push_back(i);
            switch (i) {
                case '[':
                    st.push('[');
                    break;

                case ']':
                    if (st.empty() || st.top() != '[') {
                        throw TestException("\"" + s + "\" is an error array string!");
                    }

                    st.pop();
                    break;

                case '\'':
                case '\"':
                    if (st.empty() || st.top() != i) {
                        st.push(i);
                    }
                    else {
                        st.pop();
                    }

                    break;

                case '\\':
                    if (st.empty() || st.top() != '\\') {
                        st.push(i);
                        temp.pop_back();
                    }
                    else {
                        st.pop();
                    }

                    break;

                default:
                    break;
            }
        }

        if (!st.empty()) {
            throw TestException("\"" + s + "\" is an error array string!");
        }

        if (!temp.empty()) {
            res.emplace_back(itemValue(temp));
        }

        return std::move(res);
    }

private:
    static T itemValue(std::string& s) {
        leetcode::trim(s, ' ');
        if (s.front() == '\'' || s.front() == '\"') {
            s.erase(s.begin());
        }

        if (s.back() == '\'' || s.back() == '\"') {
            s.pop_back();
        }

        T v = FromString<T>::convert(s);
        s.clear();
        return v;
    }
};

template <>
struct FromString<ListNode*> {
    static ListNode* convert(const std::string& s) {
        auto nums = FromString<std::vector<int>>::convert(s);
        ListNode root(0);
        auto head = &root;
        for (int i : nums) {
            head->next = new ListNode(i);
            head = head->next;
        }

        return root.next;
    }
};

template <>
struct FromString<TreeNode*> {
    static TreeNode* convert(const std::string& s) {
        if (s.front() != '[' || s.back() != ']') {
            throw TestException("\"" + s + "\" is not a tree !");
        }

        auto data = s.substr(1, s.size() - 2);
        std::vector<TreeNode*> nodes;

        std::string::size_type prev_pos = 0;
        std::string::size_type pos = 0;
        while ((pos = data.find(',', pos)) != std::string::npos) {
            std::string sub = data.substr(prev_pos, pos - prev_pos);
            ++pos;
            prev_pos = pos;
            if (sub == "null") {
                nodes.push_back(nullptr);
            }
            else {
                nodes.push_back(new TreeNode(std::stoi(sub)));
            }
        }

        std::string last = data.substr(prev_pos);
        if (last.empty() == false) {
            if (last == "null") {
                nodes.push_back(nullptr);
            }
            else {
                nodes.push_back(new TreeNode(std::stoi(last)));
            }
        }

        int prevLevelTwiceIndex = 0;
        for (int i = 1; i < nodes.size(); ++i) {
            while (nodes[prevLevelTwiceIndex / 2] == nullptr) {
                ++prevLevelTwiceIndex;
            }

            if (prevLevelTwiceIndex % 2 == 0) {
                nodes[prevLevelTwiceIndex / 2]->left = nodes[i];
            }
            else {
                nodes[prevLevelTwiceIndex / 2]->right = nodes[i];
            }

            ++prevLevelTwiceIndex;
        }

        return nodes.empty() ? nullptr : nodes.front();
    }
};