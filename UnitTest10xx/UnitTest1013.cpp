#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../10xx/1013.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest10xx
{
    TEST_CLASS(UnitTest1013)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            check("[0,2,1,-6,6,-7,9,1,2,0,1]", true);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[0,2,1,-6,6,7,9,-1,2,0,1]", false);
        }

        TEST_METHOD(TestMethod3)
        {
            check("[3,3,6,5,-2,2,5,1,-9,4]", true);
        }

        void check(string ASrc, bool expected)
        {
            auto A = toIntArray(ASrc);
            Solution sln;
            auto actual = sln.canThreePartsEqualSum(A);
            Assert::AreEqual(expected, actual);
        }
    };
}
