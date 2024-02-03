#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> fillInventory() {
    vector<string> inventory;
    const string items[] = { "RedPotion", "Elixir", "EmptyBottle", "BluePotion" };

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < 10; ++i) {
      
        int randomIndex = rand() % (sizeof(items) / sizeof(items[0]));
        inventory.push_back(items[randomIndex]);
    }
    return inventory;
}

void printInventory(const vector<string>& inventory) {
    cout << "Inventory:\n";
    for (const auto& item : inventory) {
        cout << item << "\n";
    }
}

int countItemInstances(const vector<string>& inventory, const string& itemToCount) {
    int count = 0;
    for (const auto& item : inventory) {
        if (item == itemToCount) {
            count++;
        }
    }
    return count;
}

void removeItem(vector<string>& inventory, const string& itemToRemove) {
    
    inventory.erase(remove(inventory.begin(), inventory.end(), itemToRemove), inventory.end());
}
int main() {
    
    vector<string> Inventory = fillInventory();

    printInventory(Inventory);

    string itemToRemove = "RedPotion";
    removeItem(Inventory, itemToRemove);

    cout << "\nAfter removing " << itemToRemove << ":\n";
    printInventory(Inventory);

    return 0;
}
