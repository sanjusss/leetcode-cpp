#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0122.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200
{
    TEST_CLASS(UnitTest122)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            vector<int> input = { 8,6,4,3,3,2,3,5,8,3,8,2,6 };
            int expected = 15;
            Solution solution;
            int actual = solution.maxProfit(input);
            Assert::AreEqual(expected, actual);
        }
    };
}
