#include "pch.h"
#include "CppUnitTest.h"
#include "../601-700/0621.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest601700
{
    TEST_CLASS(UnitTest621)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[\"A\",\"A\",\"A\",\"B\",\"B\",\"B\"]",
                2,
                8);
        }

        TEST_METHOD(TestMethod2)
        {
            check("[\"A\",\"A\",\"A\",\"A\",\"A\",\"A\",\"B\",\"C\",\"D\",\"E\",\"F\",\"G\"]",
                2,
                16);
        }

        void check(string tasksSrc, int n, int expected)
        {
            auto tasks = toCharArray(tasksSrc);
            Solution sln;
            auto actual = sln.leastInterval(tasks, n);
            Assert::AreEqual(expected, actual);
        }
    };
}
