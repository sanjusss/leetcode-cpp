#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5249.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC1xx
{
    TEST_CLASS(UnitTest5249)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            string s = "))((";
            string expected = "";

            Solution sln;
            auto actual = sln.minRemoveToMakeValid(s);
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(TestMethod2)
        {
            string s = "lee(t(c)o)de)";
            string expected = "lee(t(c)o)de";

            Solution sln;
            auto actual = sln.minRemoveToMakeValid(s);
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(TestMethod3)
        {
            string s = "a)b(c)d";
            string expected = "ab(c)d";

            Solution sln;
            auto actual = sln.minRemoveToMakeValid(s);
            Assert::AreEqual(expected, actual);
        }
    };
}
