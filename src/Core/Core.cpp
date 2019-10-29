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
}

void Core::fillPath(const std::string s)
{
    _inc.push_back("inc/" + s + ".hpp");
    _src.push_back("src/" + s + ".cpp");
}

void Core::createHpp(std::string s)
{
    _w.setFile(_f.getFileHpp());

    if (_p.getInheritance()) {
        _w.setInclude(_p.getProjectName() + ".hpp");
        _w.setInheritance(_p.getProjectName());
    }
    if (_p.getFolders()) {
        _d.createDir(_p.getProjectName() + "/inc", s);
        _w.create(s, _p.getProjectName() + "/inc/" + s, ".hpp");
        return;
    }
    _w.create(s, _p.getProjectName() + "/inc", ".hpp");
}

void Core::createCpp(std::string s)
{
    _w.setFile(_f.getFileCpp());

    if (_p.getInheritance())
            _w.setInheritance(_p.getProjectName());
    if (_p.getFolders()) {
        _d.createDir(_p.getProjectName() + "/src", s);
        _w.setInclude(s + "/" + s + ".hpp");
        _w.create(s, _p.getProjectName() + "/src/" + s, ".cpp");
        return;
    }
    _w.setInclude(s + ".hpp");
    _w.create(s, _p.getProjectName() + "/src", ".cpp");
}

void Core::createHppRoot(std::string s)
{
    _w.setFile(_f.getFileHpp());
    _w.create(s, _p.getProjectName() + "/inc", ".hpp");
}

void Core::createCppRoot(std::string s)
{
    _w.setFile(_f.getFileCpp());
    _w.setInclude("../inc/" + s + ".hpp");
    _w.create(s, _p.getProjectName() + "/src", ".cpp");
}

bool Core::generateCode()
{
    _d.createDir(_p.getProjectName(), "inc");
    _d.createDir(_p.getProjectName(), "src");

    Core::createHppRoot(_p.getProjectName());
    Core::createCppRoot(_p.getProjectName());
    Core::fillPath(_p.getProjectName());
    if (_p.getSubFiles().size() <= 0)
        return true;

    std::vector<std::string> subfiles = _p.getSubFiles();
    for (unsigned int i = 0; i < subfiles.size(); i++) {
        Core::createHpp(subfiles[i]);
        Core::createCpp(subfiles[i]);
        if (_p.getFolders())
            Core::fillPath(subfiles[i] + "/" + subfiles[i]);
        else
            Core::fillPath(subfiles[i]);
    }
    return true;
}

bool Core::generateMain()
{
    if (!_p.getMain())
        return false;
    _w.setFile(_f.getMain());
    _w.setInc(_inc);
    _w.create("main", _p.getProjectName(), "main");
    _src.push_back("main.cpp");
    return true;
}

bool Core::generateMakefile()
{
    if (!_p.getMakefile())
        return false;
    _w.setFile(_f.getMakefile());
    _w.setSrc(_src);
    _w.create("Makefile", _p.getProjectName(), "Makefile");
    return true;
}

bool Core::generateCMake()
{
    if (!_p.getCMake())
        return false;
    _w.setFile(_f.getCMake());
    _w.setInc(_inc);
    _w.setSrc(_src);
    _w.create("CMakeLists", _p.getProjectName(), "CMake");
    return true;
}

void Core::buildProject()
{
    std::string s;

    if (_p.getMakefile() == true)
        s = "make && make clean";
    if (_p.getCMake() == true)
        s = "cmake CMakeLists.txt && make";
    chdir(_p.getProjectName().c_str());
    system(s.c_str());
}

bool Core::run()
{
    if (!_f.loadConfig(_p.getMain(), _p.getMakefile(), _p.getCMake()))
        return false;

    _w.setHeader(_f.getHeader());
    _d.createDir(".", _p.getProjectName());
    Core::generateCode();
    Core::generateMain();
    Core::generateMakefile();
    Core::generateCMake();
    if ((_p.getMakefile() || _p.getCMake()) && _p.getMain())
        Core::buildProject();
    return true;
}
