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
        int targetHp= target.getHp();
        targetHp-=attackPower;
        if (targetHp<=0) targetHp=0;
        cout << name << " hit " << target.getName() << " for " << attackPower << " damage. HP left: " << targetHp << endl; 
    }

    

};

