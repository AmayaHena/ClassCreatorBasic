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

void File::setMain(const std::vector<std::string> v)
{
    _main = v;
}

std::vector<std::string> File::getFileCpp(void)
{
    return _fileCpp;
}

void File::setFileCpp(const std::vector<std::string> v)
{
    _fileCpp = v;
}

std::vector<std::string> File::getFileHpp(void)
{
    return _fileHpp;
}

void File::setFileHpp(const std::vector<std::string> v)
{
    _fileHpp = v;
}

std::vector<std::string> File::getHeader(void)
{
    return _header;
}

void File::setHeader(const std::vector<std::string> v)
{
    _header = v;
}

std::vector<std::string> File::getMakefile(void)
{
    return _makefile;
}

void File::setMakefile(const std::vector<std::string> v)
{
    _makefile = v;
}

std::vector<std::string> File::getCMake(void)
{
    return _cmake;
}

void File::setCMake(const std::vector<std::string> v)
{
    _cmake = v;
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
    File::setFileCpp(File::loadFileToV("config/file.cpp"));
    File::setFileHpp(File::loadFileToV("config/file.hpp"));
    File::setHeader(File::loadFileToV("config/header.txt"));
    if (main == true)
        File::setMain(File::loadFileToV("config/main.cpp"));
    if (make == true)
        File::setMakefile(File::loadFileToV("config/makefile"));
    if (cmake == true)
        File::setCMake(File::loadFileToV("config/CMakeLists.txt"));
    return true;
}
