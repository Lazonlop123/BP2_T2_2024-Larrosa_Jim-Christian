#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Card { CIVILIAN, EMPEROR, SLAVE };

void playRound(vector<Card>& playerHand, int& mmLeft, int& moneyEarned, int round) {
    if (playerHand.empty()) {
        cerr << "Error: Player's hand is empty!" << endl;
        return;
    }

    
    Card playerCard = playerHand.back(); 
    playerHand.pop_back();

    
    Card opponentCard = static_cast<Card>(rand() % 3);

  
    if (playerCard == EMPEROR) {
        if (opponentCard == CIVILIAN) {
            
            moneyEarned += 100000; 
        }
        else if (opponentCard == SLAVE) {
            mmLeft -= 10; 
        }
    }
    else if (playerCard == SLAVE) {
        if (opponentCard == EMPEROR) {
            
            moneyEarned += 500000; 
        }
        else if (opponentCard == CIVILIAN) {
           
            mmLeft -= 10; 
        }
    }

    cout << "Round " << round << ": Player's money earned = " << moneyEarned << " yen, mm left = " << mmLeft << endl;
}

bool shouldEndGame(int round, int mmLeft, int moneyEarned) {
   
    return (round == 12 && mmLeft > 0) || mmLeft <= 0 || moneyEarned >= 20000000;
}

int main() {
    srand(time(0)); 

    vector<Card> playerHand(5, CIVILIAN);
    
    if (rand() % 2 == 0) {
        playerHand.push_back(EMPEROR); 
    }
    else {
        playerHand.push_back(SLAVE); 
    }

    int round = 1; 
    int mmLeft = 30; 
    int moneyEarned = 0; 

    
    while (!shouldEndGame(round, mmLeft, moneyEarned)) {
        playRound(playerHand, mmLeft, moneyEarned, round);
        round++;
    }

 
    if (round == 12 && mmLeft > 0) {
        if (moneyEarned >= 20000000) {
            cout << "Good ending: Player wins 20 million yen without piercing their eardrum." << endl;
        }
        else {
            cout << "Meh ending: Player didn't reach 20 million yen but their eardrum is safe." << endl;
        }
    }
    else {
        cout << "Bad ending: Player's eardrum is pierced or they didn't reach 20 million yen." << endl;
    }

    return 0;
}
