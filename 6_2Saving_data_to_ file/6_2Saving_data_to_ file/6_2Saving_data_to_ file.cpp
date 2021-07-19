using namespace std;
#include <iostream>
#include <windows.h>
#include <fstream>

int * max_vect(int size, int a[], int b[]);

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	ofstream out("test1", ios::out | ios::binary);
	if (!out) {
		cout << "Файл открыть невозможно\n";
		return 1;
	}
	int a[] = { 1,2,3,4,5,6,7,2 };
	int b[] = { 7,6,5,4,3,2,1,3 };
	int kc = sizeof(a) / sizeof(a[0]);
	int *c;
	c = max_vect(kc, a, b);
	for (int i = 0; i < kc; i++)
		cout << c[i] << " ";
	cout << endl;

	for (int i = 0; i < kc; i++)    
		out << c[i] << " ";
	
	out.close();	int C2[8];
		ifstream in("test1", ios::in | ios::binary);
	if (!in) {
		cout << "Файл открыть невозможно";
		return 1;
	}

	int N, k;
	k = 0;
	while (in >> N)
	{
		C2[k++] = N;
	}
	cout << "Искомый массив:" << endl;
	for (int i = 0; i < k; i++)
	{
		cout << C2[i] << " ";
	}
	
	in.close();
	delete[]c;
}

int * max_vect(int size, int a[], int b[])
{
	int * newArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		if (a[i] > b[i])
			newArr[i] = a[i];
		else
		{
			newArr[i] = b[i];
		}
	}
	return newArr;
}

