/*
** EPITECH PROJECT, 2024
** B-OOP-400-REN-4-1-tekspice-arthur.doriel [WSL: Ubuntu]
** File description:
** AComponent
*/

#pragma once

#include "IComponent.hpp"
#include <memory>
#include <vector>

class AComponent : public nts::IComponent {
    protected:
        AComponent() {};
        ~AComponent();
    public:
        virtual nts::Tristate compute ([[maybe_unused]] std::size_t pin) override {return nts::Tristate::Undefined;};
        void simulate([[maybe_unused]] std::size_t tick) override {};
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
    public:
        AComponent &operator=(const nts::Tristate &state) override;
    public:
        class ComponentError : public std::exception {
            public:
                ComponentError(std::string msg) : _msg(msg) {};
                ~ComponentError() {};
            private:
                const char *what() const noexcept override {return _msg.c_str();};
            private:
                std::string _msg;
        };
    protected:
        std::vector<nts::IComponent *> _links;
};
