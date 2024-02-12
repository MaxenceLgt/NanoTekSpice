/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** False
*/

#pragma once

#include "../inheritence/AComponent.hpp"

class False : public AComponent {
    public:
        False() : AComponent(nts::Tristate::False) {};
        ~False();

    public:
        nts::Tristate compute (std::size_t pin);
        // void simulate(std::size_t tick) {};
};
