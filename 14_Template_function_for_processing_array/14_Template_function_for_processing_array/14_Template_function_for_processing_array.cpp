#include <typeinfo>
using namespace std;
#include <iostream>

template<class T>
double average_value(T arr[], int size)
{
	double avg;
	avg = 0.0;
	for (int i = 0; i < size; i++)
		avg += arr[i];	
	avg /= size;
	return avg ;
}
template<class T>
void show(T arr[],double avg)
{
	cout << "Average value for array type " << typeid(T ).name() << "  is:  " << avg << endl;
}
int main()
{
	int arr[] = { 9,3,17,6,5,4,31,2,12 };
	double arrd[] = { 2.1, 2.3,1.7,6.6,5.3,2.44,3.1,2.4,1.2 };
	char arrc[] = "Hello, word";
	long arrl[] = {  -247483648, 114848348,-554327890, -114748364,1147483648, - 249483648, 114845348 };
	int k1 = sizeof(arr) / sizeof(arr[0]);
	int k2 = sizeof(arrd) / sizeof(arrd[0]);
	int k3 = sizeof(arrc) / sizeof(arrc[0]) - 1;
	int k4= sizeof(arrl) / sizeof(arrl[0]);
	double avg;
	avg=average_value(arr, k1);
	show(arr, avg);
	avg=average_value(arrd, k2);
	show(arrd, avg);
	avg=average_value(arrc, k3);
	show(arrc, avg);
	avg = average_value(arrl, k4);
	show(arrl, avg);
}

