#include "pch.h"
#include "CppUnitTest.h"
#include "../Time.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab1Tests
{
	TEST_CLASS(TimeTests)
	{
	public:
		TEST_METHOD(ParameterLessConstructorTest)
		{
			Time time;
			Assert::AreEqual(time.getHour(), 0);
			Assert::AreEqual(time.getMinute(), 0);
			Assert::AreEqual(time.getSecond(), 0);
		}
		TEST_METHOD(ParameterConstrustorTest)
		{
			Time time(1, 2, 3);
			Assert::AreEqual(time.getHour(), 1);
			Assert::AreEqual(time.getMinute(), 2);
			Assert::AreEqual(time.getSecond(), 3);
		}
		TEST_METHOD(GetSetMethodsTest)
		{
			Time time;
			time.setHour(4);
			time.setMinute(45);
			time.setSecond(56);
			Assert::AreEqual(time.getHour(), 4);
			Assert::AreEqual(time.getMinute(), 45);
			Assert::AreEqual(time.getSecond(), 56);
		}
		TEST_METHOD(AddTimeTest)
		{
			Time time(12, 42, 14);
			Time timeToAdd(7, 23, 3);
			time.addTime(timeToAdd);
			
			Assert::AreEqual(time.getHour(), 20);
			Assert::AreEqual(time.getMinute(), 5);
			Assert::AreEqual(time.getSecond(), 17);
		}
		TEST_METHOD(EqualityOperatorTest)
		{
			Time time1(8, 7, 6);
			Time time2(8, 7, 6);
			bool actual = time1 == time2;
			Assert::IsTrue(actual);
		}
		TEST_METHOD(OutputOperatorTest)
		{
			/*
			* source: https://stackoverflow.com/questions/5419356/redirect-stdout-stderr-to-a-string
			*/
			Time time1(15, 42, 30);
			std::string expected = "15:42:30";
			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
			std::cout << time1;

			std::string actual = buffer.str();
			Assert::AreEqual(expected, actual);


			
			buffer.swap(stringstream()); // clear the buffer

			Time time2(3, 0, 2);
			expected = "03:00:02";
			std::cout << time2;
			
			actual = buffer.str();
			Assert::AreEqual(expected, actual);
		}
	};
}
