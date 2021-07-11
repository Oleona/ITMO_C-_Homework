#include <iostream>
using namespace std;
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int year;
    cout << "Input the year to check: \n";
	cin >> year;
	if( year % 4 != 0 or (year % 100 == 0 and year % 400 != 0))
		cout << "NO- The year is NOT leap";
	else
		cout << "YES-The year is leap year";
	return 0;

}

