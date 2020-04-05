#include "pch.h"
#include "CppUnitTest.h"
#include "../401-500/0460.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest401500
{
    TEST_CLASS(UnitTest460)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            LFUCache cache(2 /* capacity (��������) */);

            cache.put(1, 1);
            cache.put(2, 2);
            Assert::AreEqual(1, cache.get(1));       // ���� 1
            cache.put(3, 3);    // ȥ�� key 2
            Assert::AreEqual(-1, cache.get(2));       // ���� -1 (δ�ҵ�key 2)
            Assert::AreEqual(3, cache.get(3));       // ���� 3
            cache.put(4, 4);    // ȥ�� key 1
            Assert::AreEqual(-1, cache.get(1));       // ���� -1 (δ�ҵ� key 1)
            Assert::AreEqual(3, cache.get(3));       // ���� 3
            Assert::AreEqual(4, cache.get(4));       // ���� 4
        }

        TEST_METHOD(TestMethod2)
        {
            LFUCache cache(0 /* capacity (��������) */);

            cache.put(0, 0);
            Assert::AreEqual(-1, cache.get(0));       // ���� -1
        }
    };
}
