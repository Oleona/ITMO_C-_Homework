#include <iostream>
using namespace std;
#include<math.h>


double cube_root(double a)
{
	return pow(a, 1.0 / 3.0);
}
double cubшс_root(double a)
{
	double x_prev, x_curr = a / 3.0;
	do 
	{
		x_prev = x_curr;
		x_curr = (2. * x_prev + a / (x_prev * x_prev)) / 3.0;
	} while (abs(x_prev - x_curr) >= numeric_limits<double>::epsilon());
	return x_curr;
}


int main()
{
	double a;
	cout <<" Input number a = : \n ";
	cin >> a;
	cout << " root= :  "<<cube_root(a) << "\n";
	cout << " root= :  "<<  cubшс_root(a);
}

