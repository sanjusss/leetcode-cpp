#include "pch.h"
#include "CppUnitTest.h"
#include "../401-500/0415.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest401500
{
	TEST_CLASS(UnitTest0415)
	{
	public:

        TEST_METHOD(TestMethod1)
        {
            check("205", "3699", "3904");
        }

        void check(string num1, string num2, string expected)
        {
            Solution sln;
            auto actual = sln.addStrings(num1, num2);
            Assert::AreEqual(expected, actual);
        }
	};
}
