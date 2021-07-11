using namespace std;
#include <iostream>
#include <windows.h>

void show_array(int Arr[], const int N);
int sum_all_elements(int Arr[], const int N);
double mean_value_of_elements(int Arr[], const int N);
void sum_of_negative_and_positive(int Arr[], const int N);
void sum_elements_with_odd_and_even_indices(int Arr[], const int N);
void max_and_min_elements_and_their_indices(int Arr[], const int N);
void product_of_elements_between_max_and_min_elements(int Arr[], const int N);
void selection_sort(int Arr[], const int N);

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	const int n = 5;
	int mas[n];
	for (int i = 0; i < n; i++)
	{
		cout << "mas[" << i << "]=";
		cin >> mas[i];
	}

	cout << "исходный массив   ";
	show_array(mas, n);
	//Определите сумму всех элементов массива	
	int s = sum_all_elements(mas, n);
	cout << "суммa всех элементов массива=  " << s << endl;

	//среднее значение элементов массива
	double midl = mean_value_of_elements(mas, n);
	cout << "среднее значение элементов массива=  " << midl << endl;

	//расчет суммы отрицательных элементов
	//расчет суммы положительных элементов

	sum_of_negative_and_positive(mas, n);

	//расчет суммы элементов с нечетными индексами,
	//.расчет суммы элементов с четными индексами.
	sum_elements_with_odd_and_even_indices(mas, n);

	//найти максимальный и минимальный элементы массива и вывести их индексы

	max_and_min_elements_and_their_indices(mas, n);

	//рассчитать произведение элементов массива, расположенных между максимальным и минимальным элементами
	 product_of_elements_between_max_and_min_elements(mas, n);

	 //Сортировка массива
	 selection_sort(mas, n);

}
void show_array(int Arr[], const int N)
{
	for (int i = 0; i < N; i++)
		cout << Arr[i] << " ";
	cout << "\n";
}

int sum_all_elements(int Arr[], const int N)
{
	int s = 0;
	for (int i = 0; i < N; i++)
	{
		s += Arr[i];
	}
	return s;
}

double mean_value_of_elements(int Arr[], const int N)
{
	int s = sum_all_elements(Arr, N);
	double mid;
	mid = (double)s / N;
	return mid;
}
void sum_of_negative_and_positive(int Arr[], const int N)
{
	int  ssum_of_negative = 0;
	int sum_of_positive = 0;
	for (int i = 0; i < N; i++)
	{
		if (Arr[i] < 0)
			ssum_of_negative += Arr[i];
		else
			sum_of_positive += Arr[i];
	}

	cout << "суммa отрицательных элементов" << ssum_of_negative << endl;
	cout << "суммa положительных элементов " << sum_of_positive << endl;
}

void sum_elements_with_odd_and_even_indices(int Arr[], const int N)
{
	int even = 0;
	int odd = 0;

	for (int i = 0; i < N; i++)
	{
		if (i % 2)
			even += Arr[i];
		else
			odd += Arr[i];
	}
	cout << "суммы элементов с нечетными индексами  " << even << endl;
	cout << "суммы элементов с четными индексами  " << odd << endl;
}

void max_and_min_elements_and_their_indices(int Arr[], const int N)
{
	int max = 0;
	int min = 0;
	int index_min;
	int index_max;

	for (int i = 0; i < N; i++)
	{
		if (Arr[i] < min)
		{
			min = Arr[i];
			index_min = i;
		}
		else
			if (Arr[i] > max)
			{
				max = Arr[i];
				index_max = i;
			}
	}
	cout << " минимальный элемент массива " << min << "  с индексом  " << index_min << endl;
	cout << " максимальный элемент массива " << max << "  с индексом  " << index_max << endl;
}



void product_of_elements_between_max_and_min_elements(int Arr[], const int N)
{
	int max = 0;
	int min = 0;
	int index_min = 0;
	int index_max = 0;

	for (int i = 0; i < N; i++)
	{
		if (Arr[i] < min)
		{
			min = Arr[i];
			index_min = i;
		}
		else
			if (Arr[i] > max)
			{
				max = Arr[i];
				index_max = i;
			}
	}
	int mult = 1;
	for (int i = index_min; i <= index_max; i++)
	{
		mult *= Arr[i];
	}

	cout << "Произведение элементов между  " << index_min << "  и  " << index_max << "  =  " << mult << endl;

}

void selection_sort(int Arr[], const int N)
{
	int min = 0; 
	int buf = 0;
	for (int i = 0; i < N; i++)
	{
		min = i; 
		for (int j = i + 1; j < N; j++)
			min = (Arr[j] < Arr[min]) ? j : min;
	
		if (i != min)
		{
			buf = Arr[i];
			Arr[i] = Arr[min];
			Arr[min] = buf;
		}
	}	cout << "Отсортированный массив  ";	show_array(Arr, N);
}
