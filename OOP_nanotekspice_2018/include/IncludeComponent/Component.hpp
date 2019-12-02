/*
** EPITECH PROJECT, 2019
** NanotekSpice
** File description:
** ComponentInput.hpp
*/

#pragma once

#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <memory>
#include "IComponent.hpp"

#define callMemberFunct(object, ptrToMember) ((object).*(ptrToMember))

using namespace nts;

struct HashMyPair
{
    template<class TA, class TB>
    std::size_t operator()(const std::pair<TA,TB> &elem) const {
        auto h1 = std::hash<TA>{}(elem.first);
        auto h2 = std::hash<TB>{}(elem.second);
        return h1 ^ h2;
    }
};

static const unsigned int GATE_SIZE = 14;

class Component : public IComponent
{

typedef void (Component::*PtrInit)(const std::string &value);

public:
    explicit Component();
    virtual ~Component() {};

    std::unique_ptr<IComponent>
         createComponent(const std::string &type, const std::string &value) final;
    nts::Tristate compute(std::size_t pin = 1) final;
    void setLink(std::size_t pin,
         nts::IComponent &other, size_t otherPin) override;
    void dump() const final;
protected:    
    void setComponentPin(size_t pin, nts::Tristate state) final;
    void setComponentPtr(size_t pin, nts::IComponent &component) final;
    std::unique_ptr<std::pair<Tristate, IComponent*>[]> _component;
private:
    std::unordered_map
         <std::string, PtrInit> _componentType;
    void setComponentInit(const Tristate &pinVal = FALSE,
        unsigned long newVal = 1);
    void pullValAndInit(const std::string &value,
        unsigned long allocSize = 1);
private:
    void initInput(const std::string &value);
    void initOutput(const std::string &value);
    void initGate(const std::string &value);
};

class StrToEnum
{
public:
    bool operator()
    (const std::pair<std::string, Tristate> &elem) const;
};
