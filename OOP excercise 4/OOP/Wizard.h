#pragma once
#include <iostream>
#include <string>
using namespace std;

class Spell; // Forward declaration

class Wizard 
{
public:
    string name;
    int HP;
    int MP;
    int minDamage;
    int maxDamage;

    ~Wizard(); // Destructor to ensure proper memory management
    Spell* spell; // Composition with Spell class
    void Attack(Wizard& target);
    void CastSpell(Wizard& target);
    void GenerateMP();
    bool IsAlive() const;
    string GetName() const;
    int GetHP() const;
    int GetMP() const;
    int GetMinDamage() const;
    int GetMaxDamage() const;
};