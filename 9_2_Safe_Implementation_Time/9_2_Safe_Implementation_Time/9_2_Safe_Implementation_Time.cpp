using namespace std;
#include <iostream>
#include <windows.h>
#include <string>


class Time
{
	int myhours;
	int myminutes;
	int myseconds;
public:

	class ExScore
	{
	public:
		string origin;
		int iValue;
		ExScore(string str, int sc)
		{
			origin = str;
			iValue = sc;
		}
	};
	Time()
	{
		myhours = myminutes = myseconds = 0;
	}

	Time(int hours, int minutes, int seconds)
	{
		myhours = hours;
		myminutes = minutes;
		myseconds = seconds;
		if (myhours > 2147483647.0L || myhours < -2147483647.0L)
			throw ExScore(" Переполнение для переменной типа int", myhours);
		if (myminutes > 2147483647.0L || myminutes < -2147483647.0L)
			throw ExScore(" Переполнение для переменной типа int", myminutes);
		if (myseconds > 2147483647.0L || myseconds < -2147483647.0L)
			throw ExScore(" Переполнение для переменной типа int", myseconds);
		if (myhours < 0)
			throw ExScore("в конструкторе Time(int,int,int) ", myhours);		if (myminutes < 0)
			throw ExScore("в конструкторе Time(int,int,int)", myminutes);		if (myseconds < 0)
			throw ExScore("в конструкторе Time(int,int,int)", myseconds);

		if (myseconds >= 60)
		{
			myminutes += myseconds / 60;
			myseconds = myseconds % 60;
		}
		else if (myminutes >= 60)
		{
			myhours += myminutes / 60;
			myminutes = myminutes % 60;
		}
	}

	void show_time()const
	{
		cout << "Time is   " << myhours << ":" << myminutes << ":" << myseconds << endl;
	}

	Time time_sum(Time &t1, Time &t2)
	{
		int totalsecs = (t1.myhours * 3600) + (t1.myminutes * 60) + t1.myseconds + (t2.myhours * 3600) + (t2.myminutes * 60) + t2.myseconds;
		if (totalsecs > 2147483647 || totalsecs < 0);
		throw ExScore(" Переполнение для переменной типа int", totalsecs);;

		myhours = totalsecs / 3600;
		myminutes = totalsecs % (3600) / 60;
		myseconds = totalsecs % (3600) % 60;
		Time summary = Time(myhours, myminutes, myseconds);
		return summary;
	}

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try
	{
		Time time1 = Time();
		time1.show_time();
		Time time2 = Time(1, 14, -72);
		time2.show_time();
		Time time3 = Time(3333333, 83, 54);
		time3.show_time();
		time1.time_sum(time2, time3);
		time1.show_time();
	}
	catch (Time::ExScore& ex)
	{
		cout << "\nОшибка " << ex.origin;
		cout << "\nВведенное значение времени " << ex.iValue <<
			"    является недопустимым\n";
	}
}
