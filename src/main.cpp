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

        //std::shared_ptr<Circuit> CORP = std::make_shared<Circuit>();
        //CORP->parser.parsingFile("./src/config/and_config.nts", CORP->_mapComponent, CORP->_linkIndex);
        std::shared_ptr<nts::IComponent> i1 = factory.createComponent("input");
        std::shared_ptr<nts::IComponent> i2 = factory.createComponent("input");
        std::shared_ptr<nts::IComponent> o1 = factory.createComponent("output");
        std::shared_ptr<nts::IComponent> andComponent = std::make_shared<Circuit>("and");

        // std::cout << "AND component :" << std::endl;
        // for (auto pair : andComponent->_mapComponent)
        //     std::cout << pair.first << std::endl;
        // std::cout << "AND linkIndex:" << std::endl;
        // for (auto pair : andComponent->_linkIndex)
        //     std::cout << pair.first << " : " << pair.second << std::endl;
        


        i1->setLink(1, *andComponent, 1);
        i2->setLink(1, *andComponent, 2);
        andComponent->setLink(3, *o1, 1);
        *i1 = nts::Tristate::True;
        *i2 = nts::Tristate::True;
        std::cout << "Valeur de retour and : " << o1->compute(1) << std::endl;
        i1->simulate(1);
        std::cout << "Valeur de retour and : " << o1->compute(2) << std::endl;
        i2->simulate(1);
        std::cout << "Valeur de retour and : " << o1->compute(3) << std::endl;
        *i2 = nts::Tristate::False;
        i2->simulate(1);
        std::cout << "Valeur de retour and : " << o1->compute(4) << std::endl;
        //std::cout << "TEST MAP CONTENT :" << std::endl;
        //dump(CORP);
        //for (auto test : CORP->_links) {
        //    if (test != nullptr)
        //        std::cout << "test pas null" << std::endl;
        //    if (test == nullptr)
        //        std::cout << "test est pd" << std::endl;
//
        //}
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
