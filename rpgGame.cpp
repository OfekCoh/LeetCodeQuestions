// not leetcode but practice opp

#include <iostream>
using namespace std;

class Character {
    string name;
    int hp;
    int attackPower;

    public:
    // constructor
    Character(string name, int hp, int attackPower): name(name), hp(hp), attackPower(attackPower) {};

    // getters
    string getName() {
        return name;
    }

    int getHp() {
        return hp;
    }

    int getAttackPower() {
        return attackPower;
    }

    // setters
    void setName(string name) {
        this->name=name;
    }

    void setHp(int hp) {
        this->hp=hp;
    }

    void setAttackPower(int attackPower) {
        this->attackPower=attackPower;
    }

    // methods
    void attack(Character& target) {
        target.takeDamage(attackPower);
    }

    void takeDamage(int amount) {
        hp-=amount;
        if(hp<0) hp=0; // can call destructor here if dead
    }

    virtual void displayStats()=0; // class is abstract
};

