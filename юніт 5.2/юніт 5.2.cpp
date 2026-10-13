#include "pch.h"
#include "CppUnitTest.h"
#include "../LABAA 5.2/LABAA 5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Unittest52
{
	TEST_CLASS(Unittest52)
	{
	public:

		// Рекурентне співвідношення: при x = -2 з a0 = 0.5 отримуємо a1 = 1/(3*x^3) = -1/24
		TEST_METHOD(TestA)
		{
			double a = A(-2, 1, 0.5);
			Assert::AreEqual(-1.0 / 24.0, a, 1e-9);
		}

		// Сума ряду при x = -2 має збігатися з arctg(-2)
		TEST_METHOD(TestS)
		{
			int n = 0;
			double s = S(-2, 1e-6, n, 0);
			Assert::AreEqual(atan(-2.0), s, 1e-5);
		}
	};
}