#include<iostream>
#include <vector>
#include<string.h>
#include<string_view>
std::string checkName(const std::string_view name)
{
	using namespace std::literals;

	std::vector Names{ "Allex"s, "Betty"s, "Caroline"s, "Dave"s, "Emily"s, "Fred"s, "Greg"s, "Holly"s };
	for (const auto checkName : Names)
	{
		if (checkName == name)
			return "found";


	}
	return "not found";

}


int main()
{

	std::string storeName{};
	std::cout << "Enter name :" << "\n";
	std::cin >> storeName;
	std::cout << storeName << ' ' << checkName(storeName);
}
