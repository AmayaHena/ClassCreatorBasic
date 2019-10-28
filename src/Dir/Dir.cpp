/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** dir
*/

/* STD LIB */
#include <iostream>

/* MKDIR LIB */
#include <sys/stat.h>
#include <sys/types.h>

#include "Dir/Dir.hpp"

bool Dir::createDir(const std::string path, const std::string name)
{
    std::string s = path + "/" + name;
    struct stat buffer;

    if (stat(s.c_str(), &buffer) == 0) {
        std::cout << "Dir already exits : " << s << std::endl;
        return false;
    }
    if (mkdir(s.c_str(), 0777) == -1) {
        std::cout << "Failed to create dir : " << s << std::endl;
        return false;
    }
    std::cout << "Created dir : " << s << std::endl;
    return true;
}

bool Dir::createInc(const std::string path)
{
    return (Dir::createDir(path, "inc"));
}

bool Dir::createSrc(const std::string path)
{
    return (Dir::createDir(path, "src"));
}
