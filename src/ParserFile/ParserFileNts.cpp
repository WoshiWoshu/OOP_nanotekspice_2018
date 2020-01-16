/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** ParserFile.cpp
*/

#include <iostream>
#include <iterator>
#include <fstream>
#include "ParserFileNts.hpp"

bool link::LinkVarT::checkLink = false;

static void readNcreategate(std::istream_iterator<std::string> &itP)
{    
    if (*itP == "4081" || *itP == "4071"
    || *itP == "4001" || *itP == "4030" || *itP == "4011") {
        (*itP == "4081") ? Gate::setGateType(ginfo::AND) : void();
        (*itP == "4071") ? Gate::setGateType(ginfo::OR) : (void)0;
        (*itP == "4001") ? Gate::setGateType(ginfo::NOR) : void();
        (*itP == "4030") ? Gate::setGateType(ginfo::XOR) : (void)0;
        (*itP == "4011") ? Gate::setGateType(ginfo::NAND) : void();
        compoCollec[*(++itP)] = std::make_unique<Gate>();
        compoCollec[*itP]->createComponent("gate", "");
    }
}

//change the parameter of this function eventually
static void readNCreateComp(std::istream_iterator<std::string> &itP)
{
    if (itP->compare("input") == 0) {
        compoCollec[*(++itP)] = std::make_unique<Component>();
        compoCollec[*itP]->createComponent("input", "0");
    }
    if (itP->compare("true") == 0) {
        compoCollec[*(++itP)] = std::make_unique<Component>();
        compoCollec[*itP]->createComponent("input", "1");
    }
    if (itP->compare("false") == 0) {
        compoCollec[*(++itP)] = std::make_unique<Component>();
        compoCollec[*itP]->createComponent("input", "0");
    }
    if (*itP == "output") {
        compoCollec[*(++itP)] = std::make_unique<Component>();
        compoCollec[*itP]->createComponent("output", "-1");
    }
    readNcreategate(itP);
}

static void readNLinkComp(std::istream_iterator<std::string> &itP,
                          std::ifstream &streamF,
                          link::LinkVarT &lVar, link::CompPinT &coPin)
{
    (*itP == ".links:") ? link::LinkVarT::checkLink = true : 0;
    (*itP == ".links:") ? *(itP++) : "";
    if (link::LinkVarT::checkLink) {
        lVar.cpyIt.assign(*itP);
        while ((lVar.pos = lVar.cpyIt.find(lVar.limit)) != std::string::npos) {
            lVar.token = lVar.cpyIt.substr(0, lVar.pos);
            lVar.cpyIt.erase(0, lVar.pos + lVar.limit.length());
        }
        coPin.Elem[coPin.indx] = make_pair(lVar.token, lVar.cpyIt);
        coPin.indx++;
        streamF.get(coPin.quote);
        if (coPin.quote == '\n') {
            //std::cout << coPin.Elem[1].first << std::endl;
            compoCollec[coPin.Elem[0].first]->setLink
            (link::stringToNumber<size_t>(coPin.Elem[0].second),
            *compoCollec[coPin.Elem[1].first],
            link::stringToNumber<size_t>(coPin.Elem[1].second));
            coPin.indx = 0;
        }
    }
}

//Driver function
void initReadF(char *fPath)
{
    std::ifstream stream;
    std::istream_iterator<std::string> it;
    link::LinkVarT v;
    link::CompPinT cP;

    stream.open(fPath);
    it = stream;
    if (stream)
        for (; it != std::istream_iterator<std::string>(); ++it) {
            readNCreateComp(it);
            readNLinkComp(it, stream, v, cP);
        }
    else
        std::cout << "file non-existant or corrupted\n";
    stream.close();
}
