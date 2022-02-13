#include "pch.h"
#include "CppUnitTest.h"
#include "../DateTime.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab1Tests
{
	TEST_CLASS(DateTimeTests)
	{
	public:
		TEST_METHOD(ParameterLessConstructorTest)
		{
			DateTime dt;
			Assert::AreEqual(dt.getHour(), 0);
			Assert::AreEqual(dt.getMinute(), 0);
			Assert::AreEqual(dt.getSecond(), 0);
			Assert::AreEqual(dt.getYear(), 2000);
			Assert::AreEqual(dt.getMonth(), 1);
			Assert::AreEqual(dt.getDay(), 1);
		}
		TEST_METHOD(AddSecondsTest)
		{
			bool actual;
			DateTime dt1(2020, 2, 28, 3, 4, 5);
			dt1.addSeconds(86400);
			DateTime expected1(2020, 2, 29, 3, 4, 5);
			actual = dt1 == expected1;
			Assert::IsTrue(actual);

			DateTime dt2(2020, 2, 28, 3, 4, 5);
			dt2.addSeconds(-86400);
			DateTime expected2(2020, 2, 27, 3, 4, 5);
			actual = dt2 == expected2;
			Assert::IsTrue(actual);
		}
		TEST_METHOD(ParameterConstrustorTest)
		{
			DateTime dt1(2022, 2, 13, 13, 28, 46);
			Assert::AreEqual(dt1.getHour(), 13);
			Assert::AreEqual(dt1.getMinute(), 28);
			Assert::AreEqual(dt1.getSecond(), 46);
			Assert::AreEqual(dt1.getYear(), 2022);
			Assert::AreEqual(dt1.getMonth(), 2);
			Assert::AreEqual(dt1.getDay(), 13);
		}
		TEST_METHOD(GetSetMethodsTest)
		{
			DateTime dt;
			dt.setHour(4);
			dt.setMinute(45);
			dt.setSecond(56);
			dt.setYear(2022);
			dt.setMonth(2);
			dt.setDay(13);
			Assert::AreEqual(dt.getHour(), 4);
			Assert::AreEqual(dt.getMinute(), 45);
			Assert::AreEqual(dt.getSecond(), 56);
			Assert::AreEqual(dt.getYear(), 2022);
			Assert::AreEqual(dt.getMonth(), 2);
			Assert::AreEqual(dt.getDay(), 13);
		}
		TEST_METHOD(AddTimeTest)
		{
			DateTime dt(2022, 2, 13, 12, 49, 2);
			Time timeToAdd(11, 10, 59);
			dt.addTime(timeToAdd);

			Assert::AreEqual(dt.getYear(), 2022);
			Assert::AreEqual(dt.getMonth(), 2);
			Assert::AreEqual(dt.getDay(), 14);
			Assert::AreEqual(dt.getHour(), 0);
			Assert::AreEqual(dt.getMinute(), 0);
			Assert::AreEqual(dt.getSecond(), 1);
		}
		TEST_METHOD(EqualityOperatorTest)
		{
			DateTime dt1(2022, 2, 13, 12, 53, 47);
			DateTime dt2(2022, 2, 13, 12, 53, 47);
			bool actual = dt1 == dt2;
			Assert::IsTrue(actual);

			dt2.setHour(3);
			actual = dt1 == dt2;
			Assert::IsFalse(actual);
		}
		TEST_METHOD(OutputOperatorTest)
		{
			/*
			* source: https://stackoverflow.com/questions/5419356/redirect-stdout-stderr-to-a-string
			*/
			DateTime dt1(2022, 2, 13, 12, 54, 0);
			std::string expected = "13.02.2022 12:54:00";
			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
			std::cout << dt1;

			std::string actual = buffer.str();
			Assert::AreEqual(expected, actual);
		}
	};
}
