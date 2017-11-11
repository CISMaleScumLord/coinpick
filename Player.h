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

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

/*
 * The way c++ handles classes is very strange. For starters, a class is split 
 * across two files. A header (.h) that contains the class definition and a
 * source file (.cpp) that contains the implementation. As far as I can tell,
 * this split is needed due to the order the compiler reads the files.
 * 
 * The header and source file do not need the same name but don't do that!
 */
class Player {
public:
    /* 
     * This is a constructor that initialises the score variable, apparently 
     * for simple initialisation this is better than coding the constructor in
     * the cpp file.
     */
    Player() : score(0) {}
    
    string getName();
    void setName();
    void addPoints(int howMany);
    
    /*
     * Normally, I wouldn't use a pointer in this situation, I'd just return an
     * int but as I am using this small project to practice c++ based on the 
     * JP beginners course, it suffers from a lot of over-engineering like this.
    */
    void move(int *coinsLeft);
    int getScore();

private:
    
    string name;
    int score;

};

#endif /* PLAYER_H */

