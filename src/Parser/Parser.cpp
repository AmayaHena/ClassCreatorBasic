/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** parser
*/

#include "Parser/Parser.hpp"

Parser::Parser() : _main(false), _inheritance(false), _makefile(false), _cmake(false), _folders(false) {}

void Parser::setProjectName(const std::string s)
{
    _project_name = s;
}

std::string Parser::getProjectName(void)
{
    return _project_name;
}

void Parser::setMain(const bool b)
{
    _main = b;
}

bool Parser::getMain(void)
{
    return _main;
}

void Parser::setSubFiles(const std::vector<std::string> v)
{
    _sub_files = v;
}

std::vector<std::string> Parser::getSubFiles(void)
{
    return _sub_files;
}

void Parser::setInheritance(const bool b)
{
    _inheritance = b;
}

bool Parser::getInheritance(void)
{
    return _inheritance;
}

void Parser::setMakefile(const bool b)
{
    _makefile = b;
}

bool Parser::getMakefile(void)
{
    return _makefile;
}

void Parser::setFolders(const bool b)
{
    _folders = b;
}

bool Parser::getFolders(void)
{
    return _folders;
}

void Parser::setCMake(const bool b)
{
    _cmake = b;
}

bool Parser::getCMake(void)
{
    return _cmake;
}

bool Parser::helperCommand()
{
    std::cout << "usage: classCreator [Project Name] [-miMCdf] ..." << std::endl
              << std::endl << "\tOptions:" << std::endl
              << "\t-m\tmake a main function" << std::endl
              << "\t-i\tmake inheritance from the main class of the project" << std::endl
              << "\t-M\tmake a makefile" << std::endl
              << "\t-C\tmake CMakeLists.txt for CMake" << std::endl
              << "\t-d\tmake directory for classes" << std::endl
              << "\t-f\tmake some subfiles for your project, muste be follow by subfiles name" << std::endl << std::endl;
    return false;
}

bool Parser::AVOptions(std::string s, bool tmp)
{
    for (int i = 1; s[i]; i++) {
        if (s[i] == 'm')
            Parser::setMain(true);
        else if (s[i] == 'f')
            tmp = true;
        else if (s[i] == 'i')
            Parser::setInheritance(true);
        else if (s[i] == 'M')
            Parser::setMakefile(true);
        else if (s[i] == 'C')
            Parser::setCMake(true);
        else if (s[i] == 'd')
            Parser::setFolders(true);
        else
            continue;
    }
    return tmp;
}

bool Parser::parsingAV(std::vector<std::string> v)
{
    if (v.empty())
        return false;
    if (v[0][0] == '-')
        return Parser::helperCommand();
    Parser::setProjectName(v[0]);
    bool tmp = false;
    for (unsigned int i = 1; i < v.size(); i++) {
        if (v[i][0] == '-')
            tmp = Parser::AVOptions(v[i], tmp);
        else
            _sub_files.push_back(v[i]);
    }
    return true;
}

std::string Parser::userInput()
{
    std::string s;

    std::getline(std::cin, s);
    std::cin.clear();
    return s;
}

std::string Parser::parsingString(const std::string type, const std::string convention)
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

std::vector<std::string> Parser::parsingStoVector(const std::string type, const std::string convention)
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

int Parser::parsingProceed(std::vector<std::string> v)
{
    if (Parser::parsingAV(v))
        return 0;
    Parser::setProjectName(Parser::parsingString("project name", "PascalCase"));
    Parser::setMain(Parser::parsingBoolean("main file (main.cpp)"));
    bool file = Parser::parsingBoolean("subfiles");
    if (file) {
        Parser::setSubFiles(Parser::parsingStoVector("subfiles names", "PascalCase"));
        Parser::setInheritance(Parser::parsingBoolean("Inheritance (from your main file)"));
    }
    Parser::setFolders(Parser::parsingBoolean("Folders"));
    Parser::setMakefile(Parser::parsingBoolean("Makefile"));
    Parser::setCMake(Parser::parsingBoolean("CMakeLists.txt"));
    return 0;
}
