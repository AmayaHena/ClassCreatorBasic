/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** parser
*/

#include "Parser.hpp"

Parser::Parser() : _main(false), _inheritance(false), _makefile(false), _cmake(false), _folders(false) {}

std::string Parser::getProjectName(void)
{
	return _project_name;
}

bool Parser::getMain(void)
{
	return _main;
}

std::vector<std::string> Parser::getSubFiles(void)
{
	return _sub_files;
}

bool Parser::getInheritance(void)
{
	return _inheritance;
}

bool Parser::getMakefile(void)
{
	return _makefile;
}

bool Parser::getFolders(void)
{
	return _folders;
}

bool Parser::getCMake(void)
{
	return _cmake;
}

std::string Parser::userInput()
{
	std::string s;

	std::getline(std::cin, s);
	std::cin.clear();
	return s;
}

std::string Parser::parsingString(const std::string &type, const std::string &convention)
{
	std::string s;

	while (s.empty()) {
		std::cout << "Give me your "<< type << ", please use "<< convention << std::endl << ">";
		s = Parser::userInput();
	}
	for (int i = 0; s[i]; i++)
		if (s[i] == ' ')
			s.erase(i, 1);
	std::cout << std::endl;
	return s;
}

std::vector<std::string> Parser::parsingStoVector(const std::string &type, const std::string &convention)
{
	std::cout << "Give me your "<< type << ", please use "<< convention << std::endl;
	std::cout << "Separate them by a white space" << std::endl << ">";
	std::string s = userInput();

	std::stringstream sstream(s);
	std::istream_iterator<std::string> begin(sstream);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vstrings(begin, end);
	std::cout << "There is all your " << type << " :" << std::endl;
	std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	std::cout << std::endl;
	return vstrings;
}

bool Parser::parsingBoolean(std::string s)
{
	std::cout << "Do you want " << s << " (yes/no) (y/n) ?" << std::endl << ">";

	while (1) {
		s = userInput();
		if (s == "yes" || s == "y" || s == "no" || s == "n")
			break;
		std::cout << '>';
	}
	std::cout << std::endl;
	if (s == "yes" || s == "y")
		return true;
	return false;
}

void Parser::parsingProceed(const std::vector<std::string> &v)
{
	(void)v;
	_project_name = Parser::parsingString("project name", "PascalCase");
	_main = Parser::parsingBoolean("main file (main.cpp)");
	if (Parser::parsingBoolean("subfiles")) {
		_sub_files = Parser::parsingStoVector("subfiles names", "PascalCase");
		_inheritance = Parser::parsingBoolean("Inheritance (from your main file)");
	}
	_folders = Parser::parsingBoolean("Folders");
	_makefile = Parser::parsingBoolean("Makefile");
	_cmake = Parser::parsingBoolean("CMakeLists.txt");
}
