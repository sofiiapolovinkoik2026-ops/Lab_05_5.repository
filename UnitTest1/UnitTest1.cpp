#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_5/Lab_05_5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(Test_V3_Calculation)
        {
            int a = 3, b = 2, c = 5, m = 10;
            int v1 = 1, v2 = 4;
            int depth = 0;

           
            int expected = 9;
            int actual = V(3, a, b, c, m, v1, v2, depth, 1);

            Assert::AreEqual(expected, actual);
            Assert::AreEqual(2, depth);
        }
    };
}