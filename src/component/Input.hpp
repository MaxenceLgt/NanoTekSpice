/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** componentIO
*/

#pragma once

#include "AComponent.hpp"

class Input : public AComponent {
    public:
        Input();
        Input(const Input &obj);
        ~Input();
    public:
        nts::Tristate compute(std::size_t pin) override;
        void simulate(std::size_t tick) override;
        Input &operator=(const nts::Tristate &state) override;
    private:
        nts::Tristate _futurState;
};