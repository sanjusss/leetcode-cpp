#include "pch.h"
#include "CppUnitTest.h"
#include "../101-200/0142.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101200
{
    TEST_CLASS(UnitTest142)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            doTest("[-1,-7,7,-4,19,6,-9,-5,-2,-5]", 6);
        }

        TEST_METHOD(TestMethod2)
        {
            doTest("[-1,-7,7,-4,19,6,-9,-5,-2,-5]", 9);
        }

        void doTest(string src, int pos)
        {
            auto arr = toIntArray(src);
            vector<ListNode*> nodes;
            for (size_t i = 0; i < arr.size(); ++i)
            {
                nodes.push_back(new ListNode(arr[i]));
                if (i == arr.size() - 1)
                {
                    nodes[i]->next = nodes[pos];
                }

                if (i != 0)
                {
                    nodes[i - 1]->next = nodes[i];
                }
            }

            Solution sln;
            auto actual = sln.detectCycle(nodes[0]);
            Assert::IsTrue(nodes[pos] == actual);
        }
    };
}