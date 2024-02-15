/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** Nand
*/

#include <iostream>
#include "Nand.hpp"

Nand::Nand() : AComponent()
{
    for (size_t i = 0; i < 4; i++)
        this->_links.push_back(nullptr);
}

Nand::Nand(const Nand &obj)
{
    this->_links = obj._links;
}

Nand::~Nand()
{
}

nts::Tristate Nand::compute(std::size_t pin)
{
    nts::Tristate a = this->_links[1] != nullptr ? this->_links[1]->compute(pin) : nts::Tristate::Undefined;
    nts::Tristate b = this->_links[2] != nullptr ? this->_links[2]->compute(pin) : nts::Tristate::Undefined;

    if (a == nts::Tristate::Undefined && b == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    if ((a == nts::Tristate::True || b == nts::Tristate::True) && (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined))
        return nts::Tristate::Undefined;
    if (a == nts::Tristate::False || b == nts::Tristate::False)
        return nts::Tristate::True;
    if (a == nts::Tristate::True && b == nts::Tristate::True)
        return nts::Tristate::False;
    throw AComponent::ComponentError("Cas non géré :) !");
}
