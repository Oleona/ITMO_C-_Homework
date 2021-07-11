using namespace std;
#include <iostream>

int Input(int a, int b);

int main()
{

	cout << " Input  number a and b " << endl;
	int a, b;
	cin >> a;
	cin >> b;
	if (Input(a, b) == false)
	{
		cerr << "error";
		return 1;
	}
	int s = a + b;
	cout << "sum = " << s << endl;
	return 0;


}

int Input(int a, int b)
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		return 0;
	}
	else
		return 1;

}