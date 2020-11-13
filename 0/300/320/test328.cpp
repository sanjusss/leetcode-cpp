#include "328_20201113.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto head = toListNode(params[0]);
    auto expected = toListNode(params[1]);

    Solution sln;
    auto actual = sln.oddEvenList(head);

    AREEQUAL(expected, actual);
}