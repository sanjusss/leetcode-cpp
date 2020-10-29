#include "129.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    TreeNode* root = toTreeNode(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.sumNumbers(root);

    AREEQUAL(expected, actual);
}