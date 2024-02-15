/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** main
*/

#include <iostream>
#include "ComponentFactory.hpp"
#include "IComponent.hpp"

int main()
{
    try
    {
        ComponentFactory factory;

        std::shared_ptr<nts::IComponent> i1 = factory.createComponent("input");
        std::shared_ptr<nts::IComponent> i2 = factory.createComponent("input");
        std::shared_ptr<nts::IComponent> o1 = factory.createComponent("output");
        std::shared_ptr<nts::IComponent> nandComponent = factory.createComponent("nand");
        i1->setLink(1, *nandComponent, 1);
        i2->setLink(1, *nandComponent, 2);
        nandComponent->setLink(3, *o1, 1);
        *i1 = nts::Tristate::False;
        *i2 = nts::Tristate::False;
        std::cout << "Valeur de retour nand : " << o1->compute(1) << std::endl;
        i1->simulate(0);
        std::cout << "Valeur de retour nand : " << o1->compute(1) << std::endl;
        i2->simulate(0);
        std::cout << "Valeur de retour nand : " << o1->compute(1) << std::endl;
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
