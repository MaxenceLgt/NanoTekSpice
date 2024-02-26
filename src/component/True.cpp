/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** True
*/

#include "True.hpp"

True::True() : AComponent()
{
    this->_actualState = nts::Tristate::True;
}

True::True(const True &obj)
{
    this->_links = obj._links;
}

True::~True()
{
}

nts::Tristate True::compute (std::size_t tick)
{
    this->_tick = tick;
    return this->_actualState;
}
