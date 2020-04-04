#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0042.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest42)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[0,1,0,2,1,0,1,3,2,1,2,1]",
                6);
        }

    private:
        void check(string heightSrc, int expected)
        {
            auto height = toIntArray(heightSrc);
            Solution sln;
            auto actual = sln.trap(height);
            Assert::AreEqual(expected, actual);
        }
    };
}
