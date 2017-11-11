/*
 *  Copyright 2017 CISMaleScumLord
 * 
 *  This file is part of Coin Pick.
 *
 *  Coin Pick is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Coin Pick is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Coin Pick.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include <iostream>
#include <cstdlib>

#include "Player.h"
#include "ArtificialDumbass.h"
#include "CoinPick.h"

using namespace std;

CoinPick::CoinPick() {
    srand(time(0));
    this->coinsInPile = rand() % 10 + 10;
    this->doesPlayerGoFirst();
}

void CoinPick::introduce() {
    cout << "*** Coin Game ***" << endl;
    cout << "Player and computer takes turns to pick 1, 2 or 3 coins from a pile." << flush;
    cout << "The object of the game is to leave your opponent with no or one coins" << endl << endl;
}

void CoinPick::state(Player *human, ArtificialDumbass *computer) {
    cout << endl << "There are " << coinsInPile << " coins in the pile" << endl;
    cout << "The scores are: computer: " << computer->getScore() << ", " << human->getName() << " " << human->getScore() << endl;
    if (playersTurn) {
        cout << human->getName() << " to move" << endl;
    } else {
        cout << "Computer to move" << endl;
    }
}

bool CoinPick::turn(Player *human, ArtificialDumbass *computer) 
{
    if (coinsInPile > 1) {
        if (playersTurn) {
            /* 
             * & is the address of operator. It is used here to pass a "pointer to" 
             */
            human->move(&coinsInPile);
        } else {
            computer->move(&coinsInPile);
        }
    }

    if (coinsInPile <= 1) {
        if (playersTurn) {
            human->addPoints(10);
        } else {
            computer->addPoints(10);
        }
        return true;
    }
    
    playersTurn = !playersTurn;
    return false;
}

void CoinPick::results(Player *human, ArtificialDumbass *computer) 
{
    cout << "Final score" << endl;
    cout << human->getName() << ": " << human->getScore() << endl;
    cout << "Computer: " << computer->getScore() << endl;
    
    if (human->getScore() > computer->getScore()) {
        cout << "You beat the computer! Well done " << human->getName() << endl;
    } else if (human->getScore() < computer->getScore()) {
        cout << "The computer beat you! Why not try again " << human->getName() << "?" << endl;
    } else {
        cout << "It was a tie, " << human->getName() << " couldn't even beat an artificial dumbass!" << endl;
    }
}

/* End of public interface */

void CoinPick::doesPlayerGoFirst() 
{
    int percent = rand() % 99 + 1;
    playersTurn = (percent > 50);
}
