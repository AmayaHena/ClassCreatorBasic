/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** File
*/

#ifndef FILE_HPP_
#define FILE_HPP_

/* STD Library */
#include <vector>
#include <iostream>
#include <fstream>
#include <unistd.h>

class File {

	public:

		File() = default;
		~File() = default;

		/* Load Config public */
		bool loadConfig(bool main, bool make, bool cmake);

		/* Getters */
		std::vector<std::string> getMain(void);
		std::vector<std::string> getFileCpp(void);
		std::vector<std::string> getFileHpp(void);
		std::vector<std::string> getHeader(void);
		std::vector<std::string> getMakefile(void);
		std::vector<std::string> getCMake(void);

	private:

		/* Generic Tool to load file */
		std::vector<std::string> loadGeneric(const std::string path, bool request);

		/* Checks */
		bool checkDirExist(const std::string s);
		bool checkFileExist(const std::string s);

		/* Load Config private */
		std::vector<std::string> loadFileToV(std::string path);
		bool checkLoadConfig(bool main, bool make, bool cmake);

		/* Variables - Ressources containers for files*/
		std::vector<std::string> _fileHpp;
		std::vector<std::string> _fileCpp;
		std::vector<std::string> _header;
		std::vector<std::string> _main;
		std::vector<std::string> _make;
		std::vector<std::string> _cmake;

};

#endif /* !FILE_HPP_ */
