/*
** EPITECH PROJECT, 2019
** NanotekSpice
** File description:
** Icomponent.hpp
*/

#pragma once

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent
    {
    public:
        virtual ~IComponent() = default;
    public:
        virtual Tristate compute(std::size_t pin = 1) = 0;
        virtual void setLink(std::size_t pin, IComponent &other,
        std::size_t otherPin) = 0;
        virtual void dump() const = 0;
        
        virtual void setComponentPin(size_t pin, nts::Tristate state) = 0;
        virtual void setComponentPtr(size_t pin, nts::IComponent &component) = 0;
        virtual std::unique_ptr<IComponent>
        createComponent(const std::string &type, const std::string &value) = 0;
        
        //std::unique_ptr<std::pair<nts::Tristate, IComponent*>[]> _component = 0;
    };
}
