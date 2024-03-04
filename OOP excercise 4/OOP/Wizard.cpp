#include "Wizard.h"
#include "Spell.h"
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

Wizard::Wizard(std::string name, int HP, int MP, int minDamage, int maxDamage)
    : name(name), HP(HP), MP(MP), minDamage(minDamage), maxDamage(maxDamage), spell(nullptr) {
    // Seed the random number generator
    srand(time(nullptr));
}

Wizard::~Wizard() {
    delete spell; // Delete the spell object
}

void Wizard::Attack(Wizard& target) {
    int damage = rand() % (maxDamage - minDamage + 1) + minDamage; // Random damage within range
    std::cout << name << " attacks " << target.GetName() << " for " << damage << " damage!" << std::endl;
    target.HP -= damage;
    GenerateMP(); // Generate MP after attack
}

void Wizard::CastSpell(Wizard& target) {
    if (Spell && MP >= Spell->mpCost()) {
        Spell->activate(*this, target);
        MP -= Spell->mpCost(); // Consume MP
    }
}

void Wizard::GenerateMP() {
    int generatedMP = rand() % 11 + 10; // Random MP between 10 and 20
    MP += generatedMP;
    std::cout << name << " generated " << generatedMP << " MP!" << std::endl;
}

bool Wizard::IsAlive() const {
    return HP > 0;
}

std::string Wizard::GetName() const {
    return name;
}

int Wizard::GetHP() const {
    return HP;
}

int Wizard::GetMP() const {
    return MP;
}

int Wizard::GetMinDamage() const {
    return minDamage;
}

int Wizard::GetMaxDamage() const {
    return maxDamage;
}
