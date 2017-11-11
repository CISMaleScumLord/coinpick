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

#include <cstdlib>
#include <iostream>
#include "ArtificialDumbass.h"

using namespace std;

// Computer AI is basically a dumbo
// 1,2 or 3 coins left then grab all otherwise kind of random
void ArtificialDumbass::move(int *coinsLeft) 
{

    int coinsToRemove = 0;
    
    if (*coinsLeft <= 3) {
        coinsToRemove = *coinsLeft;
    } else {
        coinsToRemove = rand() % 3 + 1;
    }
    
    cout << "Computer takes " << coinsToRemove << " coins" << endl;
    *coinsLeft -= coinsToRemove;
    score += coinsToRemove;
}

void ArtificialDumbass::addPoints(int howMany) {
    score += howMany;
}


int ArtificialDumbass::getScore()
{
    return score;
}