#include <iostream>
using namespace std;
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	double num1,num2,num3 ;
	cout << "Input three numbers: \n";
	cin >> num1 >> num2 >> num3;
	int max = num1;
	if (num2 >= max) max = num2;
	else if (num3 >= max) max = num3;
	cout << "max number is: " << max;

	return 0;

}
