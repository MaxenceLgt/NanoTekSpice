/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** True
*/

#pragma once

#include "AComponent.hpp"

class True : public AComponent {
    public:
        True();
        True(const True &obj);
        ~True();
    public:
        nts::Tristate compute(std::size_t tick) override;
};