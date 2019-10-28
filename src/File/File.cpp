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
    return _makefile;
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

bool File::checkLoadConfig(bool main, bool make, bool cmake)
{
    if (File::checkDirExist("config") == false)
        return false;
    if ((File::checkFileExist("config/file.cpp") == false)
    || (File::checkFileExist("config/file.hpp") == false)
    || (File::checkFileExist("config/header.txt") == false))
        return false;
    if (main == true)
        if (File::checkFileExist("config/main.cpp") == false)
            return false;
    if (make == true)
        if (File::checkFileExist("config/makefile") == false)
            return false;
    if (cmake == true)
        if (File::checkFileExist("config/CMakeLists.txt") == false)
            return false;
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

bool File::loadConfig(bool main, bool make, bool cmake)
{
    if (checkLoadConfig(main, make, cmake) == false)
        return false;
    _fileHpp = File::loadFileToV("config/file.hpp");
    _fileCpp = File::loadFileToV("config/file.cpp");
    _header = File::loadFileToV("config/header.txt");
    if (main == true)
        _main = File::loadFileToV("config/main.cpp");
    if (make == true)
        _makefile = File::loadFileToV("config/makefile");
    if (cmake == true)
        _cmake = File::loadFileToV("config/CMakeLists.txt");
    return true;
}
