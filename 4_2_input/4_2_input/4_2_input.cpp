using namespace std;
#include <iostream>
int Input(int &a, int &b);

int main()
{
	int a, b;
	if (Input(a, b) == false)
	{
		cerr << "error";
		return 1;
	}
	int s = a + b;
	cout << "sum = " << s << endl;
	return 0;

}
int Input(int&a, int &b)
{
	cout << " Input  number a and b " << endl;

	cin >> a;
	cin >> b;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		return 0;
	}
	else
	{
		std::cin.ignore(32767, '\n');
		return 1;
	}
}


