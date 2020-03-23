#include "pch.h"
#include "CppUnitTest.h"
#include "../501-600/0557.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest501600
{
    TEST_CLASS(UnitTest557)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest("Let's take LeetCode contest", "s'teL ekat edoCteeL tsetnoc");
        }

        void doTest(string s, string expected)
        {
            Solution sln;
            auto actual = sln.reverseWords(s);
            Assert::AreEqual(expected, actual);
        }
    };
}
