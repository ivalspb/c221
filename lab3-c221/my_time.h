#pragma once
#include <ctime>
#include <variant>

#pragma warning(disable : 4996)

static enum What { Year, Month, Day, WeekDay };
static const char* week_days_s[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

using D_res_var = std::variant<int, int, int, const char*>;// 0 = Year, 1 = Month, 2 = Day, 3 = WeekDay

D_res_var get_my_date(const What& w)
{
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);

	D_res_var res;

	switch (w)
	{
	case What::Day:
		res.emplace<2>(now->tm_mday);
		break;
	case What::Month:
		res.emplace<1>(now->tm_mon + 1);
		break;
	case What::Year:
		res.emplace<0>(now->tm_year + 1900);
		break;
	case What::WeekDay:
		res.emplace<3>(week_days_s[now->tm_wday]);
	}
	return res;
}