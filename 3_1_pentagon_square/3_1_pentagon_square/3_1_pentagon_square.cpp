#include <iostream>
using namespace std;
#include<math.h>

double triangle_side(int a0, int a1, int b0 ,int b1 )
{
	double side;
	side = sqrt((b0 - a0) * (b0 - a0) + (b1 - a1) * (b1 - a1));
	return side;

}

double triangle_square(double a, double b, double c) 
{
	double p;
	p = (a + b + c) / 2;
	double square;
	square = sqrt(p * (p - a) * (p - b) * (p - c));
	return square;
}



int main()
{
	int point_1_x = 0, point_1_y = 0, point_2_x = 1, point_2_y = 4, point_3_x = 5, point_3_y = 6, point_4_x = 7, point_4_y = 2, point_5_x = 4, point_5_y = 0;
	double firstside, secondside, thirdside;
	double fist_square, second_square, third_square, pentagon_square;

	firstside = triangle_side(point_1_x, point_1_y, point_2_x, point_2_y);
	secondside = triangle_side(point_2_x, point_2_y, point_3_x, point_3_y);
	thirdside = triangle_side(point_3_x, point_3_y, point_1_x, point_1_y);

	fist_square = triangle_square(firstside, secondside, thirdside);

	firstside = thirdside;
	secondside = triangle_side(point_3_x, point_3_y, point_4_x, point_4_y);
	thirdside = triangle_side(point_4_x, point_4_y, point_1_x, point_1_y);
	second_square = triangle_square(firstside, secondside, thirdside);

	firstside = thirdside;
	secondside = triangle_side(point_4_x, point_4_y, point_5_x, point_5_y);
	thirdside = triangle_side(point_5_x, point_5_y, point_1_x, point_1_y);
	third_square = triangle_square(firstside, secondside, thirdside);

	pentagon_square = fist_square + second_square + third_square;
	cout << "pentagon_square  =  " << pentagon_square;

}

