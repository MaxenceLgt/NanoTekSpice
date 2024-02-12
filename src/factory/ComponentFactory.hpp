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
    #include "../inheritence/AComponent.hpp"
    #include "../component/True.hpp"
    #include "../component/False.hpp"
    #include "../component/IO.hpp"
    #include "../component/Clock.hpp"

class ComponentFactory {
    public:         
        ComponentFactory();
        ~ComponentFactory() {};
    public:
        std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
        std::unique_ptr<nts::IComponent> createMappedComponent(const std::string &type);
        std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> getMap() const;
        void addComponent(const std::string &type, std::unique_ptr<nts::IComponent> component);
    private:
        std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> _creationMap;
};

#endif /* !COMPONENT_FACTORY_HPP_ */
