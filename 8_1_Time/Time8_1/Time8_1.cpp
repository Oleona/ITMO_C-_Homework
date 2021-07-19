using namespace std;
#include <iostream>

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

	Time time_sum(Time &t1, Time &t2)
	{
		long totalsecs = (t1.myhours * 3600) + (t1.myminutes * 60) + t1.myseconds + (t2.myhours * 3600) + (t2.myminutes * 60) + t2.myseconds;
		myhours = totalsecs / 3600;
		myminutes = totalsecs % (3600) / 60;
		myseconds = totalsecs % (3600) % 60;
		Time summary = Time(myhours, myminutes, myseconds);
		return summary;
	}
};

int main()
{
	Time time1 = Time();
	time1.show_time();
	Time time2 = Time(1, 14, 72);
	time2.show_time();
	Time time3 = Time(3, 83, 54);
	time3.show_time();
	time1.time_sum(time2, time3);
	time1.show_time();
}

