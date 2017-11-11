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

#ifndef GAME_H
#define GAME_H

class CoinPick {
public:
    CoinPick();
    
    void introduce();
    
    /*
     * Another bit of weirdness with cpp classes. If you don't pass a pointer,
     * it passes a copy of the object so changes made in the method do not happen
     * in the caller. Very unintuitive when you are used to any other programming
     * language.
     */
    bool turn(Player *human, ArtificialDumbass *computer);
    
    /*
     * Even though I don't change the objects data in these methods, I'm passing
     * a pointer to make it familiar. Maybe that's bad practice in C++ ?
     */
    void results(Player *human, ArtificialDumbass *computer);
    void state(Player *human, ArtificialDumbass *computer);
    
private:
    int coinsInPile;
    bool playersTurn;

    void doesPlayerGoFirst();
};

#endif /* GAME_H */

