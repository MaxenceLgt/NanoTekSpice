/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** componentIO
*/

#pragma once

#include "../inheritence/AComponent.hpp"

class IO : public AComponent {
    public:
        IO() : AComponent(nts::Tristate::Undefined) {};
        ~IO();

    public:
        nts::Tristate compute (std::size_t pin);
        // void simulate(std::size_t tick);
};
