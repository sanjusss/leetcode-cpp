#include "143.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto head = toListNode(params[0]);
    auto expected = toListNode(params[1]);

    Solution sln;
    sln.reorderList(head);
    AREEQUAL(expected, head);
}