/*
** EPITECH PROJECT, 2024
** ComponentFactory
** File description:
** ComponentFactory
*/

#ifndef COMPONENT_FACTORY_HPP_
    #define COMPONENT_FACTORY_HPP_

    #include <memory>
    #include <string>
    #include <unordered_map>
    #include <exception>
    #include <functional>
    #include "AComponent.hpp"
    #include "True.hpp"
    #include "False.hpp"
    #include "Input.hpp"
    #include "Output.hpp"
    #include "Clock.hpp"
    #include "Nand.hpp"

class ComponentFactory {
    public:         
        ComponentFactory();
        ~ComponentFactory() {};
    public:
        bool isMappedComponent(const std::string &type);
        std::shared_ptr<nts::IComponent> createComponent(const std::string &type);
        std::unordered_map<std::string, std::function<std::shared_ptr<nts::IComponent>()>> getMap() const;
    public:
        class FactoryError : public std::exception {
            public:
                FactoryError(std::string msg) : _msg(msg) {};
                ~FactoryError() {};
            private:
                const char *what() const noexcept override {return _msg.c_str();};
            private:
                std::string _msg;
        };
    private:
        std::unordered_map<std::string, std::function<std::shared_ptr<nts::IComponent>()>> _creationMap;
};

#endif /* !COMPONENT_FACTORY_HPP_ */
