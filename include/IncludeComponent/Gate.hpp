/*
** EPITECH PROJECT, 2019
** NanotekSpice
** File description:
** GateAnd.hpp
*/

#pragma once

#include "Component.hpp"

namespace ginfo {
    enum GateTypeE
    {
        INIT = -1,
        AND = 0,
        OR,
        NOR,
        XOR,
        NAND
    };

    using GateTypeT = enum GateTypeE;

    static const size_t GATE_SIZE = 5;
}

class Gate : public Component
{

using PtrGate = bool (Gate::*)(const bool &a, const bool &b) const;

public:
    explicit Gate();
    
    void setLink(std::size_t pin, nts::IComponent &other,
         size_t otherPin) override;
    
    static void setGateType(ginfo::GateTypeT gate);
    static ginfo::GateTypeT getGateType(void);
protected:
    using Component::dump;
    
    void gateProceed(size_t pinA, size_t pinB, ginfo::GateTypeT GateType);
private:
    std::array<PtrGate, ginfo::GATE_SIZE> _gateType;
    static ginfo::GateTypeT gateTyp;
    
    bool andGate(const bool &a, const bool &b) const;
    bool orGate(const bool &a, const bool &b) const;
    bool norGate(const bool &a, const bool &b) const;
    bool xorGate(const bool &a, const bool &b) const;
    bool nandGate(const bool &a, const bool &b) const;
};
