/*
** EPITECH PROJECT, 2019
** nanotekspice
** File description:
** initgatecomponent.cpp
*/

#include "Component.hpp"

void Component::initGate(const std::string &value)
{
    static_cast<void>(value);
    this->pullValAndInit("0", GATE_SIZE);
    _component[2].first = UNDEFINED;
    _component[3].first = UNDEFINED;
    _component[9].first = UNDEFINED;
    _component[10].first = UNDEFINED;
}
