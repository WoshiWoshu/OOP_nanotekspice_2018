/*
** EPITECH PROJECT, 2019
** nanotekspice
** File description:
** ComponentInit.cpp
*/

#include "Component.hpp"

Component::Component() : _component(nullptr)
{
    _componentType = {{"input", &Component::initInput},
    {"output", &Component::initOutput}, {"gate", &Component::initGate}};
}

void Component::setComponentInit(const Tristate &pinVal, unsigned long newVal)
{
    auto i = 0;

    _component = std::make_unique<std::pair<Tristate, IComponent*>[]>(newVal);
    do {
        _component[i] = std::make_pair(pinVal, nullptr);
    } while (static_cast<unsigned long>(++i) < newVal);
}

std::unique_ptr<IComponent>
Component::createComponent(const std::string &type, const std::string &value)
{
    callMemberFunct(*this, _componentType[type])(value);
    return nullptr;
}
