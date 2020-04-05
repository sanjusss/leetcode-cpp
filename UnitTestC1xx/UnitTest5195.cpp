#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5195.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC183
{
    TEST_CLASS(UnitTest5195)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(6, 3, 1);
        }

        TEST_METHOD(TestMethod2)
        {
            check(6, 1, 1);
        }

        void check(int a, int b, int c)
        {
            Solution sln;
            auto actual = sln.longestDiverseString(a, b, c);
            
        }
    };
}