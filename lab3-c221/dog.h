#include <string>
#include <iostream>

class dog
{
	std::string name;
public:
	dog() = default;
	template <typename T>
	dog(T&& n) :name(std::forward<T>(n)) {}
	friend std::ostream& operator<<(std::ostream& os, const dog& c)
	{
		os << "Dog " << c.name << std::endl;
		return os;
	}
};

