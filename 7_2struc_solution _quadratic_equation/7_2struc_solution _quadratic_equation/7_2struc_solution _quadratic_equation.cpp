#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;

struct Roots
{
	double root1;
	double root2;
};


Roots return_roots(double a, double b, double c)
{
	Roots r;
	if ((b*b - 4 * a*c) > 0)
	{
		r.root1 = ((-b) + sqrt(b*b - 4 * a*c)) / (2 * a);
		r.root2 = ((-b) - sqrt(b*b - 4 * a*c)) / (2 * a);
	}
	else if ((b*b - 4 * a*c) == 0)
	{
		r.root1 = -b / (2 * a);
		r.root2 = r.root1;
	}
	else
	{
		cout << "Нет корней ";
		r.root1 = numeric_limits<double>::quiet_NaN();
		r.root2 = numeric_limits<double>::quiet_NaN();

	}

	return r;
}


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Roots roots;
	double a, b, c;
	cout << "Input first coefficient " << endl;
	cin >> a;
	cout << "Input second coefficient " << endl;
	cin >> b;
	cout << "Input third coefficient " << endl;
	cin >> c;
	roots = return_roots(a, b, c);
	if (!isnan(roots.root1 ))
	{
		cout << "Первый корень   " << roots.root1 << endl;
		cout << "Второй корень   " << roots.root2 << endl;
	}
}
