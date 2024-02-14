/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** AComponent
*/

#include "AComponent.hpp"

AComponent::~AComponent()
{
}

void AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > this->_links.size() || pin < this->_links.size())
        return;
    if (this->_links[pin] != &other) {
        this->_links[pin] = &other;
        other.setLink(otherPin, *this, pin);
    }
}
