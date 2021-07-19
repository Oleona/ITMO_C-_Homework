#include <fstream>
using namespace std;
#include <iostream>
#include <windows.h>
#include <string>

int main()
{
	
	char str[255];

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ofstream out("test.txt");
	if (!out) {
		cout << "Файл открыть невозможно\n";
		return 1;
	}
	cout << "Введите текст стихотворения/ Нажмите & для остановки " << endl;
	

	while (true)
	{
		cin.getline(str, 255);
		if (*str == '&')
			break;

		out << str << endl;
	}




	out.close(); 
	return 0;
}

	

