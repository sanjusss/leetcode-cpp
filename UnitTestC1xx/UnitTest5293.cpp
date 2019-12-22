#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5293.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5293)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("aaaa", 1, 3, 3, 2);
        }

        TEST_METHOD(TestMethod2)
        {
            
        }

        void check(string s, int maxLetters, int minSize, int maxSize, int expected)
        {
            Solution sln;
            auto actual = sln.maxFreq(s, maxLetters, minSize, maxSize);
            Assert::AreEqual(expected, actual);
        }
    };
}