#include "321.hpp"
#include "unittest.h"

DEFINE_TESTS(params, index) {
    auto nums1 = toIntArray(params[0]);
    auto nums2 = toIntArray(params[1]);
    int k = stoi(params[2]);
    auto expected = toIntArray(params[3]);

    Solution sln;
    auto actual = sln.maxNumber(nums1, nums2, k);

    AREEQUAL(expected, actual);
}