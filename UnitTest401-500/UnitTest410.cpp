#include "pch.h"
#include "CppUnitTest.h"
#include "../401-500/0410.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest401500 {
    TEST_CLASS(UnitTest410) {
public:

    TEST_METHOD(TestMethod1) {
        check("[7,2,5,10,8]",
            2,
            18);
    }

    TEST_METHOD(TestMethod2) {
        check("[1,2147483647]",
            2,
            2147483647);
    }

    void check(string numsSrc, int m, int expected) {
        auto nums = toIntArray(numsSrc);
        Solution sln;
        auto actual = sln.splitArray(nums, m);
        Assert::AreEqual(expected, actual);
    }
    };
}
