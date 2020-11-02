#include "349_20201102.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums1 = toIntArray(params[0]);
    auto nums2 = toIntArray(params[1]);
    auto expected = toIntArray(params[2]);

    Solution sln;
    auto actual = sln.intersection(nums1, nums2);

    AREEQUIVALENT(expected, actual);
}