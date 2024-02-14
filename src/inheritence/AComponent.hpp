/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** AComponent
*/

#pragma once

#include "IComponent.hpp"
#include <memory>
#include <vector>

class AComponent : public nts::IComponent {
    protected:
        AComponent() {};
        ~AComponent();
    public:
        virtual nts::Tristate compute ([[maybe_unused]] std::size_t pin) {return nts::Tristate::Undefined;};
        void simulate([[maybe_unused]] std::size_t tick) {};
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        //std::shared_ptr<nts::IComponent> clone() {return nullptr;};
    protected:
        std::vector<nts::IComponent *> _links;
};
