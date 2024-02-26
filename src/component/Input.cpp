/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** IO
*/

#include "Input.hpp"

Input::Input() : AComponent()
{
    this->_actualState = nts::Tristate::Undefined;
    this->_futurState = nts::Tristate::Undefined;
}

Input::Input(const Input &obj)
{
    this->_actualState = obj._actualState;
    this->_futurState = obj._futurState;
}

Input::~Input()
{
}

nts::Tristate Input::compute(std::size_t tick)
{
    if (this->_tick == tick)
        return this->_actualState;
}

void Input::simulate(std::size_t tick)
{
    if (_links.size() != 1)
        return;
    this->_actualState = this->_futurState;
}

Input &Input::operator=(const nts::Tristate &state)
{
    if (this->_links.size() == 1)
        this->_futurState = state;
    return *this;
}
