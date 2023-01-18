#include <iostream>
#include <chrono>

class year
{
	private:
		int y;
	public:
		year();
		year(int y);
		int getMonthName(int monthNumber);
		int numberOfDays(int monthNumber);
		void printCalendar();
};

year::year()
{
	int currentYear = static_cast<int>(
		year_month_day{ time_point_cast<days>(system_clock::now())}.year()
	);
	this.y = currentYear;
}

year::year(int y)
{
	this.y = y;
}

int year::getMonthName(int monthNumber)
{
	string M[] = {"January","February","March","April", "May", "June", "July", "August", "September", "October", "November", "December" };
	return (M[monthNumber]);
}

int year::numberOfDays(int monthNumber)
{
	switch(monthNumber)
	{
		case 0:
		case 2:
		case 4:
		case 6:
		case 7:
		case 9:
		case 11:
			return 31;	//for 31 day months
			break;
		case 1:
			if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
				return 29;
			else
				return 28;
			break;
		case 3:
		case 5:
		case 8:
		case 10:
			return 30;
			break;
	}
}

void year::printCalendar()
{
	cout << "\t\t\t Calendar - Year " << year;
	int days;
	int current = dayNumber (1,1, y);
	for(int i=0;i<12;i++)
	{
		days = numberOfDays(i);
		cout << endl << "\t\t ----X----" << getMonthName(i).c_str() << "----X---- \t\t" << endl;
		cout << "Sun Mon Tue Wed Thu Fri Sat \n";
		int k;
		for(k=0;k<current;k++)
			cout << "\t";
		for(int j=1;j<=days;j++)
		{
			printf("%5d", j);
			if(++k > 6)
			{
				k=0;
				cout << endl;
			}
		}
		if(k)
			cout << endl;
		current = k;
	}
	return;
}

