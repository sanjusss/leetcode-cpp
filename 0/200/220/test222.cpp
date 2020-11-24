#include "222.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto root = toTreeNode(params[0]);
    int expected = stoi(params[1]);

    Solution sln;
    int actual = sln.countNodes(root);

    AREEQUAL(expected, actual);
}
