/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** AComponent
*/

#include <iostream>
#include "AComponent.hpp"

AComponent::~AComponent()
{
}

void AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > this->_links.size() || pin < 1)
        throw AComponent::ComponentError("Maxence tu sais pas setLink !");
    if (this->_links[pin] != &other) {
        this->_links[pin] = &other;
        other.setLink(otherPin, *this, pin);
    }
}

AComponent &AComponent::operator=(const nts::Tristate &state)
{
    (void)state;
    throw AComponent::ComponentError("Impossible to modify state of non clock/input component.");
}
