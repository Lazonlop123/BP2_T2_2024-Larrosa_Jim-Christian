#include <iostream>
#include <ctime>

using namespace std;

void rollTwoDice(int& die1, int& die2) {
    die1 = rand() % 6 + 1; 
    die2 = rand() % 6 + 1; 
}

void evaluateOutcome(int aiRoll, int playerRoll, int playerBet, int& playerGold) {
    if (playerRoll > aiRoll) {
        cout << "You win! You gained " << playerBet << " gold." << endl;
        playerGold += playerBet;
    }
    else if (playerRoll == aiRoll) {
        cout << "It's a draw. No gold gained or lost." << endl;
    }
    else {
        cout << "You lose! You lost " << playerBet << " gold." << endl;
        playerGold -= playerBet;
    }
}

void playRound(int& playerGold) {
    int playerBet;

    do {
        cout << "Current gold: " << playerGold << endl;
        cout << "Enter your bet (0 to quit): ";
        cin >> playerBet;

        if (playerBet == 0) {
            cout << "Thanks for playing! Exiting..." << endl;
            exit(0);
        }

    } while (playerBet <= 0 || playerBet > playerGold);

    playerGold -= playerBet;

    int aiDie1, aiDie2;
    int playerDie1, playerDie2;

    rollTwoDice(aiDie1, aiDie2);
    rollTwoDice(playerDie1, playerDie2);

    cout << "AI rolled: " << aiDie1 << " and " << aiDie2 << " (Total: " << aiDie1 + aiDie2 << ")" << endl;
    cout << "Player rolled: " << playerDie1 << " and " << playerDie2 << " (Total: " << playerDie1 + playerDie2 << ")" << endl;

    evaluateOutcome(aiDie1 + aiDie2, playerDie1 + playerDie2, playerBet, playerGold);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int playerGold = 1000;

    while (playerGold > 0) {
        playRound(playerGold);
    }

    cout << "You're out of gold. Game over!" << endl;

    return 0;
}