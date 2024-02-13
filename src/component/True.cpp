/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** True
*/

#include "True.hpp"

True::True()
{
    for (size_t i = 0; i < 2; i++)
        this->_links.push_back(nullptr);
}

True::~True()
{
}

nts::Tristate True::compute (std::size_t pin) {
    (void)pin;
    return nts::Tristate::True;
}