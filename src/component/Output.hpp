/*
** EPITECH PROJECT, 2024
** Output
** File description:
** Output
*/

#pragma once

#include "AComponent.hpp"

class Output : public AComponent {
    public:
        Output();
        ~Output();
    public:
        nts::Tristate compute(std::size_t pin);
};
