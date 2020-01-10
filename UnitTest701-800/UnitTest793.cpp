#include "pch.h"
#include "CppUnitTest.h"
#include "../701-800/0793.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest701800
{
    TEST_CLASS(UnitTest793)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check(0, 5);
        }

        TEST_METHOD(TestMethod2)
        {
            check(5, 0);
        }

    private:
        void check(int K, int expected)
        {
            Solution sln;
            auto actual = sln.preimageSizeFZF(K);
            Assert::AreEqual(expected, actual);
        }
    };
}
