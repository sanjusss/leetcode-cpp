/*
 * @Author: sanjusss
 * @Date: 2020-10-12 10:20:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-12 10:22:28
 * @FilePath: \0\500\530\test530.cpp\
 */
#include "530.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    TreeNode* root = toTreeNode(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.getMinimumDifference(root);

    testCheckEqual(expected, actual);
}