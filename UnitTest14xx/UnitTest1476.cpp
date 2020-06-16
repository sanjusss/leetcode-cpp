#include "pch.h"
#include "CppUnitTest.h"
#include "unittest.h"
#include "../14xx/1476.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest14xx
{
    TEST_CLASS(UnitTest1476)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[\"SubrectangleQueries\",\"getValue\",\"updateSubrectangle\",\"getValue\",\"getValue\",\"updateSubrectangle\",\"getValue\",\"getValue\"]",
                "[[[[1,2,1],[4,3,4],[3,2,1],[1,1,1]]],[0,2],[0,0,3,2,5],[0,2],[3,1],[3,0,3,2,10],[3,1],[0,2]]",
                "[null,1,null,5,5,null,10,5]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[\"SubrectangleQueries\",\"getValue\",\"updateSubrectangle\",\"getValue\",\"getValue\",\"updateSubrectangle\",\"getValue\"]",
                "[[[[1,1,1],[2,2,2],[3,3,3]]],[0,0],[0,0,2,2,100],[0,0],[2,2],[1,1,2,2,20],[2,2]]",
                "[null,1,null,100,100,null,20]");
        }

    private:
        void check(const string& calls, const string& inputs, const string& expecteds)
        {
            FunctionTest<SubrectangleQueries> ft(inputs, expecteds, calls,
                {
                    { "SubrectangleQueries", init },
                    { "updateSubrectangle", updateSubrectangle },
                    { "getValue", getValue }
                });
            ft.check();
        }

        static void init(SubrectangleQueries*& s, const string& inputSrc, const string& expectedSrc)
        {
            auto j = nlohmann::json::parse(inputSrc);
            auto input = j.at(0).get<vector<vector<int>>>();
            s = new SubrectangleQueries(input);
        }

        static void updateSubrectangle(SubrectangleQueries*& s, const string& inputSrc, const string& expectedSrc)
        {
            auto inputs = toIntArray(inputSrc);
            s->updateSubrectangle(inputs[0], inputs[1], inputs[2], inputs[3], inputs[4]);
        }

        static void getValue(SubrectangleQueries*& s, const string& inputSrc, const string& expectedSrc)
        {
            auto inputs = toIntArray(inputSrc);
            auto actual = s->getValue(inputs[0], inputs[1]);
            Assert::AreEqual(stoi(expectedSrc), actual);
        }
    };
}
