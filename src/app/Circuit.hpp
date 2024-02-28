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
        std::shared_ptr<nts::IComponent> findComponent(const std::string name);
        void addComponent(std::shared_ptr<nts::IComponent> component, std::string name);
        Parsing getparser();
        std::size_t gettick();
        void circuitparsing(std::string filename);
        std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> getmapcomp();
        std::unordered_map<std::string, std::size_t> getmaplink();
        void display();
        void computeComponents();
        void run();
    public:
        void simulate(std::size_t tick) override;
    public:
        nts::IComponent *getAtPin(std::size_t pin);
    public:
        Circuit &operator=(const nts::Tristate &state) override;
    private:
        std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> _mapComponent;
        std::unordered_map<std::string, std::size_t> _linkIndex;
        Parsing parser;
};
