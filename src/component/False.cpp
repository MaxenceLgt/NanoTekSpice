/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** False
*/

#include "False.hpp"

False::False() : AComponent()
{
    for (size_t i = 0; i < 2; i++)
        this->_links.push_back(nullptr);
}

False::False(const False &obj)
{
    this->_links = obj._links;
}

False::~False()
{
}

nts::Tristate False::compute(std::size_t pin)
{
    (void)pin;
    return nts::Tristate::False;
}
