/*
############################################ ЗАДАНИЕ ###########################################
			Шаблонный класс «Вектор»
	Реализовать разработанный ранее класс «Вектор» в виде
шаблонного класса. В клиентской части программы
продемонстрировать работу всех методов класса. При создании
объектов шаблонного класса важно типизировать шаблон
разными типами данных (стандартными и пользовательскими).
################################################################################################
		СТАТУС : Готово.
		ДОРАБОТКИ:
*
		ИЗВЕСТНЫЕ ОШИБКИ:
*
		ПРОТЕСТИРОВАТЬ:
*
		ВОПРОСЫ:
*
		ВИДЕО: 02:36:18 (начало дз), 01:43:00(шаблоны класса), 02:05:40 (о шаблонном веркторе)
################################################################################################
*/

// Класс для тестирования шаблонного класса Vector.
#include <iostream>
#include "Vector.h"
using std::cin;
using std::boolalpha;

class Test
{
	int m_a;
public:
	Test() :m_a{ 0 } {};
	Test(int a) :m_a{ a } {};

	void Set(int n)
	{
		m_a = n;
	}
	int Get()
	{
		return m_a;
	}
	void Show()
	{
		cout << m_a << endl;
	}

	friend ostream& operator<<(ostream& os, const Test& obj);
	friend istream& operator>>(istream& os, Test& obj);

	Test operator + (const Test& test) const;

	Test operator - (const Test& test) const;

	// Увеличение всех компонент вектора на единицу (префикс).	
	Test& operator ++ ();

	// Увеличение всех компонент вектора на единицу (постфикс).	
	Test operator ++ (int postfix);

	// Уменьшение всех компонент вектора на	единицу (префикс).
	Test& operator--();

	// Уменьшение всех компонент вектора на единицу (постфикс).
	Test operator--(int postfix);

	//// Перегруженный оператор присваивания с копированием.
	//Test& operator = (const Test& test);

	// Перегрузка оператора ">" для "this > object".
	bool operator > (const Test& test) const;

	// Перегрузка оператора "*" для "this * object".
	Test operator * (const Test& test) const;

};

ostream& operator<<(ostream& os, const Test& obj)
{
	cout << obj.m_a << "\t";
	return os;
}

istream& operator>>(istream& is, Test& obj)
{
	cin >> obj.m_a;
	return is;
}

Test Test::operator+(const Test& test) const
{
	Test result{};
	result.m_a = m_a + test.m_a;
	return result;
}

Test Test::operator-(const Test& test) const
{
	Test result{};
	result.m_a = m_a - test.m_a;
	return result;
}

Test& Test::operator++()
{
	++m_a;
	return *this;
}

Test Test::operator++(int postfix)
{
	Test tmp = *this;
	m_a++;
	return tmp;
}

Test& Test::operator--()
{
	--m_a;
	return *this;
}

Test Test::operator--(int postfix)
{
	Test tmp = *this;
	m_a--;
	return tmp;
}

bool Test::operator>(const Test& test) const
{

	return m_a > test.m_a ? m_a : test.m_a;
}

Test Test::operator*(const Test& test) const
{
	Test result{};
	result.m_a = m_a * test.m_a;
	return result;
}

int main()
{
	srand(time(0));
	//int
	int size{ 5 };
	int* arr_int = new int[size] {1, 2, 3, 4, 5}; // Массив для инициализации INT_ом.
	for (int i = 0; i < size; i++)
	{
		cout << arr_int[i] << ' ';
	}
	cout << endl;
	//double
	double* arr_double = new double[size] {1.1, 2.2, 3.3, 4.4, 5.5}; // Массив для инициализации double_ом.
	for (int i = 0; i < size; i++)
	{
		cout << arr_int[i] << ' ';
	}
	cout << endl;
	//class Test
	Test* arr_class = new Test[size]{ 1, 2, 3, 4, 5 }; // Массив для инициализации вектора class_ом.
	for (int i = 0; i < size; i++)
	{
		cout << arr_int[i] << ' ';
	}
	cout << endl;

	//int
	Vector<int> v1_int;
	Vector<int> v2_int{ 3 };
	Vector<int> v3_int{ arr_int, size };
	//double
	Vector<double> v1_double;
	Vector<double> v2_double{ 3 };
	Vector<double> v3_double{ arr_double, size };
	//class Test
	Vector<Test> v1_class;
	Vector<Test> v2_class{ 3 };
	Vector<Test> v3_class{ arr_class, size };

	//int
	cout << "\n\tv1_int size is " << v1_int.GetSize() << endl;
	cout << "\n\tv2_int size is " << v2_int.GetSize() << endl;
	cout << "\n\tv3_int size is " << v3_int.GetSize() << endl;
	//double
	cout << "\n\tv1_double size is " << v1_double.GetSize() << endl;
	cout << "\n\tv2_double size is " << v2_double.GetSize() << endl;
	cout << "\n\tv3_double size is " << v3_double.GetSize() << endl;
	//class Test
	cout << "\n\tv1_class size is " << v1_class.GetSize() << endl;
	cout << "\n\tv2_class size is " << v2_class.GetSize() << endl;
	cout << "\n\tv3_class size is " << v3_class.GetSize() << endl;

	//int
	cout << "\n\tv1_int IsEmpty - " << boolalpha << v1_int.IsEmpty() << endl;
	cout << "\n\tv2_int IsEmpty - " << boolalpha << v2_int.IsEmpty() << endl;
	cout << "\n\tv3_int IsEmpty - " << boolalpha << v3_int.IsEmpty() << endl;
	//double
	cout << "\n\tv1_double IsEmpty - " << boolalpha << v1_double.IsEmpty() << endl;
	cout << "\n\tv2_double IsEmpty - " << boolalpha << v2_double.IsEmpty() << endl;
	cout << "\n\tv3_double IsEmpty - " << boolalpha << v3_double.IsEmpty() << endl;
	//class Test
	cout << "\n\tv1_class IsEmpty - " << boolalpha << v1_class.IsEmpty() << endl;
	cout << "\n\tv2_class IsEmpty - " << boolalpha << v2_class.IsEmpty() << endl;
	cout << "\n\tv3_class IsEmpty - " << boolalpha << v3_class.IsEmpty() << endl;

	//int
	cout << "\n\tv1_int :" << endl;
	v1_int.Print();
	cout << endl;
	cout << "\tv2_int :" << endl;
	v2_int.Print();
	cout << endl;
	cout << "\tv3_int :" << endl;
	v3_int.Print();
	cout << endl;
	//double
	cout << "\n\tv1_double :" << endl;
	v1_double.Print();
	cout << endl;
	cout << "\tv2_double :" << endl;
	v2_double.Print();
	cout << endl;
	cout << "\tv3_double :" << endl;
	v3_double.Print();
	cout << endl;
	//class Test
	cout << "\n\tv1_class :" << endl;
	v1_class.Print();
	cout << endl;
	cout << "\tv2_class :" << endl;
	v2_class.Print();
	cout << endl;
	cout << "\tv3_class :" << endl;
	v3_class.Print();
	cout << endl;

	//int
	v1_int.Add(111);
	v1_int.Add(111);
	v2_int.Add(222);
	v2_int.Add(222);
	v3_int.Add(333);
	v3_int.Add(333);
	cout << "\n\tv1_int After adding 2 elements to the Vector<int> :" << endl;
	v1_int.Print();
	cout << "\n\tv2_int After adding 2 elements to the Vector<int> :" << endl;
	v2_int.Print();
	cout << "\n\tv3_int After adding 2 elements to the Vector<int> :" << endl;
	v3_int.Print();
	//double
	v1_double.Add(111.1);
	v1_double.Add(111.1);
	v2_double.Add(222.2);
	v2_double.Add(222.2);
	v3_double.Add(333.3);
	v3_double.Add(333.3);
	cout << "\n\tv1_double After adding 2 elements to the Vector<double> :" << endl;
	v1_double.Print();
	cout << "\n\tv2_double After adding 2 elements to the Vector<double> :" << endl;
	v2_double.Print();
	cout << "\n\tv3_double After adding 2 elements to the Vector<double> :" << endl;
	v3_double.Print();
	//class Test
	v1_class.Add(111);
	v1_class.Add(111);
	v2_class.Add(222);
	v2_class.Add(222);
	v3_class.Add(333);
	v3_class.Add(333);
	cout << "\n\tv1_class After adding 2 elements to the Vector<class> :" << endl;
	v1_class.Print();
	cout << "\n\tv2_class After adding 2 elements to the Vector<class> :" << endl;
	v2_class.Print();
	cout << "\n\tv3_class After adding 2 elements to the Vector<class> :" << endl;
	v3_class.Print();

	//int
	v1_int.Clear();
	v2_int.Clear();
	v3_int.Clear();
	cout << "\n\tv1_int After clearing the Vector<int> :" << endl;
	v1_int.Print();
	cout << "\n\tv2_int After clearing the Vector<int> :" << endl;
	v2_int.Print();
	cout << "\n\tv3_int After clearing the Vector<int> :" << endl;
	v3_int.Print();
	//double
	v1_double.Clear();
	v2_double.Clear();
	v3_double.Clear();
	cout << "\n\tv1_double After clearing the Vector<double> :" << endl;
	v1_double.Print();
	cout << "\n\tv2_double After clearing the Vector<double> :" << endl;
	v2_double.Print();
	cout << "\n\tv3_double After clearing the Vector<double> :" << endl;
	v3_double.Print();
	//class Test
	v1_class.Clear();
	v2_class.Clear();
	v3_class.Clear();
	cout << "\n\tv1_class After clearing the Vector<class> :" << endl;
	v1_class.Print();
	cout << "\n\tv2_class After clearing the Vector<class> :" << endl;
	v2_class.Print();
	cout << "\n\tv3_class After clearing the Vector<class> :" << endl;
	v3_class.Print();

	//int
	v1_int.Input();
	v2_int.Input();
	v3_int.Input();
	cout << "\n\tv1_int After filling the Vector<int> :" << endl;
	v1_int.Print();
	cout << "\n\tv2_int After filling the Vector<int> :" << endl;
	v2_int.Print();
	cout << "\n\tv3_int After filling the Vector<int> :" << endl;
	v3_int.Print();
	//double
	v1_double.Input();
	v2_double.Input();
	v3_double.Input();
	cout << "\n\tv1_double After filling the Vector<double> :" << endl;
	v1_double.Print();
	cout << "\n\tv2_double After filling the Vector<double> :" << endl;
	v2_double.Print();
	cout << "\n\tv3_double After filling the Vector<double> :" << endl;
	v3_double.Print();
	//class Test
	v1_class.Input();
	v2_class.Input();
	v3_class.Input();
	cout << "\n\tv1_class After filling the Vector<class> :" << endl;
	v1_class.Print();
	cout << "\n\tv2_class After filling the Vector<class> :" << endl;
	v2_class.Print();
	cout << "\n\tv3_class After filling the Vector<class> :" << endl;
	v3_class.Print();

	//int
	cout << "\n\tv1_int IsEmpty - " << boolalpha << v1_int.IsEmpty() << endl;
	cout << "\n\tv2_int IsEmpty - " << boolalpha << v2_int.IsEmpty() << endl;
	cout << "\n\tv3_int IsEmpty - " << boolalpha << v3_int.IsEmpty() << endl;
	//double
	cout << "\n\tv1_double IsEmpty - " << boolalpha << v1_double.IsEmpty() << endl;
	cout << "\n\tv2_double IsEmpty - " << boolalpha << v2_double.IsEmpty() << endl;
	cout << "\n\tv3_double IsEmpty - " << boolalpha << v3_double.IsEmpty() << endl;
	//class Test
	cout << "\n\tv1_class IsEmpty - " << boolalpha << v1_class.IsEmpty() << endl;
	cout << "\n\tv2_class IsEmpty - " << boolalpha << v2_class.IsEmpty() << endl;
	cout << "\n\tv3_class IsEmpty - " << boolalpha << v3_class.IsEmpty() << endl;

	//int
	cout << "\n\tv1_int After inserting the 111111 into the Vector<int> at the 1 index :" << endl;
	v1_int.Insert(1, 111111);
	v1_int.Print();
	cout << "\n\tv1_int size is " << v1_int.GetSize() << endl;
	//double
	cout << "\n\tv1_double After inserting the 111111 into the Vector<double> at the 1 index :" << endl;
	v1_double.Insert(1, 111111.1);
	v1_double.Print();
	cout << "\n\tv1_double size is " << v1_double.GetSize() << endl;
	//class Test
	cout << "\n\tv1_class After inserting the 111111 into the Vector<class> at the 1 index :" << endl;
	v1_class.Insert(1, 111111);
	v1_class.Print();
	cout << "\n\tv1_class size is " << v1_class.GetSize() << endl;

	//int
	cout << "\n\tv2_int After inserting the 222222 into the Vector<int> at the 2 index :" << endl;
	v2_int.Insert(2, 222222);
	v2_int.Print();
	cout << "\n\tv2_int size is " << v2_int.GetSize() << endl;
	//double
	cout << "\n\tv2_double After inserting the 222222 into the Vector<double> at the 2 index :" << endl;
	v2_double.Insert(2, 222222.2);
	v2_double.Print();
	cout << "\n\tv2_double size is " << v2_double.GetSize() << endl;
	//class Test
	cout << "\n\tv2_class After inserting the 222222 into the Vector<class> at the 2 index :" << endl;
	v2_class.Insert(2, 222222);
	v2_class.Print();
	cout << "\n\tv2_class size is " << v2_class.GetSize() << endl;

	//int
	cout << "\n\tv3_int After inserting the 333333 into the Vector<int> at the 3 index :" << endl;
	v3_int.Insert(3, 333333);
	v3_int.Print();
	cout << "\n\tv3_int size is " << v3_int.GetSize() << endl;
	//double
	cout << "\n\tv3_double After inserting the 333333 into the Vector<double> at the 3 index :" << endl;
	v3_double.Insert(3, 333333.3);
	v3_double.Print();
	cout << "\n\tv3_double size is " << v3_double.GetSize() << endl;
	//class Test
	cout << "\n\tv3_class After inserting the 333333 into the Vector<class> at the 3 index :" << endl;
	v3_class.Insert(3, 333333);
	v3_class.Print();

	//int
	v1_int.Remove(1);
	cout << "\n\tv1_int After removing an element from a Vector<int> at a 1 index :" << endl;
	v1_int.Print();
	cout << "\n\tv1_int size is " << v1_int.GetSize() << endl;
	//double
	v1_double.Remove(1);
	cout << "\n\tv1_double After removing an element from a Vector<double> at a 1 index :" << endl;
	v1_double.Print();
	cout << "\n\tv1_double size is " << v1_double.GetSize() << endl;
	//class Test
	v1_class.Remove(1);
	cout << "\n\tv1_class After removing an element from a Vector<class> at a 1 index :" << endl;
	v1_class.Print();
	cout << "\n\tv1_class size is " << v1_class.GetSize() << endl;

	//int
	v2_int.Remove(2);
	cout << "\n\tv2_int After removing an element from a Vector<int> at a 2 index :" << endl;
	v2_int.Print();
	cout << "\n\tv2_int size is " << v2_int.GetSize() << endl;
	//double
	v2_double.Remove(2);
	cout << "\n\tv2_double After removing an element from a Vector<double> at a 2 index :" << endl;
	v2_double.Print();
	cout << "\n\tv2_double size is " << v2_double.GetSize() << endl;
	//class Test
	v2_class.Remove(2);
	cout << "\n\tv2_class After removing an element from a Vector<class> at a 2 index :" << endl;
	v2_class.Print();
	cout << "\n\tv2_class size is " << v2_class.GetSize() << endl;

	//int
	v3_int.Remove(3);
	cout << "\n\tv3_int After removing an element from a Vector<int> at a 3 index :" << endl;
	v3_int.Print();
	cout << "\n\tv3_int size is " << v3_int.GetSize() << endl;
	//double
	v3_double.Remove(3);
	cout << "\n\tv3_double After removing an element from a Vector<double> at a 3 index :" << endl;
	v3_double.Print();
	cout << "\n\tv3_double size is " << v3_double.GetSize() << endl;
	//class Test
	v3_class.Remove(3);
	cout << "\n\tv3_class After removing an element from a Vector<class> at a 3 index :" << endl;
	v3_class.Print();
	cout << "\n\tv3_class size is " << v3_class.GetSize() << endl;

	//int
	Vector<int> v4_int = v3_int;
	//double
	Vector<double> v4_double = v3_double;
	//class Test
	Vector<Test> v4_class = v3_class;

	//int
	cout << "\n\tv3_int and v4_int After Vector<int> v4_int = v3_int :" << endl;
	cout << "\tv3_int addresses :" << &v3_int << '\t' << v3_int.GetVect() << endl;
	cout << "\tv4_int addresses :" << &v4_int << '\t' << v4_int.GetVect() << endl;
	//double
	cout << "\n\tv3_double and v4_double After Vector<double> v4_double = v3_double :" << endl;
	cout << "\tv3_double addresses :" << &v3_double << '\t' << v3_double.GetVect() << endl;
	cout << "\tv4_double addresses :" << &v4_double << '\t' << v4_double.GetVect() << endl;
	//class Test
	cout << "\n\tv3_class and v4_class After Vector<class> v4_class = v3_class :" << endl;
	cout << "\tv3_class addresses :" << &v3_class << '\t' << v3_class.GetVect() << endl;
	cout << "\tv4_class addresses :" << &v4_class << '\t' << v4_class.GetVect() << endl;

	//int
	cout << "\n\tv3_int :";
	cout << "\n\tv3_int size is " << v3_int.GetSize() << endl;
	v3_int.Print();
	cout << endl;
	//double
	cout << "\n\tv3_double :";
	cout << "\n\tv3_double size is " << v3_double.GetSize() << endl;
	v3_double.Print();
	cout << endl;
	//class Test
	cout << "\n\tv3_class :";
	cout << "\n\tv3_class size is " << v3_class.GetSize() << endl;
	v3_class.Print();
	cout << endl;

	//int
	cout << "\tv4_int :";
	cout << "\n\tv4_int size is " << v4_int.GetSize() << endl;
	v4_int.Print();
	cout << endl;
	cout << endl;
	//double
	cout << "\tv4_double :";
	cout << "\n\tv4_double size is " << v4_double.GetSize() << endl;
	v4_double.Print();
	cout << endl;
	cout << endl;
	//class Test
	cout << "\tv4_class :";
	cout << "\n\tv4_class size is " << v4_class.GetSize() << endl;
	v4_class.Print();
	cout << endl;
	cout << endl;

	//int
	cout << "\tarr_int address :" << &arr_int << endl;
	cout << "\tv1_int addresses :" << &v1_int << '\t' << v1_int.GetVect() << endl;
	cout << "\tv2_int addresses :" << &v2_int << '\t' << v2_int.GetVect() << endl;
	cout << "\tv3_int addresses :" << &v3_int << '\t' << v3_int.GetVect() << endl;
	cout << "\tv4_int addresses :" << &v4_int << '\t' << v4_int.GetVect() << endl;
	//double
	cout << "\tarr_double address :" << &arr_double << endl;
	cout << "\tv1_double addresses :" << &v1_double << '\t' << v1_double.GetVect() << endl;
	cout << "\tv2_double addresses :" << &v2_double << '\t' << v2_double.GetVect() << endl;
	cout << "\tv3_double addresses :" << &v3_double << '\t' << v3_double.GetVect() << endl;
	cout << "\tv4_double addresses :" << &v4_double << '\t' << v4_double.GetVect() << endl;
	//class Test
	cout << "\tarr_class address :" << &arr_class << endl;
	cout << "\tv1_class addresses :" << &v1_class << '\t' << v1_class.GetVect() << endl;
	cout << "\tv2_class addresses :" << &v2_class << '\t' << v2_class.GetVect() << endl;
	cout << "\tv3_class addresses :" << &v3_class << '\t' << v3_class.GetVect() << endl;
	cout << "\tv4_class addresses :" << &v4_class << '\t' << v4_class.GetVect() << endl;

	cout << endl;
	cout << "##########################################################################" << endl;
	cout << endl;

	// Увеличение всех компонент вектора на единицу (префикс).
	//int
	cout << "\tv5_int" << endl;
	Vector<int> v5_int{ 10 };
	v5_int.Input();
	v5_int.Print();
	++v5_int;
	cout << "\tAfter ++v5_int" << endl;
	v5_int.Print();
	cout << endl;
	//double
	cout << "\tv5_double" << endl;
	Vector<double> v5_double{ 10 };
	v5_double.Input();
	v5_double.Print();
	++v5_double;
	cout << "\tAfter ++v5_double" << endl;
	v5_double.Print();
	cout << endl;
	//class Test
	cout << "\tv5_class" << endl;
	Vector<Test> v5_class{ 10 };
	v5_class.Input();
	v5_class.Print();
	++v5_class;
	cout << "\tAfter ++v5_class" << endl;
	v5_class.Print();
	cout << endl;

	// Увеличение всех компонент вектора на единицу (постфикс).
	//int
	cout << "\tv6_int" << endl;
	Vector<int> v6_int{ 10 };
	v6_int.Input();
	v6_int.Print();
	v6_int++;
	cout << "\tAfter v6_int++" << endl;
	v6_int.Print();
	cout << endl;
	//double
	cout << "\tv6_double" << endl;
	Vector<double> v6_double{ 10 };
	v6_double.Input();
	v6_double.Print();
	v6_double++;
	cout << "After v6_double++" << endl;
	v6_double.Print();
	cout << endl;
	//class Test
	cout << "\tv6_class" << endl;
	Vector<Test> v6_class{ 10 };
	v6_class.Input();
	v6_class.Print();
	v6_class++;
	cout << "After v6_class++" << endl;
	v6_class.Print();
	cout << endl;

	// Уменьшение всех компонент вектора на	единицу (префикс).
	//int
	cout << "\tv7_int" << endl;
	Vector<int> v7_int{ 10 };
	v7_int.Input();
	v7_int.Print();
	--v7_int;
	cout << "\tAfter --v7_int" << endl;
	v7_int.Print();
	cout << endl;
	//double
	cout << "\tv7_double" << endl;
	Vector<double> v7_double{ 10 };
	v7_double.Input();
	v7_double.Print();
	--v7_double;
	cout << "\tAfter --v7_double" << endl;
	v7_double.Print();
	cout << endl;
	//class Test
	cout << "\tv7_class" << endl;
	Vector<Test> v7_class{ 10 };
	v7_class.Input();
	v7_class.Print();
	--v7_class;
	cout << "\tAfter --v7_class" << endl;
	v7_class.Print();
	cout << endl;

	// Уменьшение всех компонент вектора на единицу (постфикс).
	//int
	cout << "\tv8_int" << endl;
	Vector<int> v8_int{ 10 };
	v8_int.Input();
	v8_int.Print();
	v8_int--;
	cout << "\tAfter v8_int--" << endl;
	v8_int.Print();
	cout << endl;
	//double
	cout << "\tv8_double" << endl;
	Vector<double> v8_double{ 10 };
	v8_double.Input();
	v8_double.Print();
	v8_double--;
	cout << "\tAfter v8_double--" << endl;
	v8_double.Print();
	cout << endl;
	//class Test
	cout << "\tv8_class" << endl;
	Vector<Test> v8_class{ 10 };
	v8_class.Input();
	v8_class.Print();
	v8_class--;
	cout << "\tAfter v8_class--" << endl;
	v8_class.Print();
	cout << endl;

	// Перегруженный оператор присваивания с копированием.
	//int
	cout << "\tv9_int" << endl;
	Vector<int> v9_int{ 10 };
	v9_int.Input();
	v9_int.Print();
	Vector<int> v10_int = v9_int;
	cout << "\tv10_int = v9_int" << endl;
	v10_int.Print();
	cout << endl;
	//double
	cout << "\tv9_double" << endl;
	Vector<double> v9_double{ 10 };
	v9_double.Input();
	v9_double.Print();
	Vector<double> v10_double = v9_double;
	cout << "\tv10_double = v9_double" << endl;
	v10_double.Print();
	cout << endl;
	//class Test
	cout << "\tv9_class" << endl;
	Vector<Test> v9_class{ 10 };
	v9_class.Input();
	v9_class.Print();
	Vector<Test> v10_class = v9_class;
	cout << "\tv10_class = v9_class" << endl;
	v10_class.Print();
	cout << endl;

	// Перегруженный оператор индексации.
	//int
	cout << "\tv11_int" << endl;
	Vector<int> v11_int{ 10 };
	v11_int.Input();
	v11_int.Print();
	v11_int[3] = 999;
	cout << "\tv11_int[3] = 999" << endl;
	v11_int.Print();
	cout << endl;
	//double
	cout << "\tv11_double" << endl;
	Vector<double> v11_double{ 10 };
	v11_double.Input();
	v11_double.Print();
	v11_double[3] = 999;
	cout << "\tv11_double[3] = 999" << endl;
	v11_double.Print();
	cout << endl;
	//class Test
	cout << "\tv11_class" << endl;
	Vector<Test> v11_class{ 10 };
	v11_class.Input();
	v11_class.Print();
	v11_class[3] = 999;
	cout << "\tv11_class[3] = 999" << endl;
	v11_class.Print();
	cout << endl;

	// Сложение двух векторов.
	//int
	cout << "\tv12_int" << endl;
	Vector<int> v12_int{ 10 };
	v12_int.Input();
	v12_int.Print();
	cout << "\tv13_int" << endl;
	Vector<int> v13_int{ 7 };
	v13_int.Input();
	v13_int.Print();
	Vector<int> v14_int;
	v14_int = v12_int + v13_int;
	cout << "\tv14_int = v12_int + v13_int" << endl;
	v14_int.Print();
	cout << endl;
	//double
	cout << "\tv12_double" << endl;
	Vector<double> v12_double{ 10 };
	v12_double.Input();
	v12_double.Print();
	cout << "\tv13_double" << endl;
	Vector<double> v13_double{ 7 };
	v13_double.Input();
	v13_double.Print();
	Vector<double> v14_double;
	v14_double = v12_double + v13_double;
	cout << "\tv14_double = v12_double + v13_double" << endl;
	v14_double.Print();
	cout << endl;
	//class Test
	cout << "\tv12_class" << endl;
	Vector<Test> v12_class{ 10 };
	v12_class.Input();
	v12_class.Print();
	cout << "\tv13_class" << endl;
	Vector<Test> v13_class{ 7 };
	v13_class.Input();
	v13_class.Print();
	Vector<Test> v14_class;
	v14_class = v12_class + v13_class;
	cout << "\tv14_class = v12_class + v13_class" << endl;
	v14_class.Print();
	cout << endl;

	// Сложение вектора с числом (каждый компонент вектора складывается с числом).
	//int
	Vector<int> v15_int{ 10 };
	v15_int.Input();
	cout << "\tv15_int" << endl;
	v15_int.Print();
	int number0{ 9 }; // Число для складываня с компонентами вектора.
	v15_int = v15_int + number0;
	cout << "\tv15_int = v15_int + number0(number0 = 9)" << endl;
	v15_int.Print();
	cout << endl;
	//double
	Vector<int> v15_double{ 10 };
	v15_double.Input();
	cout << "\tv15_double" << endl;
	v15_double.Print();
	int number1{ 9 }; // Число для складываня с компонентами вектора.
	v15_double = v15_double + number1;
	cout << "\tv15_double = v15_double + number1(number1 = 9)" << endl;
	v15_double.Print();
	cout << endl;
	//class Test
	Vector<Test> v15_class{ 10 };
	v15_class.Input();
	cout << "\tv15_class" << endl;
	v15_class.Print();
	int number11{ 9 }; // Число для складываня с компонентами вектора.
	v15_class = v15_class + number11;
	cout << "\tv15_class = v15_class + number1(number11 = 9)" << endl;
	v15_double.Print();
	cout << endl;

	// Перегруженный оператор += для сложения двух векторов.
	//int
	Vector<int> v16_int{ 10 };
	v16_int.Input();
	cout << "\tv16" << endl;
	v16_int.Print();
	Vector<int> v17_int{ 10 };
	v17_int.Input();
	cout << "\tv17_int" << endl;
	v17_int.Print();
	v16_int += v17_int;
	cout << "\tv16_int += v17_int" << endl;
	v16_int.Print();
	cout << endl;
	//double
	Vector<double> v16_double{ 10 };
	v16_double.Input();
	cout << "\tv16" << endl;
	v16_double.Print();
	Vector<double> v17_double{ 10 };
	v17_double.Input();
	cout << "\tv17_double" << endl;
	v17_double.Print();
	v16_double += v17_double;
	cout << "\tv16_double += v17_double" << endl;
	v16_double.Print();
	cout << endl;
	//class Test
	Vector<Test> v16_class{ 10 };
	v16_class.Input();
	cout << "\tv16" << endl;
	v16_class.Print();
	Vector<Test> v17_class{ 10 };
	v17_class.Input();
	cout << "\tv17_class" << endl;
	v17_class.Print();
	v16_class += v17_class;
	cout << "\tv16_class += v17_class" << endl;
	v16_class.Print();
	cout << endl;

	// Вычитание двух векторов.
	//int
	Vector<int> v18_int{ 7 };
	v18_int.Input();
	cout << "\tv18_int" << endl;
	v18_int.Print();
	Vector<int> v19_int{ 10 };
	v19_int.Input();
	cout << "\tv19_int" << endl;
	v19_int.Print();
	Vector<int> v20_int{ 10 };
	v20_int = v18_int - v19_int;
	cout << "\tv20_int = v18_int - v19_int" << endl;
	v20_int.Print();
	cout << endl;
	//double
	Vector<double> v18_double{ 7 };
	v18_double.Input();
	cout << "\tv18_double" << endl;
	v18_double.Print();
	Vector<double> v19_double{ 10 };
	v19_double.Input();
	cout << "\tv19_double" << endl;
	v19_double.Print();
	Vector<double> v20_double{ 10 };
	v20_double = v18_double - v19_double;
	cout << "\tv20_double = v18_double - v19_double" << endl;
	v20_double.Print();
	cout << endl;
	//class Test
	Vector<Test> v18_class{ 7 };
	v18_class.Input();
	cout << "\tv18_class" << endl;
	v18_class.Print();
	Vector<Test> v19_class{ 10 };
	v19_class.Input();
	cout << "\tv19_class" << endl;
	v19_class.Print();
	Vector<Test> v20_class{ 10 };
	v20_class = v18_class - v19_class;
	cout << "\tv20_class = v18_class - v19_class" << endl;
	v20_class.Print();
	cout << endl;

	// Вычитание числа из вектора (из каждого компонента вектора вычитывается число).
	//int
	Vector<int> v21_int{ 10 };
	v21_int.Input();
	cout << "\tv21_int" << endl;
	v21_int.Print();
	int number2{ 9 }; // Число для вычитания с компонентами вектора.
	v21_int = v21_int - number2;
	cout << "\tv21_int = v21_int - number2(number2 = 9)" << endl;
	v21_int.Print();
	cout << endl;
	//double
	Vector<double> v21_double{ 10 };
	v21_double.Input();
	cout << "\tv21_double" << endl;
	v21_double.Print();
	int number3{ 9 }; // Число для вычитания с компонентами вектора.
	v21_double = v21_double - number3;
	cout << "\tv21_double = v21_double - number3(number3 = 9)" << endl;
	v21_double.Print();
	cout << endl;
	//class Test
	Vector<Test> v21_class{ 10 };
	v21_class.Input();
	cout << "\tv21_class" << endl;
	v21_class.Print();
	int number33{ 9 }; // Число для вычитания с компонентами вектора.
	v21_class = v21_class - number33;
	cout << "\tv21_class = v21_class - number33(number33 = 9)" << endl;
	v21_class.Print();
	cout << endl;

	// Перегруженный оператор -= для вычитания двух векторов.
	//int
	Vector<int> v22_int{ 7 };
	v22_int.Input();
	cout << "\tv22_int" << endl;
	v22_int.Print();
	Vector<int> v23_int{ 10 };
	v23_int.Input();
	cout << "\tv23_int" << endl;
	v23_int.Print();
	v22_int -= v23_int;
	cout << "\tv22_int -= v23_int" << endl;
	v22_int.Print();
	cout << endl;
	//double
	Vector<double> v22_double{ 7 };
	v22_double.Input();
	cout << "\tv22_double" << endl;
	v22_double.Print();
	Vector<double> v23_double{ 10 };
	v23_double.Input();
	cout << "\tv23_double" << endl;
	v23_double.Print();
	v22_double -= v23_double;
	cout << "\tv22_double -= v23_double" << endl;
	v22_double.Print();
	cout << endl;
	//class Test
	Vector<Test> v22_class{ 7 };
	v22_class.Input();
	cout << "\tv22_class" << endl;
	v22_class.Print();
	Vector<Test> v23_class{ 10 };
	v23_class.Input();
	cout << "\tv23_class" << endl;
	v23_class.Print();
	v22_class -= v23_class;
	cout << "\tv22_class -= v23_class" << endl;
	v22_class.Print();
	cout << endl;

	// Умножение векторов.
	//int
	Vector<int> v24_int{ 7 };
	v24_int.Input();
	cout << "\tv24_int" << endl;
	v24_int.Print();
	Vector<int> v25_int{ 10 };
	v25_int.Input();
	cout << "\tv25_int" << endl;
	v25_int.Print();
	Vector<int> v26_int{ 10 };
	v26_int = v24_int * v25_int;
	cout << "\tv26_int = v24_int * v25_int" << endl;
	v26_int.Print();
	cout << endl;
	//double
	Vector<double> v24_double{ 7 };
	v24_double.Input();
	cout << "\tv24_double" << endl;
	v24_double.Print();
	Vector<double> v25_double{ 10 };
	v25_double.Input();
	cout << "\tv25_double" << endl;
	v25_double.Print();
	Vector<double> v26_double{ 10 };
	v26_double = v24_double * v25_double;
	cout << "\tv26_double = v24_double * v25_double" << endl;
	v26_double.Print();
	cout << endl;
	//class Test
	Vector<Test> v24_class{ 7 };
	v24_class.Input();
	cout << "\tv24_class" << endl;
	v24_class.Print();
	Vector<Test> v25_class{ 10 };
	v25_class.Input();
	cout << "\tv25_class" << endl;
	v25_class.Print();
	Vector<Test> v26_class{ 10 };
	v26_class = v24_class * v25_class;
	cout << "\tv26_class = v24_class * v25_class" << endl;
	v26_class.Print();
	cout << endl;

	// Умножение вектора на число (каждый компонент вектора умножается на число).
	//int
	Vector<int> v27_int{ 10 };
	v27_int.Input();
	cout << "\tv27_int" << endl;
	v27_int.Print();
	int number4{ 9 }; // Число для умножения с компонентами вектора.
	v27_int = v27_int * number4;
	cout << "\tv27_int = v27_int * number4(number4 = 9)" << endl;
	v27_int.Print();
	cout << endl;
	//double
	Vector<double> v27_double{ 10 };
	v27_double.Input();
	cout << "\tv27_double" << endl;
	v27_double.Print();
	int number5{ 9 }; // Число для умножения с компонентами вектора.
	v27_double = v27_double * number5;
	cout << "\tv27_double = v27_double * number5(number5 = 9)" << endl;
	v27_double.Print();
	cout << endl;
	//class Test
	Vector<Test> v27_class{ 10 };
	v27_class.Input();
	cout << "\tv27_class" << endl;
	v27_class.Print();
	int number55{ 9 }; // Число для умножения с компонентами вектора.
	v27_class = v27_class * number55;
	cout << "\tv27_class = v27_class * number55(number55 = 9)" << endl;
	v27_class.Print();
	cout << endl;

	// Перегруженный оператор *= для умножения вектора на число.
	//int
	Vector<int> v28_int{ 7 };
	v28_int.Input();
	cout << "\tv28_int" << endl;
	v28_int.Print();
	int number6{ 9 }; // Число для умножения с компонентами вектора.
	v28_int *= number6;
	cout << "\tv28_int *= number6(number6 = 9)" << endl;
	v28_int.Print();
	cout << endl;
	//double
	Vector<double> v28_double{ 7 };
	v28_double.Input();
	cout << "\tv28_double" << endl;
	v28_double.Print();
	int number7{ 9 }; // Число для умножения с компонентами вектора.
	v28_double *= number7;
	cout << "\tv28_double *= number7(number7 = 9)" << endl;
	v28_double.Print();
	cout << endl;
	//class Test
	Vector<Test> v28_class{ 7 };
	v28_class.Input();
	cout << "\tv28_class" << endl;
	v28_class.Print();
	int number77{ 9 }; // Число для умножения с компонентами вектора.
	v28_class *= number7;
	cout << "\tv28_class *= number77(number77 = 9)" << endl;
	v28_class.Print();
	cout << endl;

	// Перегруженный оператор >>. Ввод вектора с клавиатуры.
	//int
	Vector<int> v29_int{ 5 };
	cout << "\tEnter Vector<int>:";
	cin >> v29_int;
	//double
	Vector<double> v29_double{ 5 };
	cout << "\tEnter Vector<double>:";
	cin >> v29_double;
	//class Test
	Vector<Test> v29_class{ 5 };
	cout << "\tEnter Vector<class>:";
	cin >> v29_class;

	// Перегруженный оператор <<. Вывод вектора на экран.
	//int
	cout << "\tv29_int"
		<< v29_int;
	//double
	cout << "\tv29_double"
		<< v29_double;
	//class Test
	cout << "\tv29_class"
		<< v29_class;

	// Реализация семантики переноса с использованием r-value ссылок.
	// Конструктор переноса.
	//int
	Vector<int> v30_int{ 10 };
	cout << "\tv30_int";
	cout << v30_int;
	Vector<int> v31_int{ 10 };
	cout << "\tv31_int";
	cout << v31_int;
	Vector<int> v32_int = v30_int + v31_int; // Вызов конструктора переноса.
	cout << "\tVector<int> v32_int = v30_int + v31_int";
	cout << v32_int;
	//double
	Vector<double> v30_double{ 10 };
	cout << "\tv30_double";
	cout << v30_double;
	Vector<double> v31_double{ 10 };
	cout << "\tv31_double";
	cout << v31_double;
	Vector<double> v32_double = v30_double + v31_double; // Вызов конструктора переноса.
	cout << "\tVector<double> v32_double = v30_double + v31_double";
	cout << v32_double;
	//class Test
	Vector<Test> v30_class{ 10 };
	cout << "\tv30_class";
	cout << v30_class;
	Vector<Test> v31_class{ 10 };
	cout << "\tv31_class";
	cout << v31_class;
	Vector<Test> v32_class = v30_class + v31_class; // Вызов конструктора переноса.
	cout << "\tVector<class> v32_class = v30_class + v31_class";
	cout << v32_class;

	// Реализация семантики переноса с использованием r-value ссылок.
	// Перегруженный оператор присваивания с переносом.
	//int
	Vector<int> v33_int{ 10 };
	cout << "\tv33_int";
	cout << v33_int;
	Vector<int> v34_int{ 10 };
	cout << "\tv34_int";
	cout << v34_int;
	Vector<int> v35_int{ 10 };
	v35_int = v33_int + v34_int; // Присваивание с переносом.
	cout << "\tVector<int> v35_int = v33_int + v34_int";
	cout << v35_int;
	//double
	Vector<double> v33_double{ 10 };
	cout << "\tv33_double";
	cout << v33_double;
	Vector<double> v34_double{ 10 };
	cout << "\tv34_double";
	cout << v34_double;
	Vector<double> v35_double{ 10 };
	v35_double = v33_double + v34_double; // Присваивание с переносом.
	cout << "\tVector<double> v35_double = v33_double + v34_double";
	cout << v35_double;
	//class Test
	Vector<Test> v33_class{ 10 };
	cout << "\tv33_class";
	cout << v33_class;
	Vector<Test> v34_class{ 10 };
	cout << "\tv34_class";
	cout << v34_class;
	Vector<Test> v35_class{ 10 };
	v35_class = v33_class + v34_class; // Присваивание с переносом.
	cout << "\tVector<class> v35_class = v33_class + v34_class";
	cout << v35_class;

	delete[]arr_int;
	delete[]arr_double;
	delete[]arr_class;
}