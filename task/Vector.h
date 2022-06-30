#pragma once
#include <iostream>
using std::istream;
using std::ostream;

class Vector
{
	// Вектор.
	int* m_vect;
	// Размерность вектора.
	int m_size;
public:
	// Методы-аксессоры:
	// Инспекторы (позволяют получить значения полей).
	int GetSize() const;
	int* GetVect() const;

	// Функции - члены(методы) :	
	Vector();							// Конструктор по умолчанию.	
	explicit Vector(int size);			// Конструктор, позволяющий задавать размерность вектора. explicit - препятствует выполнению неявных преобразований.	
	Vector(const int* ptr, int size);	// Конструктор, позволяющий проинициализировать вектор с помощью существующего массива.
	Vector(const Vector& v);			// Конструктор копирования.

	// Реализация семантики переноса с использованием r-value ссылок.
	// Конструктор переноса.
	Vector(Vector&& v);

	// Деструктор.
	~Vector();

	Vector& operator ++ ();				// Увеличение всех компонент вектора на единицу (префикс).	
	Vector operator ++ (int postfix);	// Увеличение всех компонент вектора на единицу (постфикс).	
	Vector& operator -- ();				// Уменьшение всех компонент вектора на	единицу (префикс).	
	Vector operator -- (int postfix);	// Уменьшение всех компонент вектора на единицу (постфикс).	

	// Перегруженный оператор присваивания с копированием.
	Vector& operator = (const Vector& v);

	// Реализация семантики переноса с использованием r-value ссылок.
	// Перегруженный оператор присваивания с переносом.
	Vector& operator = (Vector&& v);

	// Перегруженный оператор индексации.
	int& operator [] (int index);

	// Сложение двух векторов.
	Vector operator + (const Vector& v);

	// Сложение вектора с числом (каждый компонент вектора складывается с числом).
	Vector operator + (int n);

	// Перегруженный оператор += для сложения двух векторов.
	Vector& operator += (const Vector& v);

	// Вычитание двух векторов.
	Vector operator - (const Vector& v);

	// Вычитание числа из вектора (из каждого компонента вектора вычитывается число).
	Vector operator - (int n);

	// Перегруженный оператор -= для вычитания двух векторов.
	Vector& operator -= (const Vector& v);

	// Умножение векторов.
	Vector operator * (const Vector& v);

	// Умножение вектора на число (каждый компонент вектора умножается на число).
	Vector operator * (int n);

	// Перегруженный оператор *= для умножения вектора на число.
	Vector& operator *= (int n);

	// Перегруженный оператор >>. Ввод вектора с клавиатуры.
	friend istream& operator >> (istream& cin, Vector& v);

	// Перегруженный оператор <<. Вывод вектора на экран.
	friend ostream& operator << (ostream& cout, Vector& v);

	// Метод вывода на экран.
	void Print() const;

	// Метод заполнения вектора.
	void Input();

	// Метод очистки вектора (заполнет все элементы нулями).
	void Clear();

	// Метод возвращает истину, если вектор пустой (m_size <= 0).
	bool IsEmpty() const;

	// Метод добавления элемента в вектор.
	void Add(const int& item);

	// Метод вставки элемента в вектор по заданному индексу.
	void Insert(int index, const int& item);

	// Метод удаления элемента из вектора по заданному индексу.
	void Remove(int index);
};

// Перегруженный оператор >>. Ввод вектора с клавиатуры.
istream& operator >> (istream& cin, Vector& v);

// Перегруженный оператор <<. Вывод вектора на экран.
ostream& operator << (ostream& cout, Vector& v);