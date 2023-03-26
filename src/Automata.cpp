//
// Created by mSiotniHS on 19.03.2023.
// Copyright 2023 mSiotniHS
//

#include <iostream>
#include <algorithm>
#include "../include/Automata.h"

Automata::Automata(
        std::vector<std::string> drinks,
        std::vector<unsigned int> prices
) {
    this->drinks = drinks;
    this->prices = prices;

    currentState = Off;
    cash = 0;
    chosenDrinkIdx = -1;
}

void Automata::on() {
    if (currentState != Off) return;

    currentState = Wait;
}

void Automata::off() {
    if (currentState != Wait) return;

    currentState = Off;
}

void Automata::coin(unsigned int coin) {
    if (currentState != Wait && currentState != Accept) return;

    currentState = Accept;
    cash += coin;
}

void Automata::choice(unsigned int drinkNo) {
    if (currentState != Accept) return;

    if (drinkNo < 1 || drinkNo > drinks.size()) {
        throw std::invalid_argument("Received drinkNo of wrong value");
    }

    chosenDrinkIdx = drinkNo - 1;
    currentState = Check;

    check();
}

void Automata::check() {
    if (currentState != Check) return;

    if (cash < prices[chosenDrinkIdx]) {
        currentState = Accept;
    } else {
        cash = 0;
        cook();
    }
}

void Automata::cook() {
    if (currentState != Check) return;

    currentState = Cook;

    finish();
}

void Automata::finish() {
    if (currentState != Cook) return;

    currentState = Wait;
}

void Automata::cancel() {
    if (currentState != Accept && currentState != Check) return;

    currentState = Wait;
    cash = 0;
    chosenDrinkIdx = -1;
}

Automata::State Automata::getState() const {
    return currentState;
}

void Automata::getMenu() const {
    std::cout << "    Coffee Machine Menu\n";
    for (size_t i = 0; i < drinks.size(); i++) {
        std::cout
            << "(" << i+1 << ") "
            << drinks[i]
            << " [$" << prices[i] << "]\n";
    }
}
