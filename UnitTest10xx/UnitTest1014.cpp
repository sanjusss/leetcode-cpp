#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../10xx/1014.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest10xx
{
    TEST_CLASS(UnitTest1014)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[8,1,5,2,6]", 
                11);
        }

        void check(string ASrc, int expected)
        {
            auto A = toIntArray(ASrc);
            Solution sln;
            auto actual = sln.maxScoreSightseeingPair(A);
            Assert::AreEqual(expected, actual);
        }
    };
}
