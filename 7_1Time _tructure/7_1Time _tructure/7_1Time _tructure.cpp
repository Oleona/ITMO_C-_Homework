#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;



struct Time
{
	int hours;
	int minutes;
	int seconds;

	Time sum(Time first, Time second)
	{
		Time summary;
		int firstTime = first.hours * 3600 + first.minutes * 60 + first.seconds;
		int secondTime = second.hours * 3600 + second.minutes * 60 + second.seconds;
		int summTime = firstTime + secondTime;
		summary.hours = summTime / 3600;
		summTime = summTime % 3600;
		summary.minutes = summTime / 60;
		summTime = summTime % 60;
		summary.seconds = summTime;

		return summary;
	}

	Time diff(Time first, Time second)
	{
		Time diff;
		int firstTime = first.hours * 3600 + first.minutes * 60 + first.seconds;
		int secondTime = second.hours * 3600 + second.minutes * 60 + second.seconds;
		int diffTime = abs(firstTime - secondTime);

		diff.hours = diffTime / 3600;
		diffTime = diffTime % 3600;
		diff.minutes = diffTime / 60;
		diffTime = diffTime % 60;
		diff.seconds = diffTime;
		return diff;
	}

	void ShowTime()
	{
		cout << hours << "h-" << minutes << "m-" << seconds << "s\n";
	}

};

Time InputTime()
{
	Time t;
	cout << "\nВведите количество часов: ";
	cin >> t.hours;
	cout << "Введите количество минут: ";
	cin >> t.minutes;
	cout << "Введите количество секунд: ";
	cin >> t.seconds;
	return t;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Time t1 = InputTime();
	int totalTime_inSeconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
	t1.ShowTime();
	cout << "Время в секундах  " << totalTime_inSeconds << endl;
	Time t2 = InputTime();
	cout << " второе время " << endl;
	t2.ShowTime();
	Time t3;
	t3=t3.sum(t1, t2);
	cout << " Суммарное время " << endl;
	t3.ShowTime();
	Time t4;
	t4= t4.diff(t1, t2);
	cout << " Разница времени " << endl;
	t4.ShowTime();
	return 0;
}
