/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** AComponent
*/

#pragma once

#include "IComponent.hpp"
#include <vector>

class AComponent : public nts::IComponent {
    protected:
        AComponent(nts::Tristate state);
        ~AComponent();
    
    public:
        virtual nts::Tristate compute (std::size_t pin);
        void simulate(std::size_t tick);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

    protected:
        std::vector<nts::IComponent *> _links;
        nts::Tristate _state;
};
