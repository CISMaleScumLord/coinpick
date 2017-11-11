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
#include "ArtificialDumbass.h"
#include "CoinPick.h"

using namespace std;

int main(int argc, char** argv) 
{

    CoinPick game;
    game.introduce();

    ArtificialDumbass computer;
    Player human;
    human.setName();
    
    bool finished = false;
    do {
        game.state(&human, &computer);
        finished = game.turn(&human, &computer);
    } while (!finished);
    
    game.results(&human, &computer);
    
    return 0; //
}