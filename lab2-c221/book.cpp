#include "book.h"

auto book::compare(const book& other, const size_t index) const
{
		switch (index)
		{
		case 0:
			return std::get<0>(data) <=> std::get<0>(other.data);
			break;
		case 1:
			return std::get<1>(data) <=> std::get<1>(other.data);
			break;
		case 2:
			return std::get<2>(data) <=> std::get<2>(other.data);

		}
}
