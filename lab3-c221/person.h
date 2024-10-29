#pragma once
#include <string>
#include <optional>
#include <iostream>

class person
{
	std::string name;
	size_t age;
	std::optional<std::string> nick;
public:
	person() = default;
	person(const std::string& nm, const size_t age, std::optional<std::string> nk=std::nullopt) :name(nm), age(age), nick(nk) {}

	auto operator<=>(const person& other) const = default;

	friend std::ostream& operator<<(std::ostream& os, const person& p);
};

