/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** File
*/

/* MKDIR LIB */
#include <sys/stat.h>
#include <sys/types.h>

#include "File/File.hpp"

std::vector<std::string> File::getMain(void)
{
    return _main;
}

std::vector<std::string> File::getFileCpp(void)
{
    return _fileCpp;
}

std::vector<std::string> File::getFileHpp(void)
{
    return _fileHpp;
}

std::vector<std::string> File::getHeader(void)
{
    return _header;
}

std::vector<std::string> File::getMakefile(void)
{
    return _make;
}

std::vector<std::string> File::getCMake(void)
{
    return _cmake;
}

bool File::checkFileExist(const std::string s)
{
    struct stat buffer;

    if (stat(s.c_str(), &buffer) == -1) {
        std::cout << "File " << s << " doesnt exits" << std::endl;
        return false;
    }
    return true;
}

bool File::checkDirExist(const std::string s)
{
    struct stat buffer;

    if (stat(s.c_str(), &buffer) == -1) {
        std::cout << "Dir " << s << " doesnt exits" << std::endl;
        return false;
    }
    return true;
}

std::vector<std::string> File::loadFileToV(const std::string path)
{
    std::vector<std::string> v;
    std::ifstream f(path);
    std::string s;

    while(std::getline(f, s))
        v.push_back(s);
    std::cout << "File " << path << " loaded" << std::endl;
    return v;
}

std::vector<std::string> File::loadGeneric(const std::string path, bool request)
{
    std::vector<std::string> v;

    v.clear();
    if (request == false)
        return v;
    if (File::checkFileExist(path) == false)
        return v;
    return File::loadFileToV(path);
}

bool File::loadConfig(bool main, bool make, bool cmake)
{
    if (checkDirExist("config") == false)
        return false;
    _fileHpp = loadGeneric("config/file.hpp", true);
    _fileCpp = loadGeneric("config/file.cpp", true);
    _header = loadGeneric("config/header.txt", true);
    if (_fileHpp.empty() || _fileCpp.empty() || _header.empty())
        return false;
    _main = loadGeneric("config/main.cpp", main);
    _make = loadGeneric("config/makefile", make);
    _cmake = loadGeneric("config/CMakeLists.txt", cmake);
    if ((main && _main.empty())
        || (make && _make.empty())
        || (cmake && _cmake.empty()))
        return false;
    return true;
}
