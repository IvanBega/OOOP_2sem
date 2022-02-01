#include "pch.h"
#include "CppUnitTest.h"
#include "../VectorQueue.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab1Tests
{
	TEST_CLASS(VectorQueueTests)
	{
	public:

		TEST_METHOD(AddAndPopOneElement)
		{
			auto q = new VectorQueue<int>;
			q->push(100, 1);
			int pop = q->pop();
			Assert::AreEqual(100, pop);
		}
		TEST_METHOD(AddAndSeekOneElement)
		{
			auto q = new VectorQueue<int>;
			q->push(100, 1);
			int pop = q->peek();
			Assert::AreEqual(100, pop);
		}
		TEST_METHOD(AddAndPopElementsSamePriority)
		{
			int values[10] = { 10,9,8,7,6,5,4,3,2,1 };
			auto q = new VectorQueue<int>;
			for (int i = 0; i < 10; i++)
			{
				q->push(values[i], 0);
			}
			for (int i = 0; i < 10; i++)
			{
				Assert::AreEqual(values[i], q->pop());
			}
		}
		TEST_METHOD(AddAndPopManyElements)
		{
			auto q = new VectorQueue<int>;
			for (int i = 0; i < 1000; i++)
			{
				q->push(i, 1000 - i);
			}
			for (int i = 0; i < 1000; i++)
			{
				Assert::AreEqual(1000 - i - 1, q->pop());
			}

		}
	};
}