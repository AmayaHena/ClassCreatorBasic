/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** Core
*/

#include "Core/Core.hpp"

Core::Core(std::vector<std::string> v)
{
    _p.parsingProceed(v);

    Core::setInheritanceName(_p.getProjectName());
    Core::setInheritance(_p.getProjectName() + ".hpp");
}

std::vector<std::string> Core::getInc()
{
    return _inc;
}

void Core::setInc(const std::vector<std::string> inc)
{
    _inc = inc;
}

std::vector<std::string> Core::getSrc()
{
    return _src;
}

void Core::setSrc(const std::vector<std::string> src)
{
    _src = src;
}

std::string Core::getInheritance()
{
    return _inheritance;
}

void Core::setInheritance(const std::string inheritance)
{
    _inheritance = inheritance;
}

std::string Core::getInheritanceName()
{
    return _inheritance_name;
}

void Core::setInheritanceName(const std::string inheritance_name)
{
    _inheritance_name = inheritance_name;
}

void Core::fillPath(const std::string s)
{
    _inc.push_back("inc/" + s + ".hpp");
    _src.push_back("src/" + s + ".cpp");
}

bool Core::generateSubFilesDir(std::vector<std::string> v)
{
    for (unsigned int i = 0; i < v.size(); i++) {
        _d.createDir(_p.getProjectName() + "/inc", v[i]);
        _d.createDir(_p.getProjectName() + "/src", v[i]);
        if (_p.getInheritance() == true) {
            _w.setFile(_f.getFileHpp());
            _w.setInclude(Core::getInheritance());
            _w.setInheritance(Core::getInheritanceName());
            _w.create(v[i], _p.getProjectName() + "/inc/" + v[i], ".hpp");
            _w.setFile(_f.getFileCpp());
            _w.setInclude(v[i] + "/" + v[i] + ".hpp");
            _w.setInheritance(Core::getInheritanceName());
            _w.create(v[i], _p.getProjectName() + "/src/" + v[i], ".cpp");
        } else {
            _w.setFile(_f.getFileHpp());
            _w.create(v[i], _p.getProjectName() + "/inc/" + v[i], ".hpp");
            _w.setFile(_f.getFileCpp());
            _w.setInclude(v[i] + "/" + v[i] + ".hpp");
            _w.create(v[i], _p.getProjectName() + "/src/" + v[i], ".cpp");
        }
        Core::fillPath(v[i] + "/" + v[i]);
    }
    return true;
}

bool Core::generateSubFilesWithoutDir(std::vector<std::string> v)
{
    for (unsigned int i = 0; i < v.size(); i++) {
        if (_p.getInheritance() == true) {
            _w.setFile(_f.getFileHpp());
            _w.setInclude(Core::getInheritance());
            _w.setInheritance(Core::getInheritanceName());
            _w.create(v[i], _p.getProjectName() + "/inc", ".hpp");
            _w.setFile(_f.getFileCpp());
            _w.setInclude(v[i] + ".hpp");
            _w.setInheritance(Core::getInheritanceName());
            _w.create(v[i], _p.getProjectName() + "/src", ".cpp");
        } else {
            _w.setFile(_f.getFileHpp());
            _w.create(v[i], _p.getProjectName() + "/inc", ".hpp");
            _w.setFile(_f.getFileCpp());
            _w.setInclude(v[i] + ".hpp");
            _w.create(v[i], _p.getProjectName() + "/src", ".cpp");
        }
        Core::fillPath(v[i]);
    }
    return true;
}

bool Core::generateSubFiles()
{
    std::vector<std::string> v = _p.getSubFiles();

    if (_p.getFolders() == true)
        return (Core::generateSubFilesDir(v));
    else
        return (Core::generateSubFilesWithoutDir(v));
    return true;
}

bool Core::generateFolderFiles()
{
    _d.createDir(_p.getProjectName(), "inc");
    _d.createDir(_p.getProjectName(), "src");
    _w.setFile(_f.getFileHpp());
    _w.create(_p.getProjectName(), _p.getProjectName() + "/inc", ".hpp");
    _w.setFile(_f.getFileCpp());
    _w.setInclude("../inc/" + _p.getProjectName() + ".hpp");
    _w.create(_p.getProjectName(), _p.getProjectName() + "/src", ".cpp");
    Core::fillPath(_p.getProjectName());
    return (Core::generateSubFiles());
}

bool Core::generateMain()
{
    _w.setFile(_f.getMain());
    _w.setInc(Core::getInc());
    _w.create("main", _p.getProjectName(), "main");
    _src.push_back("main.cpp");
    return true;
}

bool Core::generateMakefile()
{
    _w.setFile(_f.getMakefile());
    _w.setSrc(Core::getSrc());
    _w.create("Makefile", _p.getProjectName(), "Makefile");
    return true;
}

bool Core::generateCMake()
{
    _w.setFile(_f.getCMake());
    _w.setInc(Core::getInc());
    _w.setSrc(Core::getSrc());
    _w.create("CMakeLists", _p.getProjectName(), "CMake");
    return true;
}

void Core::buildProject()
{
    std::string s;

    if (_p.getCMake() == true)
        s = "cmake CMakeLists.txt && make";
    if (_p.getMakefile() == true)
        s = "make && make clean";
    chdir(_p.getProjectName().c_str());
    system(s.c_str());
}

bool Core::run()
{
    if (!_f.loadConfig(_p.getMain(), _p.getMakefile(), _p.getCMake()))
        return false;

    _w.setHeader(_f.getHeader());

    _d.createDir(".", _p.getProjectName());
    Core::generateFolderFiles();
    if (_p.getMain() == true)
        Core::generateMain();
    if (_p.getMakefile() == true)
        Core::generateMakefile();
    if (_p.getCMake() == true)
        Core::generateCMake();
    if ((_p.getMakefile() == true || _p.getCMake() == true) && _p.getMain() == true)
        Core::buildProject();
    return true;
}
