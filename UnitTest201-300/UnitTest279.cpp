#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0279.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest279)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            int n = 13;
            int expected = 2;

            Solution s;
            int actual = s.numSquares(n);
            Assert::AreEqual(expected, actual);
        }
    };
}
