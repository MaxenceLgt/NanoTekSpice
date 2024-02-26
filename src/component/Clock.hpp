/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** Clock
*/

#pragma once

#include "AComponent.hpp"

class Clock : public AComponent {
    public:
        Clock();
        Clock(const Clock &obj);
        ~Clock();
    public:
        nts::Tristate compute(std::size_t tick) override;
        void simulate(std::size_t tick) override;
        Clock &operator=(const nts::Tristate &state) override;
    private:
        nts::Tristate _futurState;
};
