#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5310.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5310)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("CAKE",
                3);
        }

        TEST_METHOD(TestMethod2)
        {
            check("HAPPY",
                6);
        }

        TEST_METHOD(TestMethod3)
        {
            check("NEW",
                3);
        }

        TEST_METHOD(TestMethod4)
        {
            check("YEAR",
                7);
        }

        void check(string word, int expected)
        {
            Solution sln;
            auto actual = sln.minimumDistance(word);
            Assert::AreEqual(expected, actual);
        }
    };
}