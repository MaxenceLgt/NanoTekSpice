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

Circuit::Circuit(const std::string &component)
{
    (void)component;
    //parser.parsingFile("src/config/" + component + "_config.nts", this->_mapComponent,
    //this->_links, this->_linkIndex);
}

Circuit::~Circuit()
{
}

std::shared_ptr<nts::IComponent> Circuit::findComponent(const std::string name)
{
    auto key = this->_mapComponent.find(name);
    if (key != this->_mapComponent.end())
        return nullptr;
    return key->second;
}

void Circuit::addComponent(std::shared_ptr<nts::IComponent> component, std::string name)
{
    if (component == nullptr)
        throw AComponent::ComponentError("Circuit: Trying to add nullptr to map!");
    this->_mapComponent[name] = component;
}

void Circuit::simulate(std::size_t tick)
{
    this->_tick = tick;
    for (auto pair : this->_mapComponent)
        if (pair.second)
            pair.second->simulate(tick);
}

nts::IComponent *Circuit::getAtPin(std::size_t pin)
{
    std::string componentName;

    for (auto pair : this->_linkIndex) {
        if (pair.second == pin)
            componentName = pair.first;
    }
    if (componentName.empty())
        return nullptr;
    auto pair = this->_mapComponent.find(componentName);
    if (pair == this->_mapComponent.end())
        return nullptr;
    return pair->second.get();
}
