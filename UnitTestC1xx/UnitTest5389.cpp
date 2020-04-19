#include "pch.h"
#include "CppUnitTest.h"
#include "../C1XX/5389.hpp"
#include "unittest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestC185
{
    TEST_CLASS(UnitTest5389)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            check("[[\"David\",\"3\",\"Ceviche\"],[\"Corina\",\"10\",\"Beef Burrito\"],[\"David\",\"3\",\"Fried Chicken\"],[\"Carla\",\"5\",\"Water\"],[\"Carla\",\"5\",\"Ceviche\"],[\"Rous\",\"3\",\"Ceviche\"]]",
                "[[\"Table\",\"Beef Burrito\",\"Ceviche\",\"Fried Chicken\",\"Water\"],[\"3\",\"0\",\"2\",\"1\",\"0\"],[\"5\",\"0\",\"1\",\"0\",\"1\"],[\"10\",\"1\",\"0\",\"0\",\"0\"]]");
        }

        TEST_METHOD(TestMethod2)
        {
            check("[[\"James\",\"12\",\"Fried Chicken\"],[\"Ratesh\",\"12\",\"Fried Chicken\"],[\"Amadeus\",\"12\",\"Fried Chicken\"],[\"Adam\",\"1\",\"Canadian Waffles\"],[\"Brianna\",\"1\",\"Canadian Waffles\"]]",
                "[[\"Table\",\"Canadian Waffles\",\"Fried Chicken\"],[\"1\",\"2\",\"0\"],[\"12\",\"0\",\"3\"]]");
        }

        TEST_METHOD(TestMethod3)
        {
            check("[[\"Laura\",\"2\",\"Bean Burrito\"],[\"Jhon\",\"2\",\"Beef Burrito\"],[\"Melissa\",\"2\",\"Soda\"]]",
                "[[\"Table\",\"Bean Burrito\",\"Beef Burrito\",\"Soda\"],[\"2\",\"1\",\"1\",\"1\"]]");
        }

        void check(string ordersSrc, string expectedSrc)
        {
            auto orders = toString2DArray(ordersSrc);
            auto expected = toString2DArray(expectedSrc);
            Solution sln;
            auto actual = sln.displayTable(orders);
            Assert::AreEqual(expected, actual);
        }
    };
}