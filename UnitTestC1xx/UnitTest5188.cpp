#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5188.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC193
{
    TEST_CLASS(UnitTest5188)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            auto parent = toIntArray("[-1,0,0,1,1,2,2]");
            int n = 7;
            TreeAncestor ta(7, parent);
            Assert::AreEqual(1, ta.getKthAncestor(3, 1));  // ���� 1 ������ 3 �ĸ��ڵ�
            Assert::AreEqual(0, ta.getKthAncestor(5, 2));  // ���� 0 ������ 5 ���游�ڵ�
            Assert::AreEqual(-1, ta.getKthAncestor(6, 3));  // ���� -1 ��Ϊ����������Ҫ������Ƚڵ�
        }
    };
}