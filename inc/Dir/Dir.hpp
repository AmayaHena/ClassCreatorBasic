/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** dir
*/

#ifndef DIR_HPP_
#define DIR_HPP_

class Dir {

    public:

        Dir() = default;
        ~Dir() = default;

        /* Create Dirs */
        bool createDir(const std::string path, const std::string name);
        bool createInc(const std::string path);
        bool createSrc(const std::string path);

};

#endif /* !DIR_HPP_ */
