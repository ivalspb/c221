#include "book.h"

std::ostream& operator<<(std::ostream& os, const book& b)
{
	os << b.data;
	return os;
}
