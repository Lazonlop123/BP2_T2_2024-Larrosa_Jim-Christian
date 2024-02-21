#include "Node.h"
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

class NightWatch {
private:
    Node* head;

public:
    NightWatch() : head(nullptr) {}

    ~NightWatch() {
        if (head == nullptr)
            return;

        Node* current = head;
        do {
            Node* temp = current;
            current = current->next;
            delete temp;
        } while (current != head);
    }

    void addSoldier(const std::string& name) {
        Node* newNode = new Node;
        newNode->name = name;

        if (head == nullptr) {
            head = newNode;
            head->next = head; // Point to itself since it's the only node
            head->previous = head;
        } else {
            Node* last = head->previous; // Last node
            last->next = newNode;
            newNode->previous = last;
            newNode->next = head; // Point back to the head to make it circular
            head->previous = newNode;
        }
    }

    Node* eliminateSoldier(int steps) {
        if (head == nullptr) {
            std::cout << "No soldiers left.\n";
            return nullptr;
        }

        Node* current = head;
        for (int i = 1; i < steps; ++i) {
            current = current->next;
        }

        // Eliminate the soldier
        Node* eliminated = current;
        current->previous->next = current->next;
        current->next->previous = current->previous;
        if (current == head) {
            head = current->next; // Move head to the next soldier
        }
        std::cout << current->name << " was eliminated.\n";
        return current->next;
    }

    Node* getLastSoldier() {
        if (head == nullptr) {
            std::cout << "No soldiers left.\n";
            return nullptr;
        }

        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        return current;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    NightWatch nightWatch;
    nightWatch.addSoldier("Alliser");
    nightWatch.addSoldier("Janos");
    nightWatch.addSoldier("Othell");
    nightWatch.addSoldier("Sam");
    nightWatch.addSoldier("Snow");

    int remainingSoldiers = 5; // Initial number of soldiers
    int steps;

    // Play the game until there's only one soldier left
    while (remainingSoldiers > 1) {
        // Randomly select the number of steps
        steps = rand() % remainingSoldiers + 1;
        std::cout << "Passing the cloak " << steps << " times.\n";

        Node* nextSoldier = nightWatch.eliminateSoldier(steps);
        remainingSoldiers--;

        if (remainingSoldiers == 1) {
            Node* lastSoldier = nightWatch.getLastSoldier();
            std::cout << "The last soldier remaining is: " << lastSoldier->name << std::endl;
            std::cout << lastSoldier->name << " will go to seek for reinforcements.\n";
            break;
        }
    }

    return 0;
}
