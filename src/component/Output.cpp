/*
** EPITECH PROJECT, 2024
** Output
** File description:
** Output
*/

#include <iostream>
#include "Output.hpp"

Output::Output() : AComponent()
{
    this->_actualState = nts::Tristate::Undefined;
}

Output::Output(const Output &obj)
{
    this->_links = obj._links;
}

Output::~Output()
{
}

nts::Tristate Output::compute(std::size_t tick)
{
    if (this->_tick == tick || _links.size() < 1)
        return this->_actualState;
    this->_tick = tick;
    auto pair = this->_links.find(1);
    if (pair != this->_links.end()) {
        std::vector<nts::IComponent *> linkedComponents = pair->second;
        if (!linkedComponents.empty() && linkedComponents.at(0) != nullptr) {
            this->_actualState = linkedComponents.at(0)->compute(tick);
            return this->_actualState;
        }
    }
    return this->_actualState;
}
