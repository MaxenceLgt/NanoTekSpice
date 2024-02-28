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
        Output(const Output &obj);
        ~Output();
    public:
        nts::Tristate compute(std::size_t tick) override;
        Output &operator=(const nts::Tristate &state) override;
};
