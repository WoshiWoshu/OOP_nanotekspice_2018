/*
** EPITECH PROJECT, 2019
** nanotekspice
** File description:
** content of function pointer to init simple component
*/

#include <algorithm>
#include "Component.hpp"

static std::string valueCpy = "";

static std::unordered_set<std::pair<std::string, Tristate>, HashMyPair>
pinValConv = {
    {"1", TRUE}, {"0", FALSE}, {"-1", UNDEFINED}
};

bool StrToEnum::operator()
    (const std::pair<std::string, Tristate> &elem) const
{
    if (elem.first == valueCpy)
        return true;
    return false;
}

void Component::pullValAndInit(const std::string &value,
  unsigned long allocSize)
{    
    std::unordered_set
    <std::pair<std::string, Tristate>, HashMyPair>::iterator it;

    valueCpy = value;
    it = std::find_if(pinValConv.begin(),
    pinValConv.end(), StrToEnum());
    if (it != pinValConv.end())
        this->setComponentInit(it->second, allocSize);
}

void Component::initInput(const std::string &value)
{
    this->pullValAndInit(value);
}

void Component::initOutput(const std::string &value)
{
    this->pullValAndInit(value);
}
