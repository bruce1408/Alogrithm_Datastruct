#include<iostream>
using namespace std;

/*定义一个新的类*/
class Clock
{
	
	private:
	int hour,minute,second;
	public:
	void setTime(int newH = 0, int newM = 0, int newS = 0);
	void showTime();
	
};

void Clock::setTime(int newH, int newM, int newS)
{
	hour = newH;
	minute = newM;
	second = newS;
	
}

void Clock::showTime()
{
	cout<<hour<<":"<<minute<<":"<<second<<endl;
}



int main()
{
	Clock myclock;
	myclock.setTime(0,0,0);
	myclock.showTime();
	
	myclock.setTime(6,35,12);
	myclock.showTime();
	return 0;
	
	
}



