#include <iostream>
#include "calender.h"
using namespace std;

int main()
{
	//cout << "Hello World\n";
	
	year y = new year(2023);
	y.printCalendar();
	return 0;
}
