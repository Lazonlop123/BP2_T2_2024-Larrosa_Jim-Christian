#include "Spell.h"
#include "Wizard.h"
#include <iostream>

void Spell::activate(Wizard& caster, Wizard& target) {
    if (caster.GetMP() >= mpCost) 
    {
        int damage = rand() % (maxDamage - minDamage + 1) + minDamage;
        target.Attack(damage);
        caster.CastSpell(mpCost);
        std::cout << caster.GetName() << " casts " << name << " on " << target.GetName() << " dealing " << damage << " damage!\n";
    }
    else {
        std::cout << caster.GetName() << " doesn't have enough MP to cast " << name << "!\n";
    }
}
