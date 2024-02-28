/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** False
*/

#include "False.hpp"

False::False() : AComponent()
{
    this->_actualState = nts::Tristate::False;
}

False::False(const False &obj)
{
    this->_links = obj._links;
}

False::~False()
{
}

nts::Tristate False::compute(std::size_t tick)
{
    this->_tick = tick;
    return this->_actualState;
}

False &False::operator=(const nts::Tristate &state)
{
    (void)state;
    throw AComponent::ComponentError("False : Trying to change state of false component");
}