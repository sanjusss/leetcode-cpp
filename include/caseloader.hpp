/*
 * @Author: sanjusss
 * @Date: 2020-10-02 18:19:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-10 08:38:20
 * @FilePath: \include\caseloader.hpp
 */
#pragma once

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

#define DEFINE_TESTS(X, Y)   \
    DEFINE_TESTS_SUITE \
    void test_function(const vector<string>& X, int Y)

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
    ss << "expected: " << expected << "(" << (expected == nullptr ? "null"s : to_string(*expected)) << ") , "
       << "actual: " << actual << "(" << (actual == nullptr ? "null"s : to_string(*actual)) << ")";
    throw TestException(ss.str());
}

template <>
void testCheckSame(ListNode* expected, ListNode* actual) {
    if (expected == actual) {
        return;
    }

    stringstream ss;
     ss << "expected: " << expected << "(" << (expected == nullptr ? "null"s : to_string(expected->val)) << ") , "
       << "actual: " << actual << "(" << (actual == nullptr ? "null"s : to_string(actual->val)) << ")";
    throw TestException(ss.str());
}

template <>
void testCheckSame(TreeNode* expected, TreeNode* actual) {
    if (expected == actual) {
        return;
    }

    stringstream ss;
     ss << "expected: " << expected << "(" << (expected == nullptr ? "null"s : to_string(expected->val)) << ") , "
       << "actual: " << actual << "(" << (actual == nullptr ? "null"s : to_string(actual->val)) << ")";
    throw TestException(ss.str());
}

void runTests(const string& codeFile) {
    vector<vector<string>> params = move(loadParams(codeFile));
    int failed = 0;
    int success = 0;
    int index = 0;
    for (auto& i : params) {
        ++index;
        try {
            test_function(i, index);
            ++success;
            cout << "Test " << index << " passed." << endl;
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