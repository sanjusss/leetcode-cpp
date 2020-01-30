#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0004.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest4)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[1, 3]", 
                "[2]",
                2);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1, 2]",
                "[3, 4]",
                2.5);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[3]",
                "[-2, -1]",
                -1);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[1,2]",
                "[3]",
                2);
        }

        TEST_METHOD(TestMethod5)
        {
            check("[1,2,3]",
                "[4]",
                2.5);
        }

    private:
        void check(string nums1Src, string nums2Src, double expected)
        {
            auto nums1 = toIntArray(nums1Src);
            auto nums2 = toIntArray(nums2Src);
            Solution sln;
            auto actual = sln.findMedianSortedArrays(nums1, nums2);
            Assert::AreEqual(expected, actual);
        }
    };
}
