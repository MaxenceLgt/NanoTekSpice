/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** parsing
*/

#include <iostream>
#include "parsing.hpp"
#include "Circuit.hpp"

Parsing::Parsing()
{
}

Parsing::~Parsing()
{
}

void Parsing::parsingFile(std::string fileName, std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> &_map, std::unordered_map<std::string, std::size_t> &_linkIndex)
{
    std::ifstream file (fileName);
    std::ostringstream oss;
    std::string ligne;
    std::regex pattern1(R"(^.links:([\s+]?#.*|\s*)?\n?$)");
    std::regex pattern2(R"(^.chipsets:([\s+]?#.*|\s*)?\n?$)");
    std::smatch matches;
    int level = 0;
    int nbr = 0;

    if (file.fail())
        throw Parsing::ParsingError("parsingFile : Invalid File.");
    while (std::getline(file, ligne)) {
        if (ligne.empty() || ligne[0] == '#')
            continue;
        if (std::regex_search(ligne, matches, pattern2) && level == 0) {
            level = 1;
            continue;
        }
        if (std::regex_search(ligne, matches, pattern1) && level == 1) {
            level = 2;
            continue;
        }
        if (level == 1) {
            nbr++;
            parsingChipset(ligne, _map, nbr, _linkIndex);
            continue;
        }
        if (level == 2) {
            parsingLink(ligne, _map);
            continue;
        }
        throw Parsing::ParsingError("parsingFile : Bad line.");
    }
    if (_map.empty())
        throw Parsing::ParsingError("parsingFile : Nocomponent.");
    file.close();
}

void Parsing::parsingChipset(std::string ligne, std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> &_map, int nbr, std::unordered_map<std::string, std::size_t> &_linkIndex)
{
    std::regex pattern(R"(^(\w+)\s+(\w+)(\s?#.*|\s*)?$)");

    std::smatch matches;
    if (std::regex_search(ligne, matches, pattern)) {
        if (mapContain(matches[2], _map))
            throw Parsing::ParsingError("parsingChipset : same name definition.");
        if (matches[1] == "output")
            this->output.push_back(matches[2]);
        if (matches[1] == "input")
            this->input.push_back(matches[2]);
        if (matches[1] == "clock")
            this->input.push_back(matches[2]);
        if (_factory.isMappedComponent(matches[1]) == true) {
            _map[matches[2]] = _factory.createComponent(matches[1]);
            _linkIndex[matches[2]] = nbr;
        } else {
            _map[matches[2]] = std::make_shared<Circuit>(matches[1]);
            _linkIndex[matches[2]] = nbr;
        }   
    }
}

void Parsing::parsingLink(std::string ligne, std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> &_map)
{
    std::regex pattern(R"(^(\w+):(\w+)\s+(\w+):(\w+)(\s?#.*|\s*)?$)");
    std::smatch matches;

    if (std::regex_search(ligne, matches, pattern)) {
        if (!this->mapContain(matches[1], _map) || !this->mapContain(matches[3], _map))
            throw Parsing::ParsingError("parsingLink : inexistant Component.");
        _map[matches[1]]->setLink(std::stoi(matches[2]), *_map[matches[3]], std::stoi(matches[4]), 0);
    }
}

bool Parsing::mapContain(std::string componentName, std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> &_map) {
    auto key = _map.find(componentName);
    if (key != _map.end())
        return true;
    return false;
}

std::list<std::string> Parsing::getinput()
{
    return this->input;
}

std::list<std::string> Parsing::getoutput()
{
    return this->output;
}