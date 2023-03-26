//
// Created by mSiotniHS on 19.03.2023.
// Copyright 2023 mSiotniHS
//

#include <vector>
#include <string>
#include <iostream>
#include "Automata.h"

void reportState(const Automata& automata);
std::string toString(const Automata::State& state);

int main() {
    std::vector<std::string> drinks = {
            "Latte", "Cappuccino", "Espresso", "Hot chocolate", "Tea", "Raf"
    };
    std::vector<unsigned int> prices = { 4, 3, 2, 3, 2, 5 };

    Automata automata(drinks, prices);
    reportState(automata);

    automata.on();
    reportState(automata);
    automata.getMenu();

    automata.coin(4);
    reportState(automata);

    automata.choice(3);
    reportState(automata);

    automata.off();

    return 0;
}

void reportState(const Automata& automata) {
    std::cout
        << "Current automata state: "
        << toString(automata.getState()) << std::endl;
}

std::string toString(const Automata::State& state) {
    switch (state) {
        case Automata::Off:    return "Off";
        case Automata::Wait:   return "Wait";
        case Automata::Cook:   return "Cook";
        case Automata::Check:  return "Check";
        case Automata::Accept: return "Accept";
        default:               return "Nothing";
    }
}
