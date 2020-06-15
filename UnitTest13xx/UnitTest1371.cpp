#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../13xx/1371.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest13xx
{
    TEST_CLASS(UnitTest1371)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("eleetminicoworoep", 
                13);
        }

        TEST_METHOD(TestMethod2)
        {
            check("leetcodeisgreat", 
                5);
        }

        TEST_METHOD(TestMethod3)
        {
            check("bcbcbc", 
                6);
        }

        void check(string s, int expected)
        {
            Solution sln;
            auto actual = sln.findTheLongestSubstring(s);
            Assert::AreEqual(expected, actual);
        }
    };
}
