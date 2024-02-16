/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** parsing
*/

#include "parsing.hpp"

Parsing::Parsing()
{
}

Parsing::~Parsing()
{
}

void Parsing::parsingFile(std::string fileName, std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> &_map)
{
    std::ifstream file (fileName);
    std::ostringstream oss;
    std::string ligne;
    int level = 0;
    int config = 0;

    if (file.fail())
        throw Parsing::ParsingError("parsingFile : Invalid File.");
    while (std::getline(file, ligne)) {
        if (fileName.find("config") && config == 0) {
            config = 1;
            continue;
        }
        if (ligne.empty() || ligne[0] == '#')
            continue;
        std::istringstream iss(ligne);
        std::string token;
        iss >> token;
        if (token == ".chipset:") {
            std::string secondWord;
            if (iss >> secondWord && secondWord[0] == '#') {
                level = 1;
                continue;
            }
        }
        if (token == ".link:" && level == 1) {
            std::string secondWord;
            if (iss >> secondWord && secondWord[0] == '#') {
                level = 2;
                continue;
            }
        }
        if (level = 1)
            parsingChipset(ligne, _map);
        if (level = 2)
            parsingLink(ligne, _map);
    }
    file.close();
}

int Parsing::parsingPin(std::string fileName)
{
    std::ifstream file (fileName);
    std::regex pattern(R"(^\b(\w+)\b$)");
    std::ostringstream oss;
    std::string ligne;
    int level = 0;

    if (file.fail())
        throw Parsing::ParsingError("parsingFile : Invalid File.");
    while (std::getline(file, ligne)) {
        std::smatch matches;
        if (std::regex_search(ligne, matches, pattern)) {
            return std::stoi(matches[1]);
        }
    }
    file.close();
}

void Parsing::parsingChipset(std::string ligne, std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> &_map)
{
    std::regex pattern(R"(^(\w+)\s+(\w+)(\s?#.*|\s*)?$)");

    std::smatch matches;
    if (std::regex_search(ligne, matches, pattern)) {
        if (mapContain(matches[2], _map))
            throw Parsing::ParsingError("parsingChipset : same name definition.");
        if (_factory.isMappedComponent(matches[1]) == true)
            _map[matches[2]] = _factory.createComponent(matches[1]);
        else {
            _map[matches[2]] = std::make_shared<Circuit>(matches[1]);
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
        _map[matches[1]]->setLink(std::stoi(matches[2]), *_map[matches[3]], std::stoi(matches[4]));
    }
}

bool Parsing::mapContain(std::string componentName, std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> &_map) {
    auto key = _map.find(componentName);
    if (key != _map.end())
        return true;
    return false;
}