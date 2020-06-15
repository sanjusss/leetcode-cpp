#include "pch.h"
#include "CppUnitTest.h"
#include "../801-900/0820.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest801900
{
    TEST_CLASS(UnitTest820)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[\"time\",\"me\",\"bell\"]",
                10);
        }

    private:
        void check(string wordsSrc, int expected)
        {
            auto words = toStringArray(wordsSrc);
            Solution sln;
            auto actual = sln.minimumLengthEncoding(words);
            Assert::AreEqual(expected, actual);
        }
    };
}
