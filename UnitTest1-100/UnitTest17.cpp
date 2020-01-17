#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0017.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
    TEST_CLASS(UnitTest0017)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("23", 
                "[\"ad\", \"ae\", \"af\", \"bd\", \"be\", \"bf\", \"cd\", \"ce\", \"cf\"]");
        }


        void check(string digits, string expectedSrc)
        {
            auto expected = toStringArray(expectedSrc);
            Solution sln;
            auto actual = sln.letterCombinations(digits);
            sort(expected.begin(), expected.end());
            sort(actual.begin(), actual.end());
            Assert::AreEqual(expected, actual);
        }
    };
}