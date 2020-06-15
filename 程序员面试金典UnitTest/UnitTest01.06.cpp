#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../程序员面试金典/01.06.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace 程序员面试金典UnitTest01
{
    TEST_CLASS(程序员面试金典UnitTest01_06)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("aabcccccaaa",
                "a2b1c5a3");
        }

        TEST_METHOD(TestMethod2)
        {
            check("abbccd",
                "abbccd");
        }

        TEST_METHOD(TestMethod3)
        {
            check("bb",
                "bb");
        }

        void check(string S, string expected)
        {
            Solution sln;
            auto actual = sln.compressString(S);
            Assert::AreEqual(expected, actual);
        }
    };
}
