#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5390.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC185
{
    TEST_CLASS(UnitTest5390)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("croakcroak"
                , 1);
        }

        TEST_METHOD(TestMethod2)
        {
            check("crcoakroak"
                , 2);
        }

        TEST_METHOD(TestMethod3)
        {
            check("croakcrook"
                , -1);
        }

        TEST_METHOD(TestMethod4)
        {
            check("croakcroa"
                , -1);
        }

        void check(string croakOfFrogs, int expected)
        {
            Solution sln;
            auto actual = sln.minNumberOfFrogs(croakOfFrogs);
            Assert::AreEqual(expected, actual);
        }
    };
}