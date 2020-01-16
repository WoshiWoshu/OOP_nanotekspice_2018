/*
** EPITECH PROJECT, 2019
** nanotekspice
** File description:
** GateAnd.cpp
*/

#include "Gate.hpp"

ginfo::GateTypeT Gate::gateTyp = ginfo::INIT;

void Gate::setGateType(ginfo::GateTypeT gate)
{
    gateTyp = gate;
}

ginfo::GateTypeT Gate::getGateType(void)
{
    return gateTyp;
}

Gate::Gate() : Component()
{
    _gateType[ginfo::AND] = &Gate::andGate;
    _gateType[ginfo::OR] = &Gate::orGate;
    _gateType[ginfo::NOR] = &Gate::norGate;
    _gateType[ginfo::XOR] = &Gate::xorGate;
    _gateType[ginfo::NAND] = &Gate::nandGate;
}

void Gate::setLink(std::size_t pin, nts::IComponent &other,
     size_t otherPin)
{
    (compute(pin) == UNDEFINED
     && pin == 3) ? gateProceed(1, 2, this->getGateType()) : void();
    (compute(pin) == UNDEFINED
    && pin == 4) ? gateProceed(5, 6, this->getGateType()) : void();
    (compute(pin) == UNDEFINED
    && pin == 10) ? gateProceed(8, 9, this->getGateType()) : void();
    (compute(pin) == UNDEFINED
    && pin == 11) ? gateProceed(12, 13, this->getGateType()) : void();
    this->Component::setLink(pin, other, otherPin);
}

void Gate::gateProceed(size_t pinA, size_t pinB, ginfo::GateTypeT gateType)
{
    bool pinS = callMemberFunct(*this, _gateType[gateType])
    (this->compute(pinA), this->compute(pinB));
    (pinA == 1 && pinB == 2) ? _component[2].first = (Tristate)pinS : 0;
    (pinA == 5 && pinB == 6) ? _component[3].first = (Tristate)pinS : 0;
    (pinA == 8 && pinB == 9) ? _component[9].first = (Tristate)pinS : 0;
    (pinA == 12 && pinB == 13) ? _component[10].first = (Tristate)pinS : 0;
}
