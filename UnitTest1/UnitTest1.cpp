#include "pch.h"
#include "../lab1/red_black_tree.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		red_black_tree map;
		TEST_METHOD(Test_insert)
		{
			map.insert(15, 23);
			red_black_tree_node* y = map.find(15);
			Assert::AreEqual(y->value, 23);

			map.insert(2, 10);
			red_black_tree_node* x = map.find(2);
			Assert::AreEqual(x->value, 10);
		}
		TEST_METHOD(Test_find)
		{
			map.insert(15, 23);
			map.insert(2, 10);
			red_black_tree_node* y = map.find(15);
			Assert::IsTrue(y->value == 23);
		}
		TEST_METHOD(Test_find_2)
		{
			map.insert(24, 12);
			map.insert(6, 76);
			red_black_tree_node* y = map.find(6);
			Assert::IsTrue(y->value == 76);
		}
		TEST_METHOD(Test_get_keys)
		{
			int array[3] = { 53,42,63 };
			for (int i = 0; i < 3; i++) map.insert(array[i], array[i]);
			ListOfNum list_keys;
			list_keys = map.get_keys();
			Assert::IsTrue(list_keys.contains(53) && list_keys.contains(42) && list_keys.contains(63) && list_keys.get_size() == 3);
			ListOfNum list_value;
			list_value = map.get_values();
			Assert::IsTrue(list_value.contains(53) && list_value.contains(42) && list_value.contains(63) && list_value.get_size() == 3);
		}
	};
}