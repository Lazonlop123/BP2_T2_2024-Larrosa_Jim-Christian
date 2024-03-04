#include <iostream>
#include "Wizard.h"
#include "Spell.h"

using namespace std;

int main()
{
    Wizard* wizard = new Wizard();
    wizard->HP = 250;
    wizard->MP = 0;
    wizard->minDamage = 10;
    wizard->maxDamage = 15;

    //Spell Class
    Spell* spell = new Spell();
    spell->minDamage = 40;
    spell->maxDamage = 60;
    spell->mpCost = 50;
}
       