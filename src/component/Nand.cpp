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
    this->_actualState = nts::Tristate::Undefined;
}

Nand::Nand(const Nand &obj)
{
    this->_links = obj._links;
}

Nand::~Nand()
{
}

nts::Tristate Nand::compute(std::size_t tick)
{
    nts::Tristate a = nts::Tristate::Undefined;
    nts::Tristate b = nts::Tristate::Undefined;

    if (this->_tick = tick)
        return this->_actualState;
    auto pair1 = this->_links.find(1);
    auto pair2 = this->_links.find(2);

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
