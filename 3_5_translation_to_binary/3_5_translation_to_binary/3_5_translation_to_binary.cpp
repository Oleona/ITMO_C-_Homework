#include <iostream>
using namespace std;
#include<math.h>
#include <string>
using std::string;

string translation(int num)
{
	string str;
	if (num < 2) return str + to_string(num);
	else return (str + to_string(num % 2) + translation(num / 2));
}



int main()
{
	int num;
	string str;
	cout << "Input number \n";
	cin >> num;
	str=(translation(num));
	reverse(str.begin(), str.end());
	cout <<"Binary number  "<< str<< endl;
		

}
