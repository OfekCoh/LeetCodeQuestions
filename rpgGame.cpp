// not leetcode but practice opp

#include <iostream>
#include <string>
using namespace std;

class Character {
    string name;
    int hp;
    int attackPower;

    public:
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

class Warrior: public Character {
    public:
    Warrior(string name, int hp, int attackPower): Character(name,hp,attackPower) {}

    // methods
    void displayStats() {
        cout << "Name: " << getName() << endl;
        cout << "HP: " << getHp() << endl;
        cout << "Attack Power: " << getAttackPower() << endl;
    }
};

class Mage: public Character {
    int mana;

    public:
    Mage(string name, int hp, int attackPower, int mana): Character(name,hp,attackPower), mana(mana) {}

    //getters 
    int getMana() {
        return mana;
    }

    // setters
    void setMana(int mana) {
        this->mana=mana;
    }

    // methods
    void displayStats() {
        cout << "Name: " << getName() << endl;
        cout << "HP: " << getHp() << endl;
        cout << "Attack Power: " << getAttackPower() << endl;
        cout << "Mana: " << mana << endl;
    }
};

int main() {
    Warrior* w= new Warrior("Slik", 100, 55);
    Mage* m= new Mage("Mage", 100, 20, 60);

    while(true) {
        w->attack(*m);
        m->displayStats();

        if(m->getHp()>0) {
            m->attack(*w);
            w->displayStats();

            if(w->getHp()<=0) {
                cout << "Winner is: " << m->getName() << endl;
                break;
            }
        }
        else {
            cout << "Winner is: " << w->getName() << endl;
            break;
        }
    }

    // free memory
    delete(w);
    delete(m);
    
    return 0;
}

