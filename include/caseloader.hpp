/*
 * @Author: sanjusss
 * @Date: 2020-10-02 18:19:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-13 09:23:18
 * @FilePath: \include\caseloader.hpp
 */
#pragma once

#include <chrono>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "stringconvert.hpp"

using namespace std;
using namespace leetcode;

#define DEFINE_TESTS_SUITE                     \
    int main(int /*argc*/, char* /*argv*/[]) { \
        runTests(__FILE__);                    \
        return 0;                              \
    }

#define DEFINE_TESTS(X, Y) \
    DEFINE_TESTS_SUITE     \
    void test_function(const vector<string>& X, int Y)

#define AREEQUAL(x, y) testCheckEqual(x, y)
#define ARESAME(x, y) testCheckSame(x, y)
#define AREEQUIVALENT(x, y) testCheckEquivalent(x, y)

void test_function(const vector<string>& params, int index);

vector<vector<string>> loadParams(const string& codeFile) {
    auto pos = codeFile.find_last_of('.');
    string casesFile = codeFile.substr(0, pos) + ".cases";
    ifstream input(casesFile);
    string line;
    getline(input, line);
    vector<string> words = split(line, ",");
    int caseLineSize = stoi(words[0]);
    bool needTrim = words.size() < 2 || words[1] != "notrim";

    vector<vector<string>> params;
    while (input) {
        vector<string> param;
        for (int i = 0; i < caseLineSize && getline(input, line); ++i) {
            if (needTrim) {
                trim(line, '\"');
            }

            param.push_back(move(line));
        }

        if (param.size() == caseLineSize) {
            params.push_back(move(param));
        }
    }

    return params;
}

template <class T>
void testCheckEqual(const T& expected, const T& actual) {
    if (expected == actual) {
        return;
    }

    stringstream ss;
    ss << "expected: " << expected << " , "
       << "actual: " << actual;
    throw TestException(ss.str());
}

template <>
void testCheckEqual(ListNode* const& expected, ListNode* const& actual) {
    testCheckEqual(*expected, *actual);
}

template <>
void testCheckEqual(TreeNode* const& expected, TreeNode* const& actual) {
    testCheckEqual(*expected, *actual);
}

void testCheckEqual(double expected, double actual, double deviation) {
    if (abs(expected - actual) <= deviation) {
        return;
    }

    stringstream ss;
    ss << "expected: " << expected << " , "
       << "actual: " << actual;
    throw TestException(ss.str());
}

template <class T>
void testCheckSame(T* expected, T* actual) {
    if (expected == actual) {
        return;
    }

    stringstream ss;
    ss << "expected: " << expected << "("
       << (expected == nullptr ? "null"s : to_string(*expected)) << ") , "
       << "actual: " << actual << "("
       << (actual == nullptr ? "null"s : to_string(*actual)) << ")";
    throw TestException(ss.str());
}

template <>
void testCheckSame(ListNode* expected, ListNode* actual) {
    if (expected == actual) {
        return;
    }

    stringstream ss;
    ss << "expected: " << expected << "("
       << (expected == nullptr ? "null"s : to_string(expected->val)) << ") , "
       << "actual: " << actual << "("
       << (actual == nullptr ? "null"s : to_string(actual->val)) << ")";
    throw TestException(ss.str());
}

template <>
void testCheckSame(TreeNode* expected, TreeNode* actual) {
    if (expected == actual) {
        return;
    }

    stringstream ss;
    ss << "expected: " << expected << "("
       << (expected == nullptr ? "null"s : to_string(expected->val)) << ") , "
       << "actual: " << actual << "("
       << (actual == nullptr ? "null"s : to_string(actual->val)) << ")";
    throw TestException(ss.str());
}

template <class T, class W>
void testCheckEquivalent(vector<T> a, vector<T> b, W cmp) {
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    testCheckEqual(a, b);
}

template <class T>
void testCheckEquivalent(vector<T> a, vector<T> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    testCheckEqual(a, b);
}

void runTests(const string& codeFile) {
    vector<vector<string>> params = move(loadParams(codeFile));
    int failed = 0;
    int success = 0;
    int index = 0;
    for (auto& i : params) {
        ++index;
        try {
            auto begin = chrono::system_clock::now();
            test_function(i, index);
            auto end = chrono::system_clock::now();
            ++success;
            cout << "Test " << index << " passed.("
                 << chrono::duration_cast<chrono::milliseconds>(end - begin)
                        .count()
                 << " ms)" << endl;
        } catch (exception& e) {
            cout << "Test " << index << " has failed. " << e.what() << endl;
            ++failed;
        } catch (...) {
            ++failed;
        }
    }

    cout << "Totoal:" << index << ", success:" << success
         << ", failed:" << failed << endl;
}