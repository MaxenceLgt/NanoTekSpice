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
    #include "IComponent.hpp"
    #include "IO.hpp"
    #include "True.hpp"
    #include "False.hpp"
    #include "Clock.hpp"

class ComponentFactory {
    public:         
        ComponentFactory();
        ~ComponentFactory() {};
    public:
        std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
    private:
        std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> _creationMap;
};

#endif /* !COMPONENT_FACTORY_HPP_ */
