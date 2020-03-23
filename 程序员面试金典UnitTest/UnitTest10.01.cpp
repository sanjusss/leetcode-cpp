#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../����Ա���Խ��/10.01.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ����Ա���Խ��UnitTest10
{
    TEST_CLASS(����Ա���Խ��UnitTest10_01)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            check("[1,2,3,0,0,0]", 3,
                "[2,5,6]", 3,
                "[1,2,2,3,5,6]");
        }

        void check(string ASrc, int m, string BSrc, int n, string expectedSrc)
        {
            auto A = toIntArray(ASrc);
            auto B = toIntArray(BSrc);
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            sln.merge(A, m, B, n);
            Assert::AreEqual(expected, A);
        }
    };
}
