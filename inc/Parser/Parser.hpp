/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

/* STD Library */
#include <iostream>

/* STD Types Library */
#include <vector>

/* Types Library */
#include <sstream>
#include <iterator>

class Parser {

    public:

        Parser();
        ~Parser() = default;

        /* Parsing public */
        bool helperCommand(void);
        int parsingProceed(std::vector<std::string> v);

        /* Getters */
        std::string getProjectName(void);
        bool getMain(void);
        std::vector<std::string> getSubFiles(void);
        bool getInheritance(void);
        bool getMakefile(void);
        bool getCMake(void);
        bool getFolders(void);

    private:

        /* Parsing private */
        std::string userInput(void);

        /* Parsing Types */
        std::string parsingString(const std::string type, const std::string convention);
        std::vector<std::string> parsingStoVector(const std::string type, const std::string convention);
        bool parsingBoolean(std::string s);

        /* Parsing AV */
        bool AVOptions(std::string s, bool tmp);
        bool parsingAV(std::vector<std::string> v);

        /* Setters */
        void setProjectName(const std::string s);
        void setMain(const bool b);
        void setSubFiles(const std::vector<std::string> v);
        void setInheritance(const bool b);
        void setMakefile(const bool b);
        void setCMake(const bool b);
        void setFolders(const bool b);

        /* Variables */
        std::string _project_name;
        bool _main;
        std::vector<std::string> _sub_files;
        bool _inheritance;
        bool _makefile;
        bool _cmake;
        bool _folders;

};

#endif /* !PARSER_HPP_ */
