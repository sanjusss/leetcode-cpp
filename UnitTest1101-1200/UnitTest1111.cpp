#include "pch.h"
#include "CppUnitTest.h"
#include "../1101-1200/1111.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest11011200
{
    TEST_CLASS(UnitTest1111)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("(()())", 
                "[0,1,1,1,1,0]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("()(())()",
                "[0,0,0,1,1,0,1,1]");
        }

        void check(string seq, string expectedSrc)
        {
            auto expected = toIntArray(expectedSrc);
            Solution sln;
            auto actual = sln.maxDepthAfterSplit(seq);
            Assert::AreEqual(depth(seq, expected), depth(seq, actual));
        }

        int depth(const string& seq, vector<int> ins)
        {
            return max(depth(seq, ins, 0), depth(seq, ins, 1));
        }
        
        int depth(const string& seq, vector<int> ins, int tag)
        {
            int res = 0;
            int d = 0;
            for (int i = 0; i < seq.size(); ++i)
            {
                if (ins[i] != tag)
                {
                    continue;
                }

                if (seq[i] == '(')
                {
                    ++d;
                    res = max(res, d);
                }
                else
                {
                    --d;
                }
            }

            return res;
        }
    };
}