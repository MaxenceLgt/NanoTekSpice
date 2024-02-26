/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** AComponent
*/

#include <iostream>
#include "Circuit.hpp"
#include "AComponent.hpp"

AComponent::AComponent()
{
    this->_actualState = nts::Tristate::Undefined;
    this->_tick = 0;
}

AComponent::~AComponent()
{
}

nts::Tristate AComponent::compute(std::size_t tick)
{
    (void)tick;
    throw AComponent::ComponentError("Trying to compute something that can't be computed.");
}

void AComponent::simulate(std::size_t tick)
{
    (void)tick;
}

void AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    //TODO Faire setlink
    (void)pin;
    (void)other;
    (void)otherPin;
}

AComponent &AComponent::operator=(const nts::Tristate &state)
{
    (void)state;
    throw AComponent::ComponentError("Impossible to modify state of non clock/input component.");
}
