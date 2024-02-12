/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** Clock
*/

#pragma once

#include "../inheritence/AComponent.hpp"

class Clock : public AComponent {
    public:
        Clock() : AComponent(nts::Tristate::Undefined) {};
        ~Clock();

    public:
        nts::Tristate compute (std::size_t pin);
        // void simulate(std::size_t tick);
};
