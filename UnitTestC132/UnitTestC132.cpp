#include "pch.h"
#include "CppUnitTest.h"
#include "../C132/5025.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC132
{
	TEST_CLASS(UnitTestC132)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            doTest("[44,46,22,68,45,66,43,9,37,30,50,67,32,47,44,11,15,4,11,6,20,64,54,54,61,63,23,43,3,12,51,61,16,57,14,12,55,17,18,25,19,28,45,56,29,39,52,8,1,21,17,21,23,70,51,61,21,52,25,28]",
                6);
		}
        
        TEST_METHOD(TestMethod2)
        {
            doTest("[3,6,9,12]",
                4);
        }

        TEST_METHOD(TestMethod3)
        {
            doTest("[20,1,15,3,10,5,8]",
                4);
        }

        TEST_METHOD(TestMethod4)
        {
            doTest("[9,4,7,2,10]",
                3);
        }

        void doTest(string src, int expected)
        {
            auto A = toIntArray(src);
            Solution sln;
            auto actual = sln.longestArithSeqLength(A);
            Assert::AreEqual(expected, actual);
        }
	};
}
