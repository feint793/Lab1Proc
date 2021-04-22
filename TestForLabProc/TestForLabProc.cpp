#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../Lab1Proc/container.h"
#include "../Lab1Proc/Container_constr.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nature;
using namespace std;

int Difference(ifstream& ifst_1, ifstream& ifst_2);

namespace TestForLabProc
{
	TEST_CLASS(TestForLabProc)
	{
	public:

		TEST_METHOD(Container_In_5) //Проверка функции In для контейнера
		{
			ifstream ifst("in_5.txt"); //В файле 7 объектов
			container c;
			Init(c);
			InContainer(c, ifst);
			int real_len = c.len;
			Assert::AreEqual(real_len, 5);//OK
			Clear(c);
		}

		TEST_METHOD(Container_In_0) //Проверка функции In для контейнера
		{
			ifstream ifst("in_0.txt"); //В файле пусто
			container c;
			Init(c);
			InContainer(c, ifst);
			int real_len = c.len;
			Assert::AreEqual(real_len, 0);//OK
			Clear(c);
		}
		TEST_METHOD(Shape_In_5) //Проверка функции In для класса wisdom
		{
			ifstream ifst("in_5_with_incorrect_keys.txt"); //В файле 5 объектов, 2 с неправильными ключами
			container c;
			Init(c);
			InContainer(c, ifst);
			int real_len = c.len;
			Assert::AreEqual(real_len, 3); //OK
			Clear(c);
		}

		TEST_METHOD(Container_Sort_5) //Проверка функции Sort для контейнера
		{
			ifstream ifst("in_6.txt"); //В файле 6 объектов
			ofstream ofst("out_6.txt");
			container c;
			Init(c);
			InContainer(c, ifst);
			Sort(c); // ОК, сортировка прошла как обычно
			OutContainer(c, ofst);
			int real_len = c.len;
			Assert::AreEqual(real_len, 6); //OK
			Clear(c);
		}

		TEST_METHOD(Container_Sort_0) //Проверка функции Sort для пустого контейнера
		{
			ifstream ifst("in_0.txt"); // пустой файл
			ofstream ofst("out_0.txt");
			container c;
			Init(c);
			InContainer(c, ifst);
			Sort(c); // ОК, сортировка прошла как обычно
			OutContainer(c, ofst);//В выходном файле "Container contents 0 elements."
			int real_len = c.len;
			Assert::AreEqual(real_len, 0); //OK
			Clear(c);
		}

		TEST_METHOD(Container_Sort_1) //Проверка функции Sort для контейнера с одним элементом
		{
			ifstream ifst("in_1.txt"); //В файле один элемент
			ofstream ofst("out_1.txt");
			container c;
			Init(c);
			InContainer(c, ifst);
			Sort(c); // ОК, сортировка прошла как обычно
			OutContainer(c, ofst);//В выходном файле "Container contents 0 elements."
			int real_len = c.len;
			Assert::AreEqual(real_len, 1); //OK
			Clear(c);
		}

		TEST_METHOD(Container_Sort_2) //Проверка функции Sort для контейнера с двумя элементами
		{
			ifstream ifst("in_2.txt"); //В файле два элемента
			ofstream ofst("out_2.txt");
			container c;
			Init(c);
			InContainer(c, ifst);
			Sort(c); // ОК, сортировка прошла как обычно
			OutContainer(c, ofst);//В выходном файле "Container contents 0 elements."
			int real_len = c.len;
			Assert::AreEqual(real_len, 2); //OK
			Clear(c);
		}

		TEST_METHOD(Container_OutTrees_0) //Проверка функции OutTrees для пустого контейнера
		{
			ifstream ifst("in_0.txt"); //В файле пусто
			ofstream ofst("out_0.txt");
			container c;
			Init(c);
			InContainer(c, ifst);
			OutOnlyTrees(c, ofst);
			int real_len = c.len;
			Assert::AreEqual(real_len, 0); //OK
			Clear(c);
		}

		TEST_METHOD(Container_OutTrees_without_objects) //Проверка функции OutTrees контейнера без деревьев
		{
			ifstream ifst("in_3_without_trees.txt"); //В файле 3 объектa
			ofstream ofst("out_3_without_trees.txt");
			container c;
			Init(c);
			InContainer(c, ifst);
			OutOnlyTrees(c, ofst);
			int real_len = c.len;
			Assert::AreEqual(real_len, 3); //OK
			Clear(c);
		}

		TEST_METHOD(Shape_InData_OverBuf) //Проверка функции InData на поведение в случае переполнения
		{
			ifstream ifst("in_1_overbuf.txt"); //В файле один объект > 50 символов
			ofstream ofst("out_1_overbuf.txt");
			ifstream ifst_IDEAL("out_1_overbuf_IDEAL.txt");
			container c;
			Init(c);
			InContainer(c, ifst);
			OutContainer(c, ofst);
			//тут сравнение двух файлов
			ifstream ifst_to_cmp("out_1_overbuf.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK
			Clear(c);
		}

		TEST_METHOD(Shape_CountLetters_0) //Проверка функции CountLetters в случае 0 согласных
		{
			ifstream ifst("in_0_letters.txt"); //В выражении нет согласных
			ofstream ofst("out_0_letters.txt");
			ifstream ifst_IDEAL("out_0_letters_IDEAL.txt");
			container c;
			Init(c);
			InContainer(c, ifst);
			OutContainer(c, ofst);
			//тут сравнение двух файлов
			ifstream ifst_to_cmp("out_0_letters.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK
			Clear(c);
		}

		TEST_METHOD(Shape_CountLetters_1) //Проверка функции CountLetters в случае 1 буквы
		{
			ifstream ifst("in_1_letter.txt"); //В выражении 1 буква
			ofstream ofst("out_1_letter.txt");
			ifstream ifst_IDEAL("out_1_letter_IDEAL.txt");
			container c;
			Init(c);
			InContainer(c, ifst);
			OutContainer(c, ofst);
			//тут сравнение двух файлов
			ifstream ifst_to_cmp("out_1_letter.txt");
			Assert::AreEqual(Difference(ifst_to_cmp, ifst_IDEAL), 1); //OK
			Clear(c);
		}

		TEST_METHOD(Container_Clean_0) //Проверка очистки контейнера при отсутствии элементов
		{
			ifstream ifst("in_0.txt"); //В файле пусто

			container c;
			Init(c);
			InContainer(c, ifst);
			Clear(c);//OK, цикл не начинался
			Assert::AreEqual(c.len, 0); //OK
		}

	};
}

	int Difference(ifstream& ifst_1, ifstream& ifst_2)
	{
		char ch_1 = '0';
		char ch_2 = '0';

		while (ifst_1.get(ch_1) && ifst_2.get(ch_2)) {
			if (ch_1 != ch_2)
			{
				return 0;
			}
		}
		return 1;
	}

