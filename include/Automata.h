//
// Created by mSiotniHS on 19.03.2023.
//

#ifndef MOD_LAB03_COFFEE_AUTOMATA_H
#define MOD_LAB03_COFFEE_AUTOMATA_H

#include <string>
#include <vector>

class Automata {
public:
    enum State {
        Off,
        Wait,
        Accept,
        Check,
        Cook
    };

    Automata(std::vector<std::string> drinks, std::vector<unsigned int> prices);

    void on();
    void off();
    void coin(unsigned int coin);
    void getMenu() const;
    State getState() const;
    void choice(unsigned int drinkNo);
    void cancel();
private:
    State currentState;
    unsigned int cash;
    std::vector<std::string> drinks;
    std::vector<unsigned int> prices;
    unsigned int chosenDrinkIdx;
    void check();
    void cook();
    void finish();
};


#endif //MOD_LAB03_COFFEE_AUTOMATA_H
