/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** main
*/

#include "ComponentFactory.hpp"
#include "IComponent.hpp"

int main()
{
    ComponentFactory factory;

    std::shared_ptr<nts::IComponent> i1 = factory.createComponent("input");
    std::shared_ptr<nts::IComponent> o1 = factory.createComponent("output");

    i1->setLink(1, *o1, 1);
    return 0;
}
