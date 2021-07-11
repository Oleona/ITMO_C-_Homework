#include <iostream>
using namespace std;
#include <windows.h>
#include <ctime> 
#include<math.h>
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int point=0, count=0;
	double x, y, target_center_x, target_center_y, side_wind_x, side_wind_y, dist;
	// target_center произвольный центр мишени, side_wind помеха бокового ветра
	while (point < 50)
	{srand(time(NULL));
		cout << "Input coordinates of the shot: \n";
		cin >> x;
		cin >> y;
		target_center_x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 5)) - static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 10));;
		target_center_y = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 5)) - static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 10));
		side_wind_x= static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1))- static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 2));
		side_wind_y = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1)) - static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 2));
		x = x + target_center_x + side_wind_x;
		y= y + target_center_y + side_wind_y;
		dist = sqrt(pow(x - target_center_x, 2.0) + pow(y - target_center_y, 2.0));
		if (dist < 1) point += 10;
		else if (dist < 2) point += 5;
		else if (dist < 3) point += 1;
		count += 1;
		cout << point<< "  points\n";
	}
	if (count<=6)
		cout << "attempts  " << count << "  received  " << point << "  points. you are a sniper \n";
    if (count <= 10)
		cout << "attempts  " << count << "  received  " << point << "  points. you are a shooter \n";
	else
	{
		cout << "attempts  " << count << "  received  " << point << "  points. you are a new \n";
	}


}

