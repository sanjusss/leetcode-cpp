#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5298.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5298)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[\"SEND\",\"MORE\"]",
                "MONEY",
                true);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[\"SIX\",\"SEVEN\",\"SEVEN\"]",
                "TWENTY",
                true);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[\"THIS\",\"IS\",\"TOO\"]",
                "FUNNY",
                true);
        }

        TEST_METHOD(TestMethod4)
        {
            check("[\"LEET\",\"CODE\"]",
                "POINT",
                false);
        }

        TEST_METHOD(TestMethod5)
        {
            check("[\"BUT\",\"ITS\",\"STILL\"]",
                "FUNNY",
                true);
        }

        TEST_METHOD(TestMethod6)
        {
            check("[\"TO\",\"BE\",\"OR\",\"NOT\"]",
                "TOBE",
                false);
        }

        void check(string wordsSrc, string result, bool expected)
        {
            vector<string> words = toStringArray(wordsSrc);
            Solution sln;
            auto actual = sln.isSolvable(words, result);
            Assert::AreEqual(expected, actual);
        }
    };
}