/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** main
*/

#include "Core.hpp"

int main()
{
	std::vector<std::string> v;
	v.clear();

	Core c(v);

	if (c.run() == false)
		return 84;
	std::cout << "\033[1;32mCreation Done\033[0m" << std::endl;
	return 0;
}