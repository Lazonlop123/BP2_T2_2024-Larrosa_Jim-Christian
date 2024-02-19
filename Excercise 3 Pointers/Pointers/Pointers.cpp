#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Item
{
    string name;
    int gold;
};

Item* createRandomItem()
{
    Item* item = new Item;
    int randNum = rand() % 5;
    switch (randNum)
    {
    case 0:
        item->name = "Mithril Ore";
        item->gold = 100;
        break;
    case 1:
        item->name = "Sharp Talon";
        item->gold = 50;
        break;
    case 2:
        item->name = "Thick Leather";
        item->gold = 25;
        break;
    case 3:
        item->name = "Jellopy";
        item->gold = 5;
        break;
    case 4:
        item->name = "Cursed Stone";
        item->gold = 0;
        break;
    }
    return item;
}

void enterDungeon(int& playerGold)
{
    const int DUNGEON_FEE = 25;
    const int TARGET_GOLD = 500;
    int bonusMultiplier = 1;
    bool cursedStoneLooted = false;

    playerGold -= DUNGEON_FEE;

    while (playerGold >= DUNGEON_FEE && playerGold < TARGET_GOLD && !cursedStoneLooted)
    {
        Item* item = createRandomItem();
        playerGold += item->gold * bonusMultiplier;

        if (item->name == "Cursed Stone")
        {
            cursedStoneLooted = true;
            delete item;
            break;
        }

        cout << "You found a " << item->name << "! Gold earned: " << item->gold * bonusMultiplier << endl;
        delete item;

        char choice;
        cout << "Do you want to continue looting? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N')
            break;

        bonusMultiplier++;
    }

    if (cursedStoneLooted)
    {
        cout << "You encountered a Cursed Stone and lost all gold looted in this instance." << endl;
        playerGold = max(0, playerGold - playerGold % 100); 
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int playerGold = 50;

    while (playerGold >= 25 && playerGold < 500)
    {
        enterDungeon(playerGold);
        if (playerGold < 25)
        {
            cout << "Not enough gold to enter the dungeon. Game Over!" << endl;
            break;
        }
        else if (playerGold >= 500)
        {
            cout << "Congratulations! You reached the target gold and won the game!" << endl;
            break;
        }
    }

    return 0;
}
