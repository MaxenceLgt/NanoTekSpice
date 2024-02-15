/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** False
*/

#pragma once

#include "AComponent.hpp"

class False : public AComponent {
    public:
        False();
        False(const False &obj);
        ~False();
    public:
        nts::Tristate compute(std::size_t pin) override;
};
