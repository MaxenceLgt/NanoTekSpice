/*
** EPITECH PROJECT, 2024
** ComponentFactory
** File description:
** ComponentFactory
*/

#include <fstream>
#include "ComponentFactory.hpp"

ComponentFactory::ComponentFactory()
{
    this->_creationMap["input"] = []() {return std::make_shared<Input>();};
    this->_creationMap["output"] = []() {return std::make_shared<Output>();};
    this->_creationMap["true"] = []() {return std::make_shared<True>();};;
    this->_creationMap["false"] = []() {return std::make_shared<False>();};
    this->_creationMap["clock"] = []() {return std::make_shared<Clock>();};
    this->_creationMap["nand"] = []() {return std::make_shared<Nand>();};
}

bool ComponentFactory::isMappedComponent(const std::string &type)
{
    auto key = this->_creationMap.find(type);
    if (key != this->_creationMap.end())
        return true;
    return false;
}

std::shared_ptr<nts::IComponent> ComponentFactory::createComponent(const std::string &type)
{
    if (this->isMappedComponent(type) == false)
        throw ComponentFactory::FactoryError("Don't try to create invalid component ;)");
    return this->_creationMap[type]();
}

std::unordered_map<std::string, std::function<std::shared_ptr<nts::IComponent>()>> ComponentFactory::getMap() const
{
    return this->_creationMap;
}
