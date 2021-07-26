#include <math.h>
#include <iostream>
using namespace std;
#include <windows.h>
class Time
{
	int myhours;
	int myminutes;
	int myseconds;
public:
	Time()
	{
		myhours = myminutes = myseconds = 0;
	}

	Time(int hours, int minutes, int seconds)
	{
		myhours = hours;
		myminutes = minutes;
		myseconds = seconds;

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

	Time operator+(const Time & t) const
	{
		long totalsecs = (myhours * 3600) + (myminutes * 60) + myseconds + (t.myhours * 3600) + (t.myminutes * 60) + t.myseconds;
		int hours = totalsecs / 3600;
		int minutes = totalsecs % (3600) / 60;
		int seconds = totalsecs % (3600) % 60;
		Time summary = Time(hours, minutes, seconds);
		return summary;
	}

	Time operator-(const Time & t) const
	{
		long totalsecs = abs((myhours * 3600) + (myminutes * 60) + myseconds - (t.myhours * 3600) - (t.myminutes * 60) - t.myseconds);
		int hours = totalsecs / 3600;
		int minutes = totalsecs % (3600) / 60;
		int seconds = totalsecs % (3600) % 60;
		Time diff = Time(hours, minutes, seconds);
		return diff;
	}

	friend Time operator+(const Time & t, double sec) //переменную предполагаем в секундах
	{
		int sec1 = static_cast <int>(sec);
		int ssec = sec1 % 60;
		int mmin = sec1 / 60 % 60;
		int hhour = sec1 / 3600;
		Time tadd(hhour, mmin, ssec);
		Time tnew = t + tadd;
		return tnew;
	}

	friend Time operator+(double sec, const Time & t)
	{
		Time temp = t + sec;
		return temp;
	}

	friend bool operator> (const Time & t1, const Time & t)
	{
		if (t1.myhours > t.myhours)
		{
			cout << " Время  ";
			t1.show_time();
			cout << " больше, чем ";
			t.show_time();
			cout << endl;
			return true;
		}
		if (t1.myhours < t.myhours)
		{ 
			cout << " Время  ";
			t1.show_time();
			cout << " НЕ больше, чем ";
			t.show_time();
			cout << endl;
		return false;
		}
		
		if (t1.myminutes > t.myminutes){
			cout << " Время  ";
			t1.show_time();
			cout << " больше, чем ";
			t.show_time();
			cout << endl;
		return true;
		}
		
		if (t1.myminutes < t.myminutes){
			cout << " Время  ";
			t1.show_time();
			cout << " НЕ больше, чем ";
			t.show_time();
			cout << endl;
		return false;
		}
		
		if (t1.myseconds > t.myseconds){
			cout << " Время  ";
			t1.show_time();
			cout << " больше, чем ";
			t.show_time();
			cout << endl;
		return true;
		}
		

		cout << " Время  ";
		t1.show_time();
		cout << " НЕ больше, чем ";
		t.show_time();
		cout << endl;
		return false;
	}

};





int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Time time1 = Time();
	time1.show_time();
	Time time4 = Time();
	time4.show_time();
	Time time2 = Time(1, 14, 72);
	time2.show_time();
	Time time3 = Time(3, 83, 54);
	time3.show_time();
	time1 = time2 + time3;
	time1.show_time();
	time4 = time2 - time3;
	time4.show_time();
	Time time5 = Time();
	time5.show_time();
	double ss = 5466;
	time5 = time2 + ss;
	time5.show_time();
	Time time6 = Time();
	time6.show_time();
	double sss = 5467;
	time6 = sss + time2;
	time6.show_time();
	bool b=time2 > time3;
	cout << b;
	bool c = time3 > time2;
	cout << c;
}
