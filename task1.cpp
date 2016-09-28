#include <iostream>
using namespace std;
int Action(int* a, int* b, int const* size);
void max(int* a, int* b, int const* size, int* result, int* arr);
void min(int* a, int* b, int const* size, int* result, int* arr);
void avg(int* a, int* b, int const* size, int* result, int* arr);
int main()
{
	int exits = 1;
	int const size = 10;
	int a[size]{ 3,5,8,50,32,43,32,46,6,15 };
	int b[size]{2.32,5,16,17,21,35,42,12,3.};
	do
	{
		Action(a, b, &size);
		cout << "continue enter 1\nexit enter 0\n";
		cin >> exits;
		if (exits !=1 &&
			exits !=0)
		{
			cout << "error wrong input" << endl;
			exit(1);
		}
	} while (exits != 0);
}

int Action(int* a, int* b, int const* size)
{
	int result;
	int arr;
	int foo;
	cout << "select:\nmaximum in arr: 1\nminimum in arr: 2\naverage in arr: 3\nenter: ";
	cin >> foo;
	if (foo == 1)
	{
		max(a,b,size, &result, &arr);
		cout << "maximum in arr = " << result << endl;
	}
	else if (foo == 2)
	{
		min(a, b, size, &result, &arr);
		cout << "minimum in arr = " << result << endl;
	}
	else if (foo == 3)
	{
		avg(a, b, size, &result, &arr);
		cout << "average in arr = " << result << endl;
	}
	else
	{
		cout << "error wrong input" << result << endl;
	}
	return 0;
}

void max(int* a, int* b, int const* size, int* result, int* arr)
{
	*result = INT_MIN;
	for (int i = 0; i < *size; i++)
	{
		if (*result < a[i])
		{
			*result = a[i];
		}
		if (*result < b[i])
		{
			*result = b[i];
		}
	}
}

void min(int* a, int* b, int const* size, int* result, int* arr)
{
	*result = INT_MAX;
	for (int i = 0; i < *size; i++)
	{
		if (*result > a[i])
		{
			*result = a[i];
		}
		if (*result > a[i]) 
		{
			*result = b[i];
		}
	}
}


void avg(int* a, int* b, int const* size, int* result, int* arr)
{
	*result = 0;
	for (int i = 0; i < *size; i++)
	{
		*result += a[i] + b[i];
	}
	*result /= (*size * 2);
	for (int i = 0; i < *size; i++)
	{
		if (*result == a[i])
		{
			*result = a[i];
		}
		if (*result == b[i])
		{
			*result = b[i];
		}
	}
}

/*Написать программу, которая содержит функцию Action, принимающую в качестве аргумента, 
указатели на два массива (А и В) и размеры массивов, а также указатель на функцию.
Пользователю отображается меню, в котором он может выбрать max,min,avg. 
Если выбран max - передается указатель на функцию, которая ищет максимум, 
если выбран min - передается указатель на функцию, которая ищет минимум, 
если выбран avg - передается указатель на функцию, которая ищет среднее.
Возвращаемое значение функции Action результат выбора пользователя max, min, avg.*/