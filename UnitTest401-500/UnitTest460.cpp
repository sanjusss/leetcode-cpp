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
            LFUCache cache(2 /* capacity (缓存容量) */);

            cache.put(1, 1);
            cache.put(2, 2);
            Assert::AreEqual(1, cache.get(1));       // 返回 1
            cache.put(3, 3);    // 去除 key 2
            Assert::AreEqual(-1, cache.get(2));       // 返回 -1 (未找到key 2)
            Assert::AreEqual(3, cache.get(3));       // 返回 3
            cache.put(4, 4);    // 去除 key 1
            Assert::AreEqual(-1, cache.get(1));       // 返回 -1 (未找到 key 1)
            Assert::AreEqual(3, cache.get(3));       // 返回 3
            Assert::AreEqual(4, cache.get(4));       // 返回 4
        }

        TEST_METHOD(TestMethod2)
        {
            LFUCache cache(0 /* capacity (缓存容量) */);

            cache.put(0, 0);
            Assert::AreEqual(-1, cache.get(0));       // 返回 -1
        }
    };
}
