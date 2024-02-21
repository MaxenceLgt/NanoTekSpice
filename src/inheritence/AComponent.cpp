/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** AComponent
*/

#include <iostream>
#include "Circuit.hpp"
#include "AComponent.hpp"

AComponent::~AComponent()
{
}

void AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::IComponent *otherComponent = getLinkableComponent(&other, otherPin);

    if (pin > this->_links.size() || pin < 1)
        throw AComponent::ComponentError("Maxence tu sais pas setLink !");
    if (this->_links[pin] != otherComponent) {
        this->_links[pin] = otherComponent;
        other.setLink(otherPin, *this, pin);
    }
}

AComponent &AComponent::operator=(const nts::Tristate &state)
{
    (void)state;
    throw AComponent::ComponentError("Impossible to modify state of non clock/input component.");
}

nts::IComponent *AComponent::getLinkableComponent(nts::IComponent *component, std::size_t pin)
{
    Circuit *circuit = dynamic_cast<Circuit *>(component);
    if (circuit == nullptr)
        return component;
    Circuit *insideCircuit = dynamic_cast<Circuit *>(circuit->_links[pin]);
    if (insideCircuit == nullptr)
        return circuit->_links[pin];
    throw AComponent::ComponentError("AComponent: GG ! Maxence à brancher un circuit à un circuit");
}
