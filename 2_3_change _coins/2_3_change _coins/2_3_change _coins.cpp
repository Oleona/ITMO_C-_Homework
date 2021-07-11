#include <iostream>
using namespace std;
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int sum;
	int denominations[] = { 5000, 2000, 1000, 500, 100, 50, 10, 5, 2, 1 };
	cout << "Input sum to be exchanged: \n";
	cin >> sum;
	int i = 0;
	int quantity;
	cout << "In sum  " << sum << "  contains  \n";
	while (sum > 0)
	{
		if (sum >= denominations[i])
		{
			quantity = sum / denominations[i];
            cout <<  quantity << " times banknote  " << denominations[i] << " rubles \n";
			sum = sum - quantity *  denominations[i];
			i++;
	    }
		else
		{
        i++;
		}
	}

	return 0;

}

