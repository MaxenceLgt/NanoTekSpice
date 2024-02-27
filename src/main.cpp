/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** main
*/

#include <iostream>
#include "ComponentFactory.hpp"
#include "IComponent.hpp"
#include "AComponent.hpp"
#include "Circuit.hpp"

int main()
{
    try {
    
        ComponentFactory factory;

        std::shared_ptr<nts::IComponent> i1 = factory.createComponent("input");
        std::shared_ptr<nts::IComponent> i2 = factory.createComponent("input");
        std::shared_ptr<nts::IComponent> o1 = factory.createComponent("output");
        std::shared_ptr<nts::IComponent> andComponent = std::make_shared<Circuit>("4081");

        i1->setLink(1, *andComponent, 1, 0);
        i2->setLink(1, *andComponent, 2, 0);
        andComponent->setLink(3, *o1, 1, 0);
        *i1 = nts::Tristate::True;
        *i2 = nts::Tristate::True;
        std::cout << "Valeur de retour Undefined / Undefined : " << o1->compute(1) << std::endl;
        i1->simulate(1);
        std::cout << "Valeur de retour True / Undefined : " << o1->compute(2) << std::endl;
        i2->simulate(1);
        std::cout << "Valeur de retour True / True : " << o1->compute(3) << std::endl;
        *i2 = nts::Tristate::False;
        i2->simulate(1);
        std::cout << "Valeur de retour True / False : " << o1->compute(4) << std::endl;
        *i1 = nts::Tristate::False;
        i1->simulate(1);
        std::cout << "Valeur de retour False / False : " << o1->compute(5) << std::endl;
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
