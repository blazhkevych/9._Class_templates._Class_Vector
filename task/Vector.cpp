#include <iostream>
#include "Vector.h"
using std::cout;
using std::endl;

// Конструктор по умолчанию.
Vector::Vector()
{
	m_vect = nullptr;
	m_size = 0;
}

// Конструктор, позволяющий задавать размерность вектора.
Vector::Vector(int size)
{
	m_size = size;
	m_vect = new int[m_size];
	int min = 10; // Минимальное значение.
	int max = 99; // Максимальное значение.
	for (int i = 0; i < size; i++) // Заполняем одномерный массив псевдослучайными числами.
		m_vect[i] = rand() % (max - min + 1) + min;
}

// Конструктор, позволяющий проинициализировать вектор с помощью существующего массива.
Vector::Vector(const int* ptr, int size)
{
	m_size = size;
	m_vect = new int[m_size];
	for (int i = 0; i < m_size; i++)
		m_vect[i] = ptr[i];
}

// Конструктор копирования.
Vector::Vector(const Vector& v)
{
	int size = v.GetSize();
	m_vect = new int[size];
	for (int i = 0; i < size; i++)
		m_vect[i] = v.m_vect[i];
	m_size = v.GetSize();
}

// Реализация семантики переноса с использованием r-value ссылок.
// Конструктор переноса.
Vector::Vector(Vector&& v)
{
	m_vect = v.m_vect;
	m_size = v.m_size;
	v.m_vect = nullptr;
}

// Деструктор.
Vector::~Vector()
{
	delete[] m_vect;
}

// Увеличение всех компонент вектора на единицу (префикс).
Vector& Vector::operator++()
{
	//this->m_val++;
	for (int i = 0; i < m_size; i++)
		m_vect[i]++;
	return *this;
}

// Увеличение всех компонент вектора на единицу (постфикс).
Vector Vector::operator++(int postfix)
{
	Vector tmp = *this;
	for (int i = 0; i < m_size; i++)
		m_vect[i]++;
	return tmp;
}

// Уменьшение всех компонент вектора на	единицу (префикс).
Vector& Vector::operator--()
{
	for (int i = 0; i < m_size; i++)
		m_vect[i]--;
	return *this;
}

// Уменьшение всех компонент вектора на единицу (постфикс).
Vector Vector::operator--(int postfix)
{
	Vector tmp = *this;
	for (int i = 0; i < m_size; i++)
		m_vect[i]--;
	return tmp;
}

// Перегруженный оператор присваивания с копированием.
Vector& Vector::operator=(const Vector& v)
{
	if (this == &v)
		return *this;
	delete[] this->m_vect;
	this->m_vect = new int[v.m_size];
	this->m_size = v.m_size;
	for (int i = 0; i < this->m_size; ++i)
	{
		this->m_vect[i] = v.m_vect[i];
	}
	return *this;
}

// Реализация семантики переноса с использованием r-value ссылок.
// Перегруженный оператор присваивания с переносом.
Vector& Vector::operator=(Vector&& v)
{
	if (this == &v)
		return *this;
	delete[] m_vect;
	m_vect = v.m_vect;
	v.m_vect = nullptr;

	return *this;
}

// Функция возвращает размерность вектора.
int Vector::GetSize() const
{
	return m_size;
}

// Функция возвращает адрес вектора.
int* Vector::GetVect() const
{
	return m_vect;
}

// Перегруженный оператор индексации.
int& Vector::operator[](int index)
{
	if (index < 0 || index >= m_size)
		return m_vect[0];
	return m_vect[index];
}

// Сложение двух векторов.
Vector Vector::operator+(const Vector& v)
{
	int sizeLess = m_size < v.m_size ? m_size : v.m_size;	// Вычисляем вектор с меньшей размерностью.
	int sizeBigger = m_size > v.m_size ? m_size : v.m_size;	// Вычисляем вектор с большей размерностью.
	Vector result{ sizeBigger };
	result.Clear();
	for (int i = 0; i < sizeBigger; i++)
		if (i >= sizeLess)
		{
			result[i] = (*(this->m_vect + i)) > (*(v.GetVect() + i)) ? (*(this->m_vect + i)) : (*(v.GetVect() + i));
		}
		else
			result[i] = *(this->m_vect + i) + *(v.GetVect() + i);

	return result;
}

// Сложение вектора с числом (каждый компонент вектора складывается с числом).
Vector Vector::operator+(int n)
{
	Vector result{ m_size };
	result.Clear();
	for (int i = 0; i < m_size; i++)
		result[i] = (*(this->m_vect + i)) + n;
	return result;
}

// Перегруженный оператор += для сложения двух векторов.
Vector& Vector::operator+=(const Vector& v)
{
	*this = this->operator+(v);

	return *this;
}

// Вычитание двух векторов.
Vector Vector::operator-(const Vector& v)
{
	int sizeLess = m_size < v.m_size ? m_size : v.m_size;	// Вычисляем вектор с меньшей размерностью.
	int sizeBigger = m_size > v.m_size ? m_size : v.m_size;	// Вычисляем вектор с большей размерностью.
	Vector result{ sizeBigger };
	result.Clear();
	for (int i = 0; i < sizeBigger; i++)
		if (i >= sizeLess)
		{
			result[i] = (*(this->m_vect + i)) > (*(v.GetVect() + i)) ? (*(this->m_vect + i)) : (*(v.GetVect() + i));
		}
		else
			result[i] = *(this->m_vect + i) - *(v.GetVect() + i);

	return result;
}

// Вычитание числа из вектора (из каждого компонента вектора вычитывается число).
Vector Vector::operator-(int n)
{
	Vector result{ m_size };
	result.Clear();
	for (int i = 0; i < m_size; i++)
		result[i] = (*(this->m_vect + i)) - n;
	return result;
}

// Перегруженный оператор -= для вычитания двух векторов.
Vector& Vector::operator-=(const Vector& v)
{
	return *this = this->operator-(v);
}

// Умножение векторов.
Vector Vector::operator*(const Vector& v)
{
	int sizeLess = m_size < v.m_size ? m_size : v.m_size;	// Вычисляем вектор с меньшей размерностью.
	int sizeBigger = m_size > v.m_size ? m_size : v.m_size;	// Вычисляем вектор с большей размерностью.
	Vector result{ sizeBigger };
	result.Clear();
	for (int i = 0; i < sizeBigger; i++)
		if (i >= sizeLess)
		{
			result[i] = (*(this->m_vect + i)) > (*(v.GetVect() + i)) ? (*(this->m_vect + i)) : (*(v.GetVect() + i));
		}
		else
			result[i] = *(this->m_vect + i) * *(v.GetVect() + i);

	return result;
}

// Умножение вектора на число (каждый компонент вектора умножается на число).
Vector Vector::operator*(int n)
{
	Vector result{ m_size };
	result.Clear();
	for (int i = 0; i < m_size; i++)
		result[i] = (*(this->m_vect + i)) * n;
	return result;
}

// Перегруженный оператор *= для умножения вектора на число.
Vector& Vector::operator*=(int n)
{
	return *this = this->operator*(n);
}

// Метод вывода на экран.
void Vector::Print() const
{
	for (int i = 0; i < m_size; i++)
		cout << m_vect[i] << '\t';
	cout << endl;
}

// Метод заполнения вектора.
void Vector::Input()
{
	int min = 10; // Минимальное значение.
	int max = 99; // Максимальное значение.
	if (m_size != 0)
		for (int i = 0; i < m_size; i++)
			m_vect[i] = rand() % (max - min + 1) + min; // Заполнение одномерного массива псевдослучайными числами.
}

// Метод очистки вектора (заполнет все элементы нулями).
void Vector::Clear()
{
	for (int i = 0; i < m_size; i++)
		m_vect[i] = 0;
}

// Метод возвращает истину, если вектор пустой (m_size <= 0).
bool Vector::IsEmpty() const
{
	return m_size <= 0 ? true : false;
}

// Метод добавления элемента в вектор.
void Vector::Add(const int& item)
{
	int* p = new int[++m_size];
	if (m_vect != nullptr)
	{

		for (int i = 0; i < m_size - 1; i++)
			p[i] = m_vect[i];
		p[m_size - 1] = item;
	}
	else
	{
		*p = item;
	}
	delete[]m_vect;
	m_vect = p;
	p = nullptr;
}

// Метод вставки элемента в вектор по заданному индексу.
void Vector::Insert(int index, const int& item)
{
	if (index < 0 || index > m_size - 1)
		return;
	int* p = new int[++m_size];
	int k = 0;
	for (int i = 0; i < m_size; i++)
	{
		if (index == i)
		{
			k = 1;
			p[i] = item;
		}
		else
			p[i] = m_vect[i - k];
	}
	delete[]m_vect;
	m_vect = p;
	p = nullptr;
}

// Метод удаления элемента из вектора по заданному индексу.
void Vector::Remove(int index)
{
	if (index < 0 || index > m_size - 1)
		return;
	int* p = new int[--m_size];
	int k = 0;
	for (int i = 0; i < m_size; i++)
	{
		if (index == i)
			k = 1;
		p[i] = m_vect[i + k];
	}
	delete[]m_vect;
	m_vect = p;
	p = nullptr;
}

// Перегруженный оператор >>. Ввод вектора с клавиатуры.
istream& operator>>(istream& cin, Vector& v)
{
	cout << endl;
	v.Clear();
	for (int i = 0; i < v.m_size; i++)
	{
		cout << "vector[" << i << "] = ";
		cin >> v.m_vect[i];
	}
	return cin;
}

// Перегруженный оператор <<. Вывод вектора на экран.
ostream& operator<<(ostream& cout, Vector& v)
{
	cout << endl;
	v.Print();
	return cout;
}