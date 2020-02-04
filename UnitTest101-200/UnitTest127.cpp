#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0127.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest0127)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("hit",
                "cog",
                "[\"hot\",\"dot\",\"dog\",\"lot\",\"log\",\"cog\"]",
                5);
        }

        TEST_METHOD(TestMethod2)
        {
            check("hit",
                "cog",
                "[\"hot\",\"dot\",\"dog\",\"lot\",\"log\"]",
                0);
        }

        void check(string beginWord, string endWord, string wordListSrc, int expected)
        {
            auto wordList = toStringArray(wordListSrc);
            Solution sln;
            auto actual = sln.ladderLength(beginWord, endWord, wordList);
            Assert::AreEqual(expected, actual);
        }
    };
}