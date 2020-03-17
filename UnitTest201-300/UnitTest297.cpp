#include "pch.h"
#include "CppUnitTest.h"
#include "../201-300/0297.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest201300
{
    TEST_CLASS(UnitTest297)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[1,2,3]");
        }

        TEST_METHOD(TestMethod3)
        {
            check("[1,null,2,3]");
        }

        TEST_METHOD(TestMethod4)
        {
            check("[5,4,7,3,null,2,null,-1,null,9]");
        }

        TEST_METHOD(TestMethod5)
        {
            check("[1,2,3,null,null,4,5]");
        }

    private:
        void check(string treeSrc)
        {
            auto expectedTree = toTreeNode(treeSrc);

            Codec c;
            auto actualTree = c.deserialize(treeSrc);
            Assert::AreEqual(*expectedTree, *actualTree);
            auto actualSrc = c.serialize(actualTree);
            Assert::AreEqual(treeSrc, actualSrc);

            freeTreeNode(expectedTree);
            freeTreeNode(actualTree);
        }
    };
}
