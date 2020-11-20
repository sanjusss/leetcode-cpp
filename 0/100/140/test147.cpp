#include "147.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto head = toListNode(params[0]);
    auto expected = toListNode(params[1]);

    Solution sln;
    auto actual = sln.insertionSortList(head);

    AREEQUAL(expected, actual);
}