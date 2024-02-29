/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** Circuit
*/

#pragma once

#include "AComponent.hpp"
#include "parsing.hpp"
#include <unordered_map>
#include <string>
#include <list>

class Circuit : public AComponent {
    public:
        Circuit();
        Circuit(const std::string &component);
        ~Circuit();
    public:
        Parsing getParser();
        std::size_t getTick();
        std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> getMapComponent();
        std::unordered_map<std::string, std::size_t> getMapLinks();
        std::shared_ptr<nts::IComponent> findComponent(const std::string name);
        nts::IComponent *getAtPin(std::size_t pin);
        void addComponent(std::shared_ptr<nts::IComponent> component, std::string name);
        void fillCircuit(std::string filename);
        void display();
    public:
        void simulate(std::size_t tick) override;
    public:
        Circuit &operator=(const nts::Tristate &state) override;
    private:
        std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> _mapComponent;
        std::unordered_map<std::string, std::size_t> _linkIndex;
        Parsing parser;
};
