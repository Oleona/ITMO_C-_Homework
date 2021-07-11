#include <iostream>
using namespace std;
#include<math.h>

double triangle_square(double a)
{
	double square;
	square = a * a*sqrt(3) / 4;
	return square;
}
double triangle_square(double a, double b, double c)
{
	double square,semi_perimetr ;
	semi_perimetr = (a + b + c) / 2;
	square =sqrt (semi_perimetr*(semi_perimetr - a)*(semi_perimetr - b)*(semi_perimetr - c));
	return square;
}


int main()
{
	int triangle;
	cout << "Input number 1 for equilateral or 0 for versatile triangle\n";
	cin >> triangle;
	if (triangle)
	{
		cout << "Input  triangle side\n";
		double side;
		cin >> side;
		cout << " equilateral triangle square " << triangle_square(side) << "\n";
	}
	else
	{
		cout << "Input first triangle side\n";
		double side1;
		cin >> side1; 
		cout << "Input second triangle side\n";
		double side2;
		cin >> side2;
		cout << "Input third triangle side\n";
		double side3;
		cin >> side3;
		cout << " versatile  triangle square " << triangle_square(side1,side2,side3) << "\n";
	}
}

