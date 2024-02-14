/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** Nand
*/

#pragma once

#include "AComponent.hpp"

class Nand : public AComponent {
    public:
        Nand();
        Nand(const Nand &obj);
        ~Nand();
    public:
        nts::Tristate compute(std::size_t pin);
};
