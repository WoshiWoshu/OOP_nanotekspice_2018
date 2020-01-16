/*
** EPITECH PROJECT, 2019
** nanotekspice
** File description:
** ParserFileNts.hpp
*/

#pragma once

#include <sstream>
#include "Gate.hpp"

namespace link {
    using LinkVarT = struct LinkVarS;
    using CompPinT = struct CompPinS;

    struct LinkVarS
    {
        explicit LinkVarS();

        static bool checkLink;
        size_t pos;
        std::string token;
        const std::string limit;
        std::string cpyIt;
    };

    struct CompPinS
    {
        explicit CompPinS();

        char quote;
        short indx;
        std::pair<std::string, std::string> Elem[2];
    };

    template<typename T>
    T stringToNumber(const std::string &txt)
    {
        std::istringstream strStream(txt);
        T nb;

        return strStream >> nb ? nb : 0;
    }
}

extern std::unordered_map
<std::string, std::unique_ptr<nts::IComponent>> compoCollec;

extern void initReadF(char *fPath);
