#include<math.h>
#include <iostream>
using namespace std;
#include <windows.h>
#include <string>


class Triangle
{
	int mySide1;
	int mySide2;
	int mySide3;
public:
	class ExSideIsTooLong
	{
	public:
		string origin; 
		
		ExSideIsTooLong(string str)
		{
			origin = str; 	
		}
	};



	Triangle()
	{
		mySide1 = mySide2 = mySide3 = 0;
	}

	Triangle(int side1, int side2, int side3)
	{
		mySide1 = side1;
		mySide2 = side2;
		mySide3 = side3;
		if (mySide1 >= mySide2 + mySide3 || mySide2 >= mySide1 + mySide3 || mySide3 >= mySide2 + mySide1)
		{
			throw ExSideIsTooLong("в конструкторе одна из сторон больше суммы двух других ");
		}

	}
	double triangle_square(Triangle t)
	{
		double p;
		p = (t.mySide1 + t.mySide2 + t.mySide3) / 2.0;
		double square;
		square = sqrt(p * (p - t.mySide1) * (p - t.mySide2) * (p - t.mySide3));
		return square;
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int side1, side2, side3;
	double square;
	cout << "Введите длины трех сторон треугольника:\n";
	cin >> side1;
	cin >> side2;
	cin >> side3;
	try
	{
		Triangle tr = Triangle(side1, side2, side3);
		square = tr.triangle_square(tr);
		cout << square;
	}
	catch (Triangle::ExSideIsTooLong ex)
	{
		cout << "\nОшибка инициализации \t" << ex.origin;
		
	}

}

