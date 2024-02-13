/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** IO
*/

#include "Input.hpp"

Input::Input()
{
    this->_actualState = nts::Tristate::Undefined;
    this->_futurState = nts::Tristate::Undefined;
    for (size_t i = 0; i < 2; i++)
        this->_links.push_back(nullptr);
}

Input::~Input()
{
}

nts::Tristate Input::compute(std::size_t pin)
{
    (void)pin;
    return this->_actualState;
}

void Input::simulate(std::size_t tick)
{
    (void)tick;
    this->_actualState = this->_futurState;
};
