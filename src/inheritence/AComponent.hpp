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
        AComponent(nts::Tristate state = nts::Tristate::Undefined) : _state(state) {};
        ~AComponent();
    
    public:
        virtual nts::Tristate compute ([[maybe_unused]] std::size_t pin) {return this->_state;};
        void simulate([[maybe_unused]] std::size_t tick) {};
        void setLink([[maybe_unused]] std::size_t pin, [[maybe_unused]] nts::IComponent &other, [[maybe_unused]] std::size_t otherPin) {};

    protected:
        std::vector<nts::IComponent *> _links;
        nts::Tristate _state;
};
