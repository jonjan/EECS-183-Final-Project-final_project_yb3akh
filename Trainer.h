//
//  Trainer.h
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#ifndef __CreatureTrainer__Trainer__
#define __CreatureTrainer__Trainer__

#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Trainer {
public:
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns 'a' or 's#' given the situation.
     This is where the bulk of your code will go. The implementation
     of your AI goes here.
     */
    string makeMove(stringstream& situation);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Prints out the final situation
     */
    void finalSituation(stringstream& situation);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Splits a string into a vector of strings
     */
    vector<string> splitString(string inString, string splitOn=" ");
    
private:
    // vvvvvv Your changes to Trainer.h go between this line…
    
    
    int currentPokemon;
    int pokemon[4];
    int nameIndex[4];
    int baseAttack[4];
    int attackElement[4];
    int pokemonWeakness[4];
    int pokemonStrength[4];
    int pokemonMaxHealth[4];
    int pokemonLevel[4];
    int currentHealth[4];
    int damageDoneToTeam[4];
    
    int currentTurn = 0;
    char currentEnemy = 0;
    int currentEnemy2= 0;
    int currentEW = 0;
    int currentES = 0;
    int currentEMH = 0;
    int currentEAT = 0;
    int currentEL = 0;
    int currentEBA = 0;
    int currentEDD = 0;
    bool newEnemy = 0;
    int currentECH = 0;
    
    int turn;
    bool attack;
    int attackTime = 0;
    int collar = 20;
    
    int r1 = 0;
    int r2 = 0;
    int r3 = 0;
    int r4 = 0;
    
    
    
    // ^^^^^^ And this line. That's it!
    
};

#endif /* defined(__CreatureTrainer__Trainer__) */