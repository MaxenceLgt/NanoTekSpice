/*
** EPITECH PROJECT, 2024
** ComponentFactory
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"

ComponentFactory::ComponentFactory()
{
    this->_creationMap["input"] = std::make_unique<IO>();
    this->_creationMap["output"] = std::make_unique<IO>();
    this->_creationMap["true"] = std::make_unique<True>();
    this->_creationMap["false"] = std::make_unique<False>();
    this->_creationMap["clock"] = std::make_unique<Clock>();
}

// std::unique_ptr<nts::IComponent> ComponentFactory::createComponent(const std::string &type)
// {
    
// }