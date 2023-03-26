// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

std::vector<std::string> drinks = {
        "Latte", "Cappuccino", "Espresso", "Hot chocolate", "Tea", "Raf"
};
std::vector<unsigned int> prices = { 4, 3, 2, 3, 2, 5 };


TEST(test, scenario1) {
    Automata automata(drinks, prices);

    EXPECT_EQ(Automata::State::Off, automata.getState());
}

TEST(test, scenario2) {
    Automata automata(drinks, prices);
    automata.on();

    EXPECT_EQ(Automata::State::Wait, automata.getState());
}

TEST(test, scenario3) {
    Automata automata(drinks, prices);
    automata.on();

    automata.coin(2);

    EXPECT_EQ(Automata::State::Accept, automata.getState());
}

TEST(test, scenario4) {
    Automata automata(drinks, prices);
    automata.on();

    automata.coin(2);
    automata.choice(1);

    EXPECT_EQ(Automata::State::Accept, automata.getState());
}

TEST(test, scenario5) {
    Automata automata(drinks, prices);
    automata.on();

    automata.coin(2);
    automata.choice(1);
    automata.coin(2);
    automata.choice(1);

    EXPECT_EQ(Automata::State::Wait, automata.getState());
}


TEST(test, scenario6) {
    Automata automata(drinks, prices);
    automata.on();

    automata.coin(4);
    automata.choice(1);

    EXPECT_EQ(Automata::State::Wait, automata.getState());
}

TEST(test, scenario7) {
    Automata automata(drinks, prices);
    automata.on();

    automata.coin(4);
    automata.cancel();

    EXPECT_EQ(Automata::State::Wait, automata.getState());
}
