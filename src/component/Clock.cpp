/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock() : AComponent()
{
    this->_actualState = nts::Tristate::Undefined;
    this->_futurState = nts::Tristate::Undefined;
}

Clock::Clock(const Clock &obj)
{
    this->_links = obj._links;
}

Clock::~Clock()
{
}

nts::Tristate Clock::compute(std::size_t tick)
{
    this->_tick = tick;
    return this->_actualState;
}

void Clock::simulate(std::size_t tick)
{
    this->_actualState = this->_futurState;

    (void)tick;
    if (this->_futurState == nts::Tristate::True)
        this->_futurState = nts::Tristate::False;
    else if (this->_futurState == nts::Tristate::False)
        this->_futurState = nts::Tristate::True;
}

Clock &Clock::operator=(const nts::Tristate &state)
{
    this->_futurState = state;
    return *this;
}