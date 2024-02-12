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
    public:
        AComponent();
        ~AComponent();
    
    protected:
        std::vector<nts::IComponent *> _links;
        nts::Tristate _state;
};
