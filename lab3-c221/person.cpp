#include "person.h"

std::ostream& operator<<(std::ostream& os, const person& p)
{
	os << "Name is " << p.name << " Age is " << p.age;
	if (p.nick) os << " Nik is " << *p.nick;
	return os;
}
