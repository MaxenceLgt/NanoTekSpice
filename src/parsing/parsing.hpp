/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** parsing
*/

#ifndef PARSING_HPP_
    #define PARSING_HPP_
    #include <string>
    #include <fstream>
    #include <vector>
    #include <sstream>
    #include <unordered_map>
    #include <exception>
    #include <functional>
    #include <memory>
    #include "IComponent.hpp"
    #include "ComponentFactory.hpp"
    #include <regex>
    #include "Circuit.hpp"

class Parsing
{
    public:
        Parsing();
        ~Parsing();

    public:
        void parsingFile(std::string fileName, std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> &_map, std::vector<std::shared_ptr<nts::IComponent>> &link);
        int parsingPin(std::string ligne);
        void parsingChipset(std::string ligne, std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> &_map);
        void parsingLink(std::string ligne, std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> &_map);
        bool mapContain(std::string componentName, std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> &_map);

        class ParsingError : public std::exception {
            public:
                ParsingError(std::string msg) : _msg(msg) {};
                ~ParsingError() {};
            private:
                const char *what() const noexcept override {return _msg.c_str();};
            private:
                std::string _msg;
        };

    protected:
        ComponentFactory _factory;
};

#endif /* !PARSING_HPP_ */
