#include <iostream>
#include <string>
using namespace std;
#include <map>
#include <windows.h>
#include <ctime>
struct StudentGrade
{
	string name;
	string grade;
};


int main()
{
	srand(time(NULL));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int n;
	string name;
	StudentGrade stud;
	map<string, string> StudentGradeMap;
	map <string, string> ::iterator it;
	cout << "Введите количество студентов в группе: " << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Введите имя студента: " << endl;
		cin >> stud.name;
		stud.grade = {};
		StudentGradeMap.insert(make_pair(stud.name, stud.grade));
	}

	cout << "Расставить оценки" << endl;
	cout << "Введите имя студента: " << endl;
	cin >> name;
	it = StudentGradeMap.find(name);
	if (it == StudentGradeMap.end()) {
		cout << "Такого студента нет";
		return 1;
	}
	it->second = to_string((2 + rand() % 4));
	stud.grade = it->second;
	cout << "Оценка студента: " << it->first << " = " << it->second << endl;
	cout << endl;
	cout << "Расставить оценки вручную" << endl;
	for (it = StudentGradeMap.begin(); it != StudentGradeMap.end(); it++)
	{
		cout << "Поставьте оценку студенту " << it->first << endl;
		cin >> it->second;
		cout << "Оценка студента: " << it->first << " = " << it->second << endl;
	}
	return 0;
}