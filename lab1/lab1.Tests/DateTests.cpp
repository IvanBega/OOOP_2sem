#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../Date.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab1Tests
{
	TEST_CLASS(DateTests)
	{
	public:
		TEST_METHOD(ParameterLessConstructorTest)
		{
			Date date;
			Assert::AreEqual(date.getDay(), 0);
			Assert::AreEqual(date.getMonth(), 0);
			Assert::AreEqual(date.getYear(), 0);
		}
		TEST_METHOD(ParameterConstructorTest)
		{
			Date date(4, 10, 3);
			Assert::AreEqual(date.getDay(), 3);
			Assert::AreEqual(date.getMonth(), 10);
			Assert::AreEqual(date.getYear(), 4);
		}
		TEST_METHOD(AddDaysTest)
		{
			Date date1(0, 0, 0);
			Date expected1(0, 0, 1);
			date1.addDays(1);

			Assert::IsTrue(date1 == expected1);

			Date date2(1, 4, 28);
			Date expected2(36, 11, 4);
			date2.addDays(12974);

			Assert::IsTrue(date2 == expected2);
		}
		TEST_METHOD(EqualityOperatorTest)
		{
			Date date1(1, 2, 3);
			Date date2(1, 2, 3);
			Assert::IsTrue(date1 == date2);

			date2.setDay(20);
			Assert::IsFalse(date1 == date2);
		}
		TEST_METHOD(GetSetMethodsTest)
		{
			Date date;
			date.setDay(19);
			date.setMonth(4);
			date.setYear(8);

			Assert::AreEqual(date.getDay(), 19);
			Assert::AreEqual(date.getMonth(), 4);
			Assert::AreEqual(date.getYear(), 8);
		}
	
	};
}
