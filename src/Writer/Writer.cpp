/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** Writer
*/

/* STD Library */
#include <functional>

/* STD Types Library */
#include <fstream>
#include <string>

#include "Writer/Writer.hpp"

Writer::Writer() : _tag_ref("/*#!")
{
}

void Writer::setHeader(std::vector<std::string> v)
{
    _header = v;
}

std::vector<std::string> Writer::getHeader(void)
{
    return _header;
}

void Writer::setFile(const std::vector<std::string> v)
{
    _file = v;
}

std::vector<std::string> Writer::getFile(void)
{
    return _file;
}

void Writer::setSrc(const std::vector<std::string> v)
{
    _src = v;
}

void Writer::setInc(const std::vector<std::string> v)
{
    _inc = v;
}

void Writer::setInheritance(const std::string s)
{
    _inheritance = s;
}

void Writer::setInclude(const std::string s)
{
    _include = s;
}

void Writer::cleanRessources()
{
    _of.close();
    _file.clear();
    _src.clear();
    _inc.clear();
    _inheritance.clear();
    _include.clear();
}

bool Writer::findTag(const std::string s, std::string const tag)
{
    for (unsigned int i = 0; i < s.length(); i++)
        if (s.substr(i, tag.length()) == tag)
            return true;
    return false;
}

int Writer::occurenceNbInS(const std::string &s, const std::string &tag)
{
    int N = s.length();
    int M = tag.length();
    int match = 0;
    int j = 0;

    for (int i = 0; i <= N - M; i++) {
        for (j = 0; j < M; j++)
            if (s[i + j] != tag[j])
                break;
        if (j == M)
            match++;
    }
    return match;
}

std::ofstream Writer::createFileG(const std::string name, const std::string path, std::string type)
{
    std::string s;

    if (type == ".hpp" || type == ".cpp")
        s = path + "/" + name + type;
    else if (type == "main")
        s = path + "/main.cpp";
    else if (type == "Makefile")
        s = path + "/Makefile";
    else if (type == "CMake")
        s = path + "/CMakeLists.txt";
    std::ofstream file(s);
    std::cout << "File " << path << '/' << name << " created" << std::endl;
    return file;
}

void Writer::writeVectorInFile(const std::string s1, const std::vector<std::string> v, const std::string s2)
{
    for (unsigned int i = 0; i < v.size(); i++)
        _of << s1 << v[i] << s2 << std::endl;
}

void Writer::useTagCpp(const std::string tag, const std::string name)
{
    if (tag == "IncludeMain") {
        Writer::writeVectorInFile("#include \"", _inc, "\"");
        return;
    } if (tag == "IncludeCpp") {
        _of << "#include \"" << _include << "\"";
        return;
    } if (tag == "ConstructorCpp") {
        _of << name << "::" << name << "()";
        return;
    } if (!_inheritance.empty() && tag == "InheritanceCpp") {
        _of << " : " << _inheritance << "()";
        return;
    } if (tag == "DestructorCpp") {
        _of << name << "::~" << name << "()";
        return;
    }
}

void Writer::useTagHpp(const std::string tag, const std::string name)
{
    if (tag == "FileName") {
        _of << name;
        return;
    }
    if (tag == "IncludeInheritanceHpp" && _include.length() > 0) {
        _of << "#include \"" << _include << "\"";
        return;
    }
    if (!_inheritance.empty() && tag == "InheritanceHpp") {
        _of << " : public " << _inheritance;
        return;
    }
    if (tag == "ContructorMethod") {
        _of << name << "();";
        return;
    }
    if (tag == "DestructorMethod") {
        _of << "~" << name << "();";
        return;
    }
}

void Writer::useTagMake(const std::string tag, const std::string path)
{
    if (tag == "ProgramName") {
        _of << path;
        return;
    }
    if (tag == "SrcMakefile") {
        Writer::writeVectorInFile("\t\t", _src, "\t\\");
        return;
    }
    if (tag == "SrcCMake") {
        Writer::writeVectorInFile("\t", _src, "");
        return;
    }
    if (tag == "IncCMake") {
        Writer::writeVectorInFile("\t", _inc, "");
        return;
    }
}

void Writer::useTag(const std::string tag, const std::string name, const std::string path, const std::string type)
{
    if (tag == "Header") {
        Writer::writeVectorInFile("", _header, "");
        return;
    } if (type == ".hpp") {
        Writer::useTagHpp(tag, name);
        return;
    } if (type == ".cpp" || type == "main") {
        Writer::useTagCpp(tag, name);
        return;
    } if (type == "Makefile" || type == "CMake") {
        Writer::useTagMake(tag, path);
        return;
    }
}

void Writer::processTag(const std::string s, const std::string name, const std::string path, const std::string type)
{
    std::string buf;
    int k = Writer::occurenceNbInS(s, _tag_ref);
    int i = 0;
    int j = s.find(_tag_ref, 0);

    for (int m = 0; m != k; m++) {
        while (i < j)
            _of << s[i++];
        while (s[i++] != '!');
        while (s[i + 1] != '/')
            buf += s[i++];
        while (s[i++] != '/');
        Writer::useTag(buf, name, path, type);
        j = s.find(_tag_ref, j + 1);
        buf.clear();
    }
    for (unsigned int pos = i; pos < s.length(); pos++)
        _of << s[pos];
}

bool Writer::create(const std::string name, const std::string path, const std::string type)
{
    _of = Writer::createFileG(name, path, type);

    for (unsigned int i = 0; i < _file.size(); i++) {
        if (Writer::findTag(_file[i], _tag_ref) == true)
            Writer::processTag(_file[i], name, path, type);
        else
            _of << _file[i];
        _of << std::endl;
    }
    Writer::cleanRessources();
    return true;
}
