/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** main
*/

#include <iostream>
#include <csignal>
#include <atomic>
#include "ComponentFactory.hpp"
#include "IComponent.hpp"
#include "AComponent.hpp"
#include "Circuit.hpp"

std::atomic_flag flag = ATOMIC_FLAG_INIT;

int main(int argc, char  **argv)
{
    if (argc != 2)
        return 84;
    try {
        std::shared_ptr<Circuit> circuit = std::make_shared<Circuit>();
        circuit->circuitparsing(argv[1]);

        std::signal(SIGINT, [](int /*signum*/) {
            flag.clear();
        });
        while (true) {
            std::regex pattern(R"((\w+)=(\w+)?\n?$)");

            std::smatch matches;
            std::string commande;

            std::cout << "> ";
            std::getline(std::cin, commande);

            if (commande == "exit")
                break;
            if (commande == "display") {
                circuit->display();
                continue;
            }
            if (commande == "loop") {
                while (flag.test_and_set()) {
                    circuit->simulate(circuit->gettick() + 1);
                    circuit->display();
                }
                continue;
            }
            if (commande == "simulate") {
                circuit->simulate(circuit->gettick() + 1);
                continue;
            }
            if (std::regex_search(commande, matches, pattern)) {
                if (circuit->findComponent(matches[1]) == nullptr) {
                    continue;
                }
                if (matches[2] != "0" && matches[2] != "1" && matches[2] != "U") {
                    continue;
                }
                std::shared_ptr<nts::IComponent> component = circuit->findComponent(matches[1]);
                if (matches[2] == "0") {
                    *component = nts::Tristate::False;
                }
                if (matches[2] == "1") {
                    *component = nts::Tristate::True;
                }
                if (matches[2] == "U") {
                    *component = nts::Tristate::Undefined;
                }
            }
            }
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
