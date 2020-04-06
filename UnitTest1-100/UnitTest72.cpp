#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0072.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest72)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("horse", "ros", 3);
        }

        TEST_METHOD(TestMethod2)
        {
            check("intention", "execution", 5);
        }

    private:
        void check(string word1, string word2, int expected)
        {
            Solution sln;
            auto actual = sln.minDistance(word1, word2);
            Assert::AreEqual(expected, actual);
        }
    };
}
