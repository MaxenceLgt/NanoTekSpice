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
    //std::cout << "PASSAGE DANS LA FONCTION" << std::endl;
    nts::IComponent *component1 = nullptr;
    std::size_t pin2 = otherPin;

    if (dynamic_cast<Circuit *>(this)) {
        //std::cout << "PASSAGE DANS LE PREMIER IF" << std::endl;
        component1 = dynamic_cast<Circuit *>(this)->getAtPin(pin);
        if (component1 != nullptr) {
            //std::cout << "THIS EST UN CIRCUIT DCP JE CHOPE IN / OUT " << std::endl;
            return component1->setLink(0, other, otherPin);
        }
        return;
    }
    if (dynamic_cast<Circuit *>(&other)) {
        //std::cout << "PASSAGE DANS LE DEUXIEME IF" << std::endl;
        component1 = dynamic_cast<Circuit *>(&other)->getAtPin(otherPin);
        pin2 = 0;
    } else
        component1 = &other;
    auto pair = this->_links.find(pin);
    if (pair != this->_links.end() && pair->second.back() == component1) {
        //std::cout << "LE COMPONENT EST LINK" << std::endl;
        return;
    }
    //std::cout << "JE PUSH A " << pin << "UN NOUVEAU COMPONENT" << std::endl;
    this->_links[pin].push_back(component1);
    component1->setLink(pin2, *this, pin);
}

AComponent &AComponent::operator=(const nts::Tristate &state)
{
    (void)state;
    throw AComponent::ComponentError("Impossible to modify state of non clock/input component.");
}
