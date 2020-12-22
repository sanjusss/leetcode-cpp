#include "103_20201222.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto root = toTreeNode(params[0]);
    auto expected = toInt2DArray(params[1]);

    Solution sln;
    auto actual = sln.zigzagLevelOrder(root);

    AREEQUAL(expected, actual);
}