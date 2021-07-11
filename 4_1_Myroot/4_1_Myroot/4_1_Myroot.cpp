using namespace std;
#include<math.h>


#include <iostream>

int Myroot(double, double, double, double&, double&);

int main()
{
	double a, b, c;
	double root1, root2;
	cout << "Input first coefficient " << endl;
	cin >> a;
	cout << "Input second coefficient " << endl;
	cin >> b;
	cout << "Input third coefficient " << endl;
	cin >> c;
	/*Myroot(a, b, c, root1, root2);
	if (((b*b - 4 * a*c) >= 0)) {
		cout << "root1 = " << root1 << endl;
		cout << "root2 = " << root2 << endl;
	}
	else
	{
		cout << "no roots" << endl;
	}*/
	if (Myroot(a, b, c, root1, root2))
	{
		cout << "root1 = " << root1 << endl;
		cout << "root2 = " << root2 << endl;
	}
	else
	{
		cout << "no roots" << endl;
	}


}

int Myroot(double a, double b, double c, double& root1, double& root2)
{
	if ((b*b - 4 * a*c) > 0)
	{
		root1 = ((-b) + sqrt(b*b - 4 * a*c)) / (2 * a);
		root2 = ((-b) - sqrt(b*b - 4 * a*c)) / (2 * a);
		return 1;
	}
	else if ((b*b - 4 * a*c) == 0)
	{
		root1 = -b / (2 * a);
		root2 = root1;
		//return 0;
		return -1;
	}
	else
	{
		//return -1;
		return 0;
	}


}