#include "pch.h"
#include "CppUnitTest.h"
#include "../601-700/0632.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest601700 {
    TEST_CLASS(UnitTest632) {
    public:

        TEST_METHOD(TestMethod1) {
            check("[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]",
                "[20,24]");
        }

        void check(string numsSrc, string expectedSrc) {
            auto nums = toInt2DArray(numsSrc);
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            auto actual = sln.smallestRange(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}
