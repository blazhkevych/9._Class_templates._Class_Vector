/*
############################################ ЗАДАНИЕ ###########################################
			Шаблонный класс «Вектор»
	Реализовать разработанный ранее класс «Вектор» в виде
шаблонного класса. В клиентской части программы
продемонстрировать работу всех методов класса. При создании
объектов шаблонного класса важно типизировать шаблон
разными типами данных (стандартными и пользовательскими).
################################################################################################
		СТАТУС : Не готово.
		ДОРАБОТКИ:
*
		ИЗВЕСТНЫЕ ОШИБКИ:
*
		ПРОТЕСТИРОВАТЬ:
*
		ВОПРОСЫ:
*
		ВИДЕО: 02:37:15 (начало дз)
################################################################################################
*/

#include <iostream>
#include "Vector.h"
using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;

int main()
{
	srand(time(0));
	int size{ 5 };
	int* arr = new int[size] {1, 2, 3, 4, 5}; // Массив для инициализации.
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	Vector v1;
	Vector v2{ 3 };
	Vector v3{ arr, size };


	cout << "\nv1 size is " << v1.GetSize() << endl;
	cout << "\nv2 size is " << v2.GetSize() << endl;
	cout << "\nv3 size is " << v3.GetSize() << endl;

	cout << "\nv1 IsEmpty - " << boolalpha << v1.IsEmpty() << endl;
	cout << "\nv2 IsEmpty - " << boolalpha << v2.IsEmpty() << endl;
	cout << "\nv3 IsEmpty - " << boolalpha << v3.IsEmpty() << endl;

	cout << "\nv1 :" << endl;
	v1.Print();
	cout << endl;
	cout << "v2 :" << endl;
	v2.Print();
	cout << endl;
	cout << "v3 :" << endl;
	v3.Print();
	cout << endl;

	v1.Add(111);
	v1.Add(111);
	v2.Add(222);
	v2.Add(222);
	v3.Add(333);
	v3.Add(333);
	cout << "\nv1 After adding 2 elements to the vector :" << endl;
	v1.Print();
	cout << "\nv2 After adding 2 elements to the vector :" << endl;
	v2.Print();
	cout << "\nv3 After adding 2 elements to the vector :" << endl;
	v3.Print();

	v1.Clear();
	v2.Clear();
	v3.Clear();
	cout << "\nv1 After clearing the vector :" << endl;
	v1.Print();
	cout << "\nv2 After clearing the vector :" << endl;
	v2.Print();
	cout << "\nv3 After clearing the vector :" << endl;
	v3.Print();

	v1.Input();
	v2.Input();
	v3.Input();
	cout << "\nv1 After filling the vector :" << endl;
	v1.Print();
	cout << "\nv2 After filling the vector :" << endl;
	v2.Print();
	cout << "\nv3 After filling the vector :" << endl;
	v3.Print();

	cout << "\nv1 IsEmpty - " << boolalpha << v1.IsEmpty() << endl;
	cout << "\nv2 IsEmpty - " << boolalpha << v2.IsEmpty() << endl;
	cout << "\nv3 IsEmpty - " << boolalpha << v3.IsEmpty() << endl;

	cout << "\nv1 After inserting the 111111 into the vector at the 1 index :" << endl;
	v1.Insert(1, 111111);
	v1.Print();
	cout << "\nv1 size is " << v1.GetSize() << endl;

	cout << "\nv2 After inserting the 222222 into the vector at the 2 index :" << endl;
	v2.Insert(2, 222222);
	v2.Print();
	cout << "\nv2 size is " << v2.GetSize() << endl;

	cout << "\nv2 After inserting the 333333 into the vector at the 3 index :" << endl;
	v3.Insert(3, 333333);
	v3.Print();
	cout << "\nv3 size is " << v3.GetSize() << endl;

	v1.Remove(1);
	cout << "\nv1 After removing an element from a vector at a 1 index :" << endl;
	v1.Print();
	cout << "\nv1 size is " << v1.GetSize() << endl;

	v2.Remove(2);
	cout << "\nv2 After removing an element from a vector at a 2 index :" << endl;
	v2.Print();
	cout << "\nv2 size is " << v2.GetSize() << endl;

	v3.Remove(3);
	cout << "\nv3 After removing an element from a vector at a 3 index :" << endl;
	v3.Print();
	cout << "\nv3 size is " << v3.GetSize() << endl;

	Vector v4 = v3;

	cout << "\nv3 and v4 After Vector v4 = v3 :" << endl;
	cout << "v3 addresses :" << &v3 << '\t' << v3.GetVect() << endl;
	cout << "v4 addresses :" << &v4 << '\t' << v4.GetVect() << endl;

	cout << "\nv3 :";
	cout << "\nv3 size is " << v3.GetSize() << endl;
	v3.Print();
	cout << endl;

	cout << "v4 :";
	cout << "\nv4 size is " << v4.GetSize() << endl;
	v4.Print();
	cout << endl;
	cout << endl;

	cout << "arr address :" << &arr << endl;
	cout << "v1 addresses :" << &v1 << '\t' << v1.GetVect() << endl;
	cout << "v2 addresses :" << &v2 << '\t' << v2.GetVect() << endl;
	cout << "v3 addresses :" << &v3 << '\t' << v3.GetVect() << endl;
	cout << "v4 addresses :" << &v4 << '\t' << v4.GetVect() << endl;

	cout << endl;
	cout << "##########################################################################" << endl;
	cout << endl;

	// Увеличение всех компонент вектора на единицу (префикс).
	cout << "v5" << endl;
	Vector v5{ 10 };
	v5.Input();
	v5.Print();
	++v5;
	cout << "After ++v5" << endl;
	v5.Print();
	cout << endl;

	// Увеличение всех компонент вектора на единицу (постфикс).
	cout << "v6" << endl;
	Vector v6{ 10 };
	v6.Input();
	v6.Print();
	v6++;
	cout << "After v6++" << endl;
	v6.Print();
	cout << endl;

	// Уменьшение всех компонент вектора на	единицу (префикс).
	cout << "v7" << endl;
	Vector v7{ 10 };
	v7.Input();
	v7.Print();
	--v7;
	cout << "After --v7" << endl;
	v7.Print();
	cout << endl;

	// Уменьшение всех компонент вектора на единицу (постфикс).
	cout << "v8" << endl;
	Vector v8{ 10 };
	v8.Input();
	v8.Print();
	v8--;
	cout << "After v8--" << endl;
	v8.Print();
	cout << endl;

	// Перегруженный оператор присваивания с копированием.
	cout << "v9" << endl;
	Vector v9{ 10 };
	v9.Input();
	v9.Print();
	Vector v10 = v9;
	cout << "v10 = v9" << endl;
	v10.Print();
	cout << endl;

	// Перегруженный оператор индексации.
	cout << "v11" << endl;
	Vector v11{ 10 };
	v11.Input();
	v11.Print();
	v11[3] = 999;
	cout << "v11[3] = 999" << endl;
	v11.Print();
	cout << endl;

	// Сложение двух векторов.
	cout << "v12" << endl;
	Vector v12{ 10 };
	v12.Input();
	v12.Print();
	cout << "v13" << endl;
	Vector v13{ 7 };
	v13.Input();
	v13.Print();
	Vector v14;
	v14 = v12 + v13;
	cout << "v14 = v12 + v13" << endl;
	v14.Print();
	cout << endl;

	// Сложение вектора с числом (каждый компонент вектора складывается с числом).
	Vector v15{ 10 };
	v15.Input();
	cout << "v15" << endl;
	v15.Print();
	int number{ 9 }; // Число для складываня с компонентами вектора.
	v15 = v15 + number;
	cout << "v15 = v15 + number(number = 9)" << endl;
	v15.Print();
	cout << endl;

	// Перегруженный оператор += для сложения двух векторов.
	Vector v16{ 10 };
	v16.Input();
	cout << "v16" << endl;
	v16.Print();
	Vector v17{ 10 };
	v17.Input();
	cout << "v17" << endl;
	v17.Print();
	v16 += v17;
	cout << "v16 += v17" << endl;
	v16.Print();
	cout << endl;

	// Вычитание двух векторов.
	Vector v18{ 7 };
	v18.Input();
	cout << "v18" << endl;
	v18.Print();
	Vector v19{ 10 };
	v19.Input();
	cout << "v19" << endl;
	v19.Print();
	Vector v20{ 10 };
	v20 = v18 - v19;
	cout << "v20 = v18 - v19" << endl;
	v20.Print();
	cout << endl;

	// Вычитание числа из вектора (из каждого компонента вектора вычитывается число).
	Vector v21{ 10 };
	v21.Input();
	cout << "v21" << endl;
	v21.Print();
	int number2{ 9 }; // Число для вычитания с компонентами вектора.
	v21 = v21 - number;
	cout << "v21 = v21 - number2(number2 = 9)" << endl;
	v21.Print();
	cout << endl;

	// Перегруженный оператор -= для вычитания двух векторов.
	Vector v22{ 7 };
	v22.Input();
	cout << "v22" << endl;
	v22.Print();
	Vector v23{ 10 };
	v23.Input();
	cout << "v23" << endl;
	v23.Print();
	v22 -= v23;
	cout << "v22 -= v23" << endl;
	v22.Print();
	cout << endl;

	// Умножение векторов.
	Vector v24{ 7 };
	v24.Input();
	cout << "v24" << endl;
	v24.Print();
	Vector v25{ 10 };
	v25.Input();
	cout << "v25" << endl;
	v25.Print();
	Vector v26{ 10 };
	v26 = v24 * v25;
	cout << "v26 = v24 * v25" << endl;
	v26.Print();
	cout << endl;

	// Умножение вектора на число (каждый компонент вектора умножается на число).
	Vector v27{ 10 };
	v27.Input();
	cout << "v27" << endl;
	v27.Print();
	int number3{ 9 }; // Число для умножения с компонентами вектора.
	v27 = v27 * number3;
	cout << "v27 = v27 * number3(number3 = 9)" << endl;
	v27.Print();
	cout << endl;

	// Перегруженный оператор *= для умножения вектора на число.
	Vector v28{ 7 };
	v28.Input();
	cout << "v28" << endl;
	v28.Print();
	int number4{ 9 }; // Число для умножения с компонентами вектора.
	v28 *= number4;
	cout << "v28 *= number4(number4 = 9)" << endl;
	v28.Print();
	cout << endl;

	// Перегруженный оператор >>. Ввод вектора с клавиатуры.
	Vector v29{ 5 };
	cout << "Enter vector:";
	cin >> v29;

	// Перегруженный оператор <<. Вывод вектора на экран.
	cout << "v29"
		<< v29;

	// Реализация семантики переноса с использованием r-value ссылок.
	// Конструктор переноса.
	Vector v30{ 10 };
	cout << "v30";
	cout << v30;
	Vector v31{ 10 };
	cout << "v31";
	cout << v31;
	Vector v32 = v30 + v31; // Вызов конструктора переноса.
	cout << "Vector v32 = v30 + v31";
	cout << v32;

	// Реализация семантики переноса с использованием r-value ссылок.
	// Перегруженный оператор присваивания с переносом.
	Vector v33{ 10 };
	cout << "v33";
	cout << v33;
	Vector v34{ 10 };
	cout << "v34";
	cout << v34;
	Vector v35{ 10 };
	v35 = v33 + v34; // Присваивание с переносом.
	cout << "Vector v35 = v33 + v34";
	cout << v35;

	delete[]arr;

	cout << endl;
	cout << "##########################################################################" << endl;
	cout << endl;


}