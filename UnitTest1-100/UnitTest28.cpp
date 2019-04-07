#include "pch.h"
#include "CppUnitTest.h"
#include "../1-100/0028.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1100
{
	TEST_CLASS(UnitTest28)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            string h = "a";
            string n = "a";
            int expected = 0;
            Solution s;
            int actual = s.strStr(h, n);
            Assert::AreEqual(expected, actual);
		}
	};
}
