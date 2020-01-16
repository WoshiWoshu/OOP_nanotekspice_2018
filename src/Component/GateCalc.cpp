/*
** EPITECH PROJECT, 2019
** nanotekspice
** File description:
** GateInit.cpp
*/

#include "Gate.hpp"

bool Gate::andGate(const bool &a, const bool &b) const
{
    if (a == true and b == true)
        return true;
    else
        return false;
}

bool Gate::orGate(const bool &a, const bool &b) const
{
    if (a == true or b == true)
        return true;
    else
        return false;
}

bool Gate::norGate(const bool &a, const bool &b) const
{
    if (a == true and b == true)
        return false;
    else if (a == true or b == true)
        return false;
    else
        return true;
}

bool Gate::xorGate(const bool &a, const bool &b) const
{
    if (a == true and b == true)
        return false;
    else if (a == true or b == true)
        return true;
    else
        return false;
}

bool Gate::nandGate(const bool &a, const bool &b) const
{
    if (a == true and b == true)
        return false;
    else if (a == true or b == true)
        return true;
    else
        return true;
}
