/*
** EPITECH PROJECT, 2019
** nanotekspice
** File description:
** member functions of Component.hpp
*/

#include "Component.hpp"

void Component::
setLink(std::size_t pin, nts::IComponent &other, size_t otherPin)
{
    this->setComponentPtr(pin, other);
    other.setComponentPtr(otherPin, *this);
    other.setComponentPin(otherPin, (this->_component[pin - 1].first));
}

Tristate Component::compute(std::size_t pin)
{
    return (this->_component[pin - 1]).first;
}

void Component::dump() const
{}

void Component::setComponentPin(size_t pin, nts::Tristate state)
{
    _component[pin - 1].first = state;
}

void Component::setComponentPtr(size_t pin, nts::IComponent &component)
{
    _component[pin - 1].second = &component;
}
