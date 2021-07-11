#include <iostream>
using namespace std;
#include<math.h>

unsigned int recursion_sum(unsigned int  n, unsigned int  k)
{
	unsigned int sum;
	sum = k * n;
	if (k == 1) return n;
	else return (k * n + recursion_sum(n, k - 1));
}

int main()
{
	unsigned int  k, n;
	cout << "Input basis of a series\n";
	cin >> n;
	cout << "Input number of members\n";
	cin >> k;
	unsigned int res;
	res = recursion_sum(n, k);
	cout << "Sum of series is: \n" << recursion_sum(n, k);
	return 0;
}






