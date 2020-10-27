#include "144_20201027.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto root = toTreeNode(params[0]);
    auto expected = toIntArray(params[1]);

    Solution sln;
    auto actual = sln.preorderTraversal(root);

    AREEQUAL(expected, actual);
}