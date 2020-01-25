#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0238.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest238)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[1,2,3,4]",
                "[24,12,8,6]");
        }

    private:
        void check(string numsSrc, string expectedSrc)
        {
            auto nums = toIntArray(numsSrc);
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            auto actual = sln.productExceptSelf(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}
