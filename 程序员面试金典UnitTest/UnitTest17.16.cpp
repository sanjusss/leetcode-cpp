#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../����Ա���Խ��/17.16.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ����Ա���Խ��UnitTest17
{
    TEST_CLASS(����Ա���Խ��UnitTest17_16)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[1,2,3,1]",
                4);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[2,7,9,3,1]",
                12);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[2,1,4,5,3,1,1,3]",
                12);
        }

        void check(string numsSrc,  int expected)
        {
            auto nums = toIntArray(numsSrc);
            Solution sln;
            auto actual = sln.massage(nums);
            Assert::AreEqual(expected, actual);
        }
    };
}
