#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0126.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest0126)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("hit",
                "cog",
                "[\"hot\",\"dot\",\"dog\",\"lot\",\"log\",\"cog\"]",
                "[[\"hit\",\"hot\",\"dot\",\"dog\",\"cog\"],[\"hit\",\"hot\",\"lot\",\"log\",\"cog\"]]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("hit",
                "cog",
                "[\"hot\",\"dot\",\"dog\",\"lot\",\"log\"]",
                "[]");
        }

        void check(string beginWord, string endWord, string wordListSrc, string expectedSrc)
        {
            auto wordList = toStringArray(wordListSrc);
            auto expected = toString2DArray(expectedSrc);
            _0126::Solution sln;
            auto actual = sln.findLadders(beginWord, endWord, wordList);
            auto cmpStringArray = [](const vector<string>& a, const vector<string>& b)
            {
                int size = a.size();
                for (int i = 0; i < size; ++i)
                {
                    if (a[i] != b[i])
                    {
                        return a[i] < b[i];
                    }
                }

                return false;
            };
            sort(expected.begin(), expected.end(), cmpStringArray);
            sort(actual.begin(), actual.end(), cmpStringArray);
            Assert::AreEqual(expected, actual);
        }
    };
}