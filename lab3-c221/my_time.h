#pragma once
#include <ctime>
#include <variant>

#pragma warning(disable : 4996)

enum What { Year, Month, Day, WeekDay };

using D_res_var = std::variant<int, const char*>;

D_res_var get_my_date(const What& w)
{
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);

	D_res_var res;

	switch (w)
	{
	case What::Day:
		res = now->tm_mday;
		break;
	case What::Month:
		res = now->tm_mon+1;
		break;
	case What::Year:
		res = now->tm_year+1900;
		break;
	case What::WeekDay:
		switch (now->tm_wday)
		{
		case 1:
			res = "Monday";
			break;
		case 2:
			res = "Tuesday";
			break;
		case 3:
			res = "Wednesday";
			break;
		case 4:
			res = "Thursday";
			break;
		case 5:
			res = "Friday";
			break;
		case 6:
			res = "Saturday";
			break;
		case 0:
			res = "Sunday";
		}
	}
	return res;
}