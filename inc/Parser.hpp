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
		void parsingProceed(const std::vector<std::string> v);

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

		/* Variables - Ressources for user inputs */
		std::string _project_name;
		bool _main;
		std::vector<std::string> _sub_files;
		bool _inheritance;
		bool _makefile;
		bool _cmake;
		bool _folders;

};

#endif /* !PARSER_HPP_ */
