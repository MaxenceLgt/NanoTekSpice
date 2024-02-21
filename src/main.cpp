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

void dump(std::shared_ptr<Circuit> CORP) {
    std::cout << "MAP CONTENT:" << std::endl;
    for (auto key : CORP->_map) {
        std::cout << key.first << std::endl;
    };
}

int main()
{
    try
    {
        ComponentFactory factory;

        std::shared_ptr<Circuit> CORP = std::make_shared<Circuit>();
        CORP->parser.parsingFile("./src/config/and_config.nts", CORP->_map, CORP->_links);
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
        std::cout << "TEST MAP CONTENT :" << std::endl;
        dump(CORP);
        for (auto test : CORP->_links) {
            if (test != nullptr)
                std::cout << "test pas null" << std::endl;
            if (test == nullptr)
                std::cout << "test est pd" << std::endl;

        }
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
