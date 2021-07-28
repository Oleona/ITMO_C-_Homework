#include <string>
#include <iostream>
#include<math.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;
#include <fstream>

class Animal {
public:

	virtual void get_full_inform()
	{
		cout << "\nInput animal name:  ";
		getline(cin >> ws, name);
		cout << "\nInput animal breed:  ";
		getline(cin >> ws, breed);
	}
	virtual void put_full_inform()
	{
		cout << "\nName: " << name;
		cout << "\nBreed:  " << breed;
	}
	virtual void showAnimalType() = 0;

	string name;
	string breed;
};

class Cat : public Animal
{
public:

	void get_full_inform()
	{
		Animal::get_full_inform();
		cout << "\nInput cat color: ";
		getline(cin >> ws, color);
	}
	void put_full_inform()
	{
		Animal::put_full_inform();
		cout << "\nColor: " << color << endl;
		ofstream out("test.txt", ios::app);
		if (out.is_open())
		{
			out << name << "  " << breed << " " << color << endl;
		}
		out.close();
	}
	void showAnimalType()
	{
		cout << "Cat" << endl;
	}

private:
	string color;
};

class Dog : public Animal
{
public:

	void get_full_inform()
	{
		Animal::get_full_inform();
		cout << "\nInput dog size: ";
		cin >> size;
	}
	void put_full_inform()
	{
		Animal::put_full_inform();
		cout << "\nSize: " << size << endl;
		ofstream out("test.txt", ios::app);
		if (out.is_open())
		{
			out << name << "  " << breed << " " << size << endl;
		}
		out.close();
	}
	void showAnimalType()
	{
		cout << "Dog" << endl;
	}
private:
	string size;
};

class IOrganizer
{
public:
	virtual ~IOrganizer() {}
	virtual void OverrideGet() = 0;
};

class Judge : IOrganizer
{
public:
	void showJudge()
	{
		int judge_name = (0 + rand() % 5);
		if (judge_name == 0)
			cout << " Ring is judged by the judge Ivanov Ivan" << endl;
		if (judge_name == 1)
			cout << " Ring is judged by the senior judge Stepanov Stepan" << endl;
		if (judge_name == 2)
			cout << "Ring is judged by the judge Marinova Marina " << endl;
		if (judge_name == 3)
			cout << " Ring is judged by the senior judge Katina Ekaterina" << endl;
		if (judge_name == 4)
			cout << " Ring is judged by an international judge Mikl Smit " << endl;
	}
	void OverrideGet()
	{
		for (int i = 0; i < 10; i++)
		{
			scores.push_back(2 + rand() % 12);
		}
		unsigned int count_scores = scores.size();
		unsigned int sum_scores = 0;
		float average_score;
		for (unsigned int i = 0; i < count_scores; ++i) {
			sum_scores += scores[i];
		}
		average_score = (float)sum_scores / (float)count_scores;
		cout << "\nAverage Score " << average_score << endl;
	}
private:
	vector<int> scores;
};

class Sponsor : IOrganizer
{
public:
	void OverrideGet()
	{
		int prize = (0 + rand() % 5);
		if (prize == 0)
			cout << "Congratulations on the sponsor's prize - food package" << endl;
		if (prize == 1)
			cout << "Congratulations on the sponsor's prize - soft bed " << endl;
		if (prize == 2)
			cout << "Congratulations on the sponsor's prize - toy " << endl;
		if (prize == 3)
			cout << "Congratulations on the sponsor's prize - bowl " << endl;
		if (prize == 4)
			cout << "Congratulations on the sponsor's prize - walking kit " << endl;
		cout << endl;
	}

};

int main()
{
	srand(time(NULL));
	Animal *test[100];
	int n = 0;
	char choice;

	do
	{
		cout << "\nCat or dog is registered for the show( c / d) ? " << endl;
		cin >> choice;
		if (choice == 'c')
		{
			test[n] = new Cat;
		}
		else {
			test[n] = new Dog;
		}
		test[n++]->get_full_inform();
		cout << "Continue((y / n) ? ";
		cin >> choice;
	} while (choice == 'y');
	cout << endl;
	cout << " Registered for the exhibition " << endl;
	for (int j = 0; j < n; j++)
		test[j]->put_full_inform();
	cout << endl;

	for (int j = 0; j < n; j++)
	{
		Judge showjudge;
		showjudge.showJudge();
		cout << " Entering the ring ";
		cout << test[j]->name << " " << test[j]->breed;
		showjudge.OverrideGet();		
		Sponsor showSponsor;
		showSponsor.OverrideGet();
	}

	return 0;

}

