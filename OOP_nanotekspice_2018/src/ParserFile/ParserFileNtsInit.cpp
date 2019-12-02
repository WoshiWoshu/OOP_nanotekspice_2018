/*
** EPITECH PROJECT, 2019
** nanotekspice
** File description:
** ParserFileInit.cpp
*/

#include "ParserFileNts.hpp"

std::unordered_map
<std::string, std::unique_ptr<IComponent>> compoCollec(0);

link::LinkVarS::LinkVarS() : pos(0), token(""), limit(":"), cpyIt("")
{}

link::CompPinS::CompPinS() : quote(0), indx(0), Elem({{"",""}, {"", ""}})
{}
