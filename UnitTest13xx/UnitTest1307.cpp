#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../13xx/1307.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest13xx
{
    TEST_CLASS(UnitTest1307)
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

        void check(string wordsSrc, string result, bool expected)
        {
            auto words = toStringArray(wordsSrc);
            Solution sln;
            auto actual = sln.isSolvable(words, result);
            Assert::AreEqual(expected, actual);
        }
    };
}
