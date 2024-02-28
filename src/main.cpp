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

int main(int argc, char  **argv)
{
    if (argc != 2)
        return 84;
    try {
        std::shared_ptr<Circuit> circuit = std::make_shared<Circuit>();
        circuit->circuitparsing(argv[1]);
        circuit->compute();
        circuit->run();
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
