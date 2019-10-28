/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

/* STD LIB */
#include <iostream>

/* STD Types LIB */
#include <vector>
#include <string>

/* Class */
#include "../Dir/Dir.hpp"
#include "../File/File.hpp"
#include "../Parser/Parser.hpp"
#include "../Writer/Writer.hpp"

class Core {

	public:

		Core(std::vector<std::string> v);
		~Core() = default;

		/* Run the program */
		bool run(void);

	private:

		/* Fill Path for Ressources _inc and _src */
		void fillPath(const std::string s);

		/* Generation Folders and Files */
		void createGeneric(std::vector<std::string> file, std::string name, std::string path, std::string type);
		bool generateSubFilesDir(std::vector<std::string> v);
		bool generateSubFilesWithoutDir(std::vector<std::string> v);
		bool generateSubFiles(void);
		bool generateFolderFiles(void);

		/* Generation Main function */
		bool generateMain(void);

		/* Generate Makefile */
		bool generateMakefile(void);

		/* Generate Makefile */
		bool generateCMake(void);

		/* tools */
		void buildProject(void);

		/* Class */
		Parser _p;
		Dir _d;
		File _f;
		Writer _w;

		/* Variables */
		std::vector<std::string> _inc;
		std::vector<std::string> _src;
		std::string _inheritance_name;
		std::string _inheritance;

};

#endif /* !CORE_HPP_ */
