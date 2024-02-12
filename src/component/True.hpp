/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** True
*/

#pragma once

#include "../inheritence/AComponent.hpp"

class True : public AComponent {
    public:
        True() : AComponent(nts::Tristate::True) {};
        ~True();
    
    public:
        nts::Tristate compute (std::size_t pin);
        //void simulate(std::size_t tick) {};
};