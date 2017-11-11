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

#ifndef COMPUTER_H
#define COMPUTER_H

using namespace std;

/*
 * I saw the opportunity for the name and I took it!
 */
class ArtificialDumbass {
public:
    ArtificialDumbass() : score(0) {}
    
    void addPoints(int howMany);
    void move(int *coinsLeft);
    int getScore();
    
private:
    int score;
};

#endif /* COMPUTER_H */

