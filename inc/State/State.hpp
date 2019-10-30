/*
** EPITECH PROJECT, 2019
** ClassCreatorWIP
** File description:
** State
*/

#ifndef STATE_HPP_
#define STATE_HPP_

/* STD LIB */
#include <iostream>
#include <vector>

/* Class */
#include "Parser/Parser.hpp"
#include "Writer/Writer.hpp"
#include "Dir/Dir.hpp"

class State {

	public:

        State() = default;
		~State() = default;

        /* Tools - state the writer and launch writer */
		void createHpp(Parser *p, Writer *w, std::vector<std::string> file, std::string s);
		void createCpp(Parser *p, Writer *w, std::vector<std::string> file, std::string s);
		void createHppRoot(Parser *p, Writer *w, std::vector<std::string> file, std::string s);
        void createCppRoot(Parser *p, Writer *w, std::vector<std::string> file, std::string s);
        void generateMain(Parser *p, Writer *w, std::vector<std::string> file, std::vector<std::string> inc);
        void generateMakefile(Parser *p, Writer *w, std::vector<std::string> file, std::vector<std::string> src);
        void generateCMake(Parser *p, Writer *w, std::vector<std::string> file, std::vector<std::string> inc, std::vector<std::string> src);

    private:

		Dir _d;

};

#endif /* !STATE_HPP_ */
