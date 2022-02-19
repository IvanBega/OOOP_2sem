#include "pch.h"
#include "CppUnitTest.h"
#include "../BinaryHeapQueue.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab1Tests
{
	TEST_CLASS(BinaryHeapQueueTests)
	{
	public:
		TEST_METHOD(EmptyQueueTest)
		{
			auto q = new BinaryHeapQueue<int>;
			Assert::IsTrue(q->empty());
			q->push(1, 1);
			Assert::IsFalse(q->empty());
			q->pop();
			Assert::IsTrue(q->empty());
		}
		TEST_METHOD(AddAndPopOneElement)
		{
			auto q = new BinaryHeapQueue<int>;
			q->push(100, 1);
			int pop = q->pop();
			Assert::AreEqual(100, pop);
		}
		TEST_METHOD(AddAndSeekOneElement)
		{
			auto q = new BinaryHeapQueue<int>;
			q->push(100, 1);
			int pop = q->peek();
			Assert::AreEqual(100, pop);
		}
		TEST_METHOD(AddAndPopManyElements)
		{
			auto q = new BinaryHeapQueue<int>;
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