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
    #include "AComponent.hpp"
    #include "True.hpp"
    #include "False.hpp"
    #include "IO.hpp"
    #include "Clock.hpp"
    #include "Nand.hpp"

class ComponentFactory {
    public:         
        ComponentFactory();
        ~ComponentFactory() {};
    public:
        std::shared_ptr<nts::IComponent> createComponent([[maybe_unused]] const std::string &type);
        std::shared_ptr<nts::IComponent> createMappedComponent([[maybe_unused]] const std::string &type);
        std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> getMap() const;
    private:
        std::unordered_map<std::string, std::shared_ptr<nts::IComponent>> _creationMap;
};

#endif /* !COMPONENT_FACTORY_HPP_ */
