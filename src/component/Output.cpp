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
    for (size_t i = 0; i < 2; i++)
        this->_links.push_back(nullptr);
}

Output::Output(const Output &obj)
{
    this->_links = obj._links;
}

Output::~Output()
{
}

nts::Tristate Output::compute(std::size_t pin)
{
    if (this->_links[1] == nullptr)
        return nts::Tristate::Undefined;
    return this->_links[1]->compute(pin);
}
