#include "pch.h"
#include "CppUnitTest.h"
#include "../C2XX/5508.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC205 {
    TEST_CLASS(UnitTest5508) {
public:

    TEST_METHOD(TestMethod1) {
        check("[1,1]",
            "[1,1,1]",
            9);
    }

    void check(string nums1Src, string nums2Src, int expected) {
        auto nums1 = toIntArray(nums1Src);
        auto nums2 = toIntArray(nums2Src);
        Solution sln;
        auto actual = sln.numTriplets(nums1, nums2);
        Assert::AreEqual(expected, actual);
    }
    };
}