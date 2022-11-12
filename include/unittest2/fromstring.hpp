#pragma once
#include <memory>
#include <stack>
#include <string>
#include <vector>
#include <functional>
#include <utility>

#include "../listnode.h"
#include "../stringconvert.hpp"
#include "../testexception.hpp"
#include "../treenode.h"

namespace unittest {
    typedef std::function<void(void)> FreeHandler;

    void freeNothing() {

    }
}

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
    static std::pair<int32_t, unittest::FreeHandler> convert(const std::string& s) {
        return { std::stoi(s), unittest::freeNothing };
    }
};

template <>
struct FromString<int64_t> {
    static std::pair<int64_t, unittest::FreeHandler> convert(const std::string& s) {
        return { std::stoll(s), unittest::freeNothing };
    }
};

template <>
struct FromString<uint32_t> {
    static std::pair<uint32_t, unittest::FreeHandler> convert(const std::string& s) {
        return { std::stoul(s), unittest::freeNothing };
    }
};

template <>
struct FromString<uint64_t> {
    static std::pair<uint64_t, unittest::FreeHandler> convert(const std::string& s) {
        return { std::stoull(s), unittest::freeNothing };
    }
};

template <>
struct FromString<char> {
    static std::pair<char, unittest::FreeHandler> convert(const std::string& s) {
        return { s.front(), unittest::freeNothing };
    }
};

template <>
struct FromString<float> {
    static std::pair<float, unittest::FreeHandler> convert(const std::string& s) {
        return { std::stof(s), unittest::freeNothing };
    }
};

template <>
struct FromString<double> {
    static std::pair<double, unittest::FreeHandler> convert(const std::string& s) {
        return { std::stod(s), unittest::freeNothing };
    }
};

template <>
struct FromString<bool> {
    static std::pair<bool, unittest::FreeHandler> convert(const std::string& s) {
        return { s == "true", unittest::freeNothing };
    }
};

template <>
struct FromString<std::string> {
    static std::pair<std::string, unittest::FreeHandler> convert(const std::string& s) {
        return { s, unittest::freeNothing };
    }
};

template <class T>
struct FromString<std::vector<T>> {
    static std::pair<std::vector<T>, unittest::FreeHandler> convert(const std::string& s) {
        std::string src = s;
        leetcode::trim(src, ' ');
        if (src.front() != '[' || src.back() != ']') {
            throw TestException("\"" + s + "\" is not an array!");
        }

        src.erase(src.begin());
        src.pop_back();
        std::vector<T> res;
        std::vector<unittest::FreeHandler> handlers;
        std::string temp;
        std::stack<char> st;  //符号栈 [、"、'
        for (char i : src) {
            if (st.empty() && i == ',') {
                auto p = itemValue(temp);
                res.emplace_back(std::get<0>(p));
                handlers.emplace_back(std::get<1>(p));
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
            auto p = itemValue(temp);
            res.emplace_back(std::get<0>(p));
            handlers.emplace_back(std::get<1>(p));
        }

        unittest::FreeHandler freeArray = [handlers]() {
            for (auto& handler : handlers) {
                handler();
            }
        };
        return { res, freeArray };
    }

private:
    static std::pair<T, unittest::FreeHandler>  itemValue(std::string& s) {
        leetcode::trim(s, ' ');
        if (s.front() == '\'' || s.front() == '\"') {
            s.erase(s.begin());
        }

        if (s.back() == '\'' || s.back() == '\"') {
            s.pop_back();
        }

        auto res = FromString<T>::convert(s);
        s.clear();
        return res;
    }
};

template <>
struct FromString<ListNode*> {
    static std::pair<ListNode*, unittest::FreeHandler> convert(const std::string& s) {
        auto [nums, handler] = FromString<std::vector<int>>::convert(s);
        ListNode root(0);
        auto head = &root;
        std::vector<ListNode*> nodes;
        for (int i : nums) {
            auto node = new ListNode(i);
            nodes.push_back(node);
            head->next = node;
            head = head->next;
        }

        unittest::FreeHandler freeNodes = [nodes, h = handler]() {
            for (auto& node : nodes) {
                delete node;
            }

            h();
        };
        return { root.next, freeNodes } ;
    }
};

template <>
struct FromString<TreeNode*> {
    static std::pair<TreeNode*, unittest::FreeHandler> convert(const std::string& s) {
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

        unittest::FreeHandler freeNodes = [nodes]() {
            for (auto& node : nodes) {
                delete node;
            }
        };
        return { (nodes.empty() ? nullptr : nodes.front()), freeNodes };
    }
};