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
#include "Player.h"

using namespace std;

string Player::getName() 
{
    return name;
}

void Player::setName() 
{
    cout << "Player, please enter your name > " << flush;
    cin >> name;
}

void Player::move(int *coinsLeft) 
{
    char coinsToRemove = 0;

    do {
        cout << "Remove 1, 2 or 3 coins > " << flush;

        cin >> coinsToRemove;
        if (coinsToRemove < '1' || coinsToRemove > '3') {
            cout << "You can only remove 1, 2 or 3 coins from the pile." << endl;
        } else if ((coinsToRemove - '0') > *coinsLeft) {
            cout << "There are not enough coins in the pile" << endl;
        }

    } while ((coinsToRemove < '1' || coinsToRemove > '3') && (coinsToRemove - '0') > *coinsLeft);

    score = score + (coinsToRemove - '0');
    *coinsLeft -= (coinsToRemove - '0');
}

void Player::addPoints(int howMany) {
    score += howMany;
}

int Player::getScore()
{
    return score;
}
