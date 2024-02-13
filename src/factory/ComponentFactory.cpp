/*
** EPITECH PROJECT, 2024
** ComponentFactory
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"

ComponentFactory::ComponentFactory()
{
    this->_creationMap["input"] = std::make_shared<IO>();
    this->_creationMap["output"] = std::make_shared<IO>();
    this->_creationMap["true"] = std::make_shared<True>();
    this->_creationMap["false"] = std::make_shared<False>();
    this->_creationMap["clock"] = std::make_shared<Clock>();
}

std::shared_ptr<nts::IComponent> ComponentFactory::createComponent([[maybe_unused]] const std::string &type)
{
    return nullptr;
}

std::shared_ptr<nts::IComponent> ComponentFactory::createMappedComponent([[maybe_unused]] const std::string &type)
{
    return nullptr;
}

std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> ComponentFactory::getMap() const
{
    return this->_creationMap;
}
