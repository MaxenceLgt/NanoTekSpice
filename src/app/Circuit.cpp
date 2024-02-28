/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** Circuit
*/

#include <iostream>
#include "Circuit.hpp"

Circuit::Circuit()
{
}

Circuit::Circuit(const std::string &component)
{
    parser.parsingFile("src/config/" + component + "_config.nts", this->_mapComponent, this->_linkIndex);
}

Circuit::~Circuit()
{
}

std::shared_ptr<nts::IComponent> Circuit::findComponent(const std::string name)
{
    auto key = this->_mapComponent.find(name);
    if (key == this->_mapComponent.end()) {
        return nullptr;
    }
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

void Circuit::display()
{
    nts::Tristate computeValue = nts::Tristate::Undefined;

    std::cout << "tick: " << this->_tick << std::endl;
    std::cout << "input(s):" << std::endl;
    std::list<std::string> input = this->parser.getinput();
    input.sort();
    for (auto elm : input) {
        std::shared_ptr<nts::IComponent> component = findComponent(elm);
        if (component != nullptr) {
            computeValue = component->compute(this->_tick + 1);
        }
        if (computeValue == -1) {
            std::cout << "  " << elm << ": " << "U" << std::endl;
            computeValue = nts::Tristate::Undefined;
            continue;
        }
        std::cout << "  " << elm << ": " << computeValue << std::endl;
        computeValue = nts::Tristate::Undefined;
    }
    std::cout << "output(s):" << std::endl;
    std::list<std::string> output = this->parser.getoutput();
    output.sort();
    for (auto elm : output) {
        std::shared_ptr<nts::IComponent> component = findComponent(elm);
        if (component != nullptr) {
            computeValue = component->compute(this->_tick + 1);
        }
        if (computeValue == -1) {
            std::cout << "  " << elm << ": " << "U" << std::endl;
            computeValue = nts::Tristate::Undefined;
            continue;
        }
        std::cout << "  " << elm << ": " << computeValue << std::endl;
        computeValue = nts::Tristate::Undefined;
    }
    return;
}

void Circuit::compute()
{
    nts::Tristate computeValue = nts::Tristate::Undefined;

    std::list<std::string> input = this->parser.getinput();
    for (auto elm : input) {
        std::shared_ptr<nts::IComponent> component = findComponent(elm);
        if (component != nullptr)
            computeValue = component->compute(this->_tick + 1);
        if (computeValue == -1) {
            computeValue = nts::Tristate::Undefined;
            continue;
        }
        computeValue = nts::Tristate::Undefined;
    }
    std::list<std::string> output = this->parser.getoutput();
    output.sort();
    for (auto elm : output) {
        std::shared_ptr<nts::IComponent> component = findComponent(elm);
        if (component != nullptr)
            computeValue = component->compute(this->_tick + 1);
        if (computeValue == -1) {
            computeValue = nts::Tristate::Undefined;
            continue;
        }
        computeValue = nts::Tristate::Undefined;
    }
    return;
}

Parsing Circuit::getparser()
{
    return this->parser;
}

std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> Circuit::getmapcomp()
{
    return this->_mapComponent;
}

std::unordered_map<std::string, std::size_t> Circuit::getmaplink()
{
    return this->_linkIndex;
}

void Circuit::circuitparsing(std::string filename)
{
    this->parser.parsingFile(filename, _mapComponent, _linkIndex);
    return;
}

std::size_t Circuit::gettick()
{
    return _tick;
}

Circuit &Circuit::operator=(const nts::Tristate &state)
{
    (void)state;
    throw AComponent::ComponentError("Circuit : Trying to change state of circuit component");
}