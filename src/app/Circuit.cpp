/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit()
{
}

Circuit::~Circuit()
{
}

std::shared_ptr<nts::IComponent> Circuit::findComponent(const std::string name)
{
    auto key = this->_map.find(name);
    if (key != this->_map.end())
        return nullptr;
    return key->second;
}

void Circuit::addComponent(std::shared_ptr<nts::IComponent> component, std::string name)
{
    if (component == nullptr)
        throw AComponent::ComponentError("Circuit: Trying to add nullptr to map!");
    this->_map[name] = component;
}
