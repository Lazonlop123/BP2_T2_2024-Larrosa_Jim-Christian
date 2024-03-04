#pragma once
#include <string>
#include <cstdlib>
using namespace std;

class Wizard; // Forward declaration of Wizard class

class Spell 
{
public:
    string name;
    int minDamage;
    int maxDamage;
    int mpCost;

    void activate(Wizard& caster, Wizard& target);
};