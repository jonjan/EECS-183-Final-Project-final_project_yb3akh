//
//  Trainer.cpp
//  CreatureTrainer
//
//  You may NOT #include any .h files we provide you (Battle, Creature, CreatureType,
//  EECSRandom, Party, PrintHelper)
//  other than the ones name "ClassX.h" and "Trainer.h"
//  You may #include other <> libraries if you wish to
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Trainer.h"
#include "Class1.h"
#include "Class2.h"
#include "Class3.h"
#include "Class4.h"
#include "Class5.h"
#include "CreatureType.h"


string Trainer::makeMove(stringstream& situation) {
    turn++;
    if(turn ==1){
        attack = false;
    }
    
    
    
    string situationString = situation.str();
    
    // Here's how to use the stringSplit function
    vector<string> lines = splitString(situationString, "\n");
    
    // Output for human player
    // Instead of doing this, you will need to replace the code of Trainer
    // to parse the input situation and create a proper response,
    // (like "a" for attack or "s3" to swap to the creature in slot 3).
    cout << situationString;
    
    
    int pipeLine = -1;
    for (int i=0; i<lines.size(); i++) {
        string line = lines[i];
        char c = line[0];
        if (c == '|') {
            pipeLine = i;
        }
    }
    
    vector<string> creatureHealthBits = splitString(lines[pipeLine], "|");
    
    //Sets name, current health, and max health for Pokemon
    for (int i=1; i<creatureHealthBits.size()-1; i++) {
        stringstream ss;
        ss << creatureHealthBits[i];
        string name;
        ss >> name;
        pokemon[i-1] = name[0];
        if (name[0] == '*'){
            pokemon[i-1] = name[1];
            currentPokemon = i-1;
        }
        int health;
        ss >> health;
        currentHealth[i-1] = health;
    }
    
    for (int i = 0; i < 4; i++){
        nameIndex[i] = pokemon[i] - 'A';
    }
    
    for (int i = 0; i < 4; i++){
        if (pokemonLevel[i] != 0){
            baseAttack[i] = CreatureType::TYPES[nameIndex[i]].getAttackPerLevel();
        }
        else {
            baseAttack[i] = CreatureType::TYPES[nameIndex[i]].getAttackBase();
        }
    }
    
    
    for (int i = 0; i < 4; i++){
        baseAttack[i] = CreatureType::TYPES[nameIndex[i]].getAttackBase();
    }
    for (int i = 0; i < 4; i++){
        attackElement[i] = CreatureType::TYPES[nameIndex[i]].getElementalAttackType();
    }
    for (int i = 0; i < 4; i++){
        pokemonWeakness[i] = CreatureType::TYPES[nameIndex[i]].getElementalWeakness();
    }
    for (int i = 0; i < 4; i++){
        pokemonStrength[i] = CreatureType::TYPES[nameIndex[i]].getElementalStrength();
    }
    for (int i = 0; i < 4; i++){
        pokemonMaxHealth[i] = CreatureType::TYPES[nameIndex[i]].getHealthMaxBase();
    }
    
    
    
    
    
    
    //Gets enemy name
    
    int pipeLine2 = -1;
    for (int i=0; i<lines.size(); i++) {
        string line = lines[i];
        char enemyLine = line[0];
        if (enemyLine == 'I') {
            if (line[1] == 't'){
                if (line[2] == '\''){
                    pipeLine2 = i;
                }
            }
        }
    }
    
    string realEnemy;
    
    if (pipeLine2 >0){
        vector<string> enemyHealthBits = splitString(lines[pipeLine2], "It's an enemy ");
        for (int i=0; i<enemyHealthBits.size(); i++) {
            string enemy;
            stringstream ss;
            ss << enemyHealthBits[i];
            ss >> enemy >> enemy >> enemy;
            ss >> enemy;
            realEnemy = enemy;
        }
        realEnemy.erase(realEnemy.length() - 1);
        currentEnemy = realEnemy[0];
        currentEnemy2 =currentEnemy - 'A';
    }
    
    if (pipeLine2 >0){
        vector<string> enemyHealthBits = splitString(lines[pipeLine2], "It's an enemy ");
        for (int i=0; i<enemyHealthBits.size(); i++) {
            string enemy;
            stringstream ss;
            ss << enemyHealthBits[i];
            ss >> enemy >> enemy >> enemy;
            ss >> enemy;
            realEnemy = enemy;
        }
        realEnemy.erase(realEnemy.length());
        currentEL = int(realEnemy[realEnemy.length()-2])-48;
        
    }
    
    if(currentEL != 0){
        currentEMH = CreatureType::TYPES[currentEnemy2].getHealthMaxPerLevel() + CreatureType::TYPES[currentEnemy2].getHealthMaxBase();
        //cout << endl << " max health" << currentEMH << endl;
    } else {
        currentEMH = CreatureType::TYPES[currentEnemy2].getHealthMaxBase();
    }
    if(pipeLine2 >0){
        currentECH = currentEMH;
    }
    
    
    currentEAT = CreatureType::TYPES[currentEnemy2].getElementalAttackType();
    currentES = CreatureType::TYPES[currentEnemy2].getElementalStrength();
    currentEW = CreatureType::TYPES[currentEnemy2].getElementalWeakness();
    
    if(currentEL != 0){
        currentEBA = CreatureType::TYPES[currentEnemy2].getAttackPerLevel() + CreatureType::TYPES[currentEnemy2].getAttackBase();
    } else {
        currentEBA = CreatureType::TYPES[currentEnemy2].getAttackBase();
    }
    
    
    int pipeLine8 = -1;
    for (int i=0; i<lines.size(); i++) {
        string line = lines[i];
        char enemyLine = line[0];
        if (enemyLine == '!') {
            if (line[1] == ' '){
                if (line[2] == 'P'){
                    pipeLine8 = i;
                }
            }
        }
    }
    
    string potions;
    int realPotion = 0;
    string defBst;
    int realDef = 0;
    string atkbst;
    int realAtk = 0;
    string revive;
    int realRevive = 0;
    
    if (pipeLine8 >0){
        vector<string> enemyHealthBits = splitString(lines[pipeLine8], "! Potion(po): ");
        for (int i=0; i<enemyHealthBits.size(); i++) {
            string enemy;
            stringstream ss;
            ss << enemyHealthBits[i];
            ss >> enemy;
            ss >> enemy;
            potions = enemy;
            ss >> enemy;
            ss >> enemy;
            defBst = enemy;
            ss >> enemy;
            ss >> enemy;
            atkbst = enemy;
            ss >> enemy;
            ss >> enemy;
            revive = enemy;
        }
        
        realPotion = int(potions[potions.length()-1])-48;
        //cout << endl << realPotion << endl;
        realDef = int(defBst[defBst.length()-1])-48;
        //cout << endl << realDef << endl;
        realAtk = int(atkbst[atkbst.length()-1])-48;
        realRevive = int(revive[revive.length()-1])-48;
    }
    
    
    
    for(int i = 0; i<4;i++){
        if(pokemonStrength[i] == currentEAT){
            damageDoneToTeam[i] = currentEBA/2;
        }
        else if(pokemonWeakness[i] == currentEAT){
            damageDoneToTeam[i] = currentEBA*2;
        }
        else{
            damageDoneToTeam[i] = currentEBA;
        }
    }
    
    //Gets current position
    //int currentPokemon = 0;
    for (int i = 0; i < 4; i++){
        if (pokemon[i] == '*'){
            currentPokemon = i;
        }
    }
    
    if(pokemonWeakness[currentPokemon] == currentEAT){
        currentEDD = currentEBA*2;
    }else{
        currentEDD = currentEBA;
    }
    if(pokemonStrength[currentPokemon] == currentEAT){
        currentEDD = currentEBA/2;
    }else{
        currentEDD = currentEBA;
    }
    for(int i = 0; i < 4; i++){
        if (currentEW == attackElement[i]){
            baseAttack[i] *= 2;
        }
        if (currentES == attackElement[i]){
            baseAttack[i] /= 2;
        }
    }
    
    //returns rest
    int pipeLine6 = -1;
    for (int i=0; i<lines.size(); i++) {
        string line = lines[i];
        char enemyLine2 = line[0];
        if (enemyLine2 == '(') {
            if (line[1] == 's'){
                if (line[2] == '#'){
                    pipeLine6 = 1;
                }
            }
        }
    }
    if (pipeLine6 >0){
        
        for (int i = 0; i< 4;i++){
            if (currentHealth[i] == 0 && collar > 0){
                if (i ==0){
                    collar--;
                    return "co1";
                }
                if (i==1){
                    collar--;
                    return "co2";
                }
                if (i == 2){
                    collar--;
                    return "co3";
                }
                if (i == 3){
                    collar--;
                    return "co4";
                }
            }
        }

        
        if (currentHealth[currentPokemon] > 0){
            if(realRevive != 0){
                for(int i = 0; i < 4; i++){
                    if(currentHealth[i] == 0){
                        if(i==0){
                            return "re1";
                        }
                        if(i==1){
                            return "re2";
                        }
                        if(i==2){
                            return "re3";
                        }
                        if(i==3){
                            return "re4";
                        }
                    }
                }
            }
            else if(realPotion != 0 && currentHealth[currentPokemon] <= pokemonMaxHealth[currentPokemon]/2){
                for(int i = 0; i < 4; i++){
                    if(currentPokemon == 0){
                        return "po1";
                    }
                    if(currentPokemon == 1){
                        return "po2";
                    }
                    if(currentPokemon == 2){
                        return "po3";
                    }
                    if(currentPokemon == 3){
                        return "po4";
                    }
                }
            }
        }
        
        
        for(int i =0; i<4; i++){
            if(i == 0){
                if(currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[1]/pokemonMaxHealth[1] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[2]/pokemonMaxHealth[2] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[3]/pokemonMaxHealth[3]){
                    if(currentPokemon != 0){
                        attack = true;
                        return "s1";
                    }
                }
            }else if(i == 1){
                if(currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[0]/pokemonMaxHealth[0] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[2]/pokemonMaxHealth[2] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[3]/pokemonMaxHealth[3]){
                    if(currentPokemon != 1){
                        attack = true;
                        return "s2";
                    }
                }
            }else if(i == 2){
                if(currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[1]/pokemonMaxHealth[1] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[0]/pokemonMaxHealth[0] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[3]/pokemonMaxHealth[3]){
                    if(currentPokemon != 2){
                        attack = true;
                        return "s3";
                    }
                }
            }else if(i == 3){
                if(currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[1]/pokemonMaxHealth[1] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[2]/pokemonMaxHealth[2] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[0]/pokemonMaxHealth[0]){
                    if(currentPokemon != 3){
                        attack = true;
                        return "s4";
                    }
                }
            }
        }
        
        
        /*if (currentEMH > currentHealth[0] && currentEMH > currentHealth[1] && currentEMH > currentHealth[2] && currentEMH > currentHealth[3] && collar > 0){
         int lowestLevelPokemon = 0;
         for (int i = 1; i < 4; i++){
         if (pokemonLevel[lowestLevelPokemon] > pokemonLevel[i]){
         lowestLevelPokemon = i;
         }
         }
         if (lowestLevelPokemon == 0){
         collar--;
         return "co1";
         }
         else if (lowestLevelPokemon == 1){
         collar--;
         return "co2";
         }
         else if (lowestLevelPokemon == 2){
         collar--;
         return "co3";
         }
         else if (lowestLevelPokemon == 3){
         collar--;
         return "co4";
         }
         }*/
        if (currentEL > pokemonLevel[0] && currentEL > pokemonLevel[1] && currentEL > pokemonLevel[2] && currentEL > pokemonLevel[3] && collar > 0){
            int lowestLevelPokemon = 0;
            for (int i = 1; i < 4; i++){
                if (pokemonLevel[lowestLevelPokemon] > pokemonLevel[i]){
                    lowestLevelPokemon = i;
                }
            }
            if (lowestLevelPokemon == 0){
                collar--;
                return "co1";
            }
            else if (lowestLevelPokemon == 1){
                collar--;
                return "co2";
            }
            else if (lowestLevelPokemon == 2){
                collar--;
                return "co3";
            }
            else if (lowestLevelPokemon == 3){
                collar--;
                return "co4";
            }
        }
         /*for (int i = 0; i < 4; i++) {
            if (currentEMH > pokemonMaxHealth[i]) {
                if (i == 0) {
                    return "co1";
                }
                if (i == 1) {
                    return "co2";
                }
                if (i == 2) {
                    return "co3";
                }
                if (i == 3) {
                    return "co4";
                }
               
            }
        }*/
        return "r";
    }
    
    if(realRevive > 0){
        for(int i = 0;i < 4; i++){
            if(currentHealth[i] ==0){
                if(i==0){
                    return "re1";
                }
                if(i==1){
                    return "re2";
                }
                if(i==2){
                    return "re3";
                }
                if(i==3){
                    return "re4";
                }
            }
        }
    }
    
    
    string response;
    if(attack == true && currentHealth[currentPokemon] !=0){
        attack = false;
        response = "a";
        //cin >> response;
    }
    else if(currentHealth[currentPokemon] == 0){
        for(int i =0; i<4; i++){
            if(i == 0){
                if(currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[1]/pokemonMaxHealth[1] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[2]/pokemonMaxHealth[2] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[3]/pokemonMaxHealth[3]){
                    if(currentPokemon != 0){
                        //attack = true;
                        return "s1";
                    }
                }
            }else if(i == 1){
                if(currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[0]/pokemonMaxHealth[0] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[2]/pokemonMaxHealth[2] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[3]/pokemonMaxHealth[3]){
                    if(currentPokemon != 1){
                        //attack = true;
                        return "s2";
                    }
                }
            }else if(i == 2){
                if(currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[1]/pokemonMaxHealth[1] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[0]/pokemonMaxHealth[0] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[3]/pokemonMaxHealth[3]){
                    if(currentPokemon != 2){
                        //attack = true;
                        return "s3";
                    }
                }
            }else if(i == 3){
                if(currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[1]/pokemonMaxHealth[1] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[2]/pokemonMaxHealth[2] && currentHealth[i]/pokemonMaxHealth[i] >= currentHealth[0]/pokemonMaxHealth[0]){
                    if(currentPokemon != 3){
                        //attack = true;
                        return "s4";
                    }
                }
            }
        }
    }
    else if(currentHealth[currentPokemon]/currentEDD > currentECH/baseAttack[currentPokemon]){
        response = "a";
    }
    else if(damageDoneToTeam[currentPokemon] > currentHealth[currentPokemon]/2){
        for(int i =0; i < 4; i++){
            if(pokemonStrength[i] == currentEAT){
                if(i == 0 && i != currentPokemon && currentHealth[i] >0){
                    attack = true;
                    return "s1";
                }
                else if(i == 1 && i != currentPokemon && currentHealth[i] >0){
                    attack = true;
                    return "s2";
                }
                else if(i == 2 && i != currentPokemon && currentHealth[i] >0){
                    attack = true;
                    return "s3";
                }
                else if(i == 3 && i != currentPokemon && currentHealth[i] >0){
                    attack = true;
                    return "s4";
                }
            }
        }
        for(int i = 0; i < 4; i++){
            if(damageDoneToTeam[i] < currentHealth[i]){
                if(i == 0 && i != currentPokemon && currentHealth[i] >0){
                    attack = true;
                    return "s1";
                }
                else if(i == 1 && i != currentPokemon && currentHealth[i] >0){
                    attack = true;
                    return "s2";
                }
                else if(i == 2 && i != currentPokemon && currentHealth[i] >0){
                    attack = true;
                    return "s3";
                }
                else if(i == 3 && i != currentPokemon && currentHealth[i] >0){
                    attack = true;
                    return "s4";
                }
            }
        }
        if(realDef != 0){
            return "db";
        }
        else{
            response = "a";
        }
        
    }
    else if(currentHealth[currentPokemon]/currentEDD > 2 && currentECH/2 <= baseAttack[currentPokemon]){
        attack = true;
        return "ab";
    }
    else if(currentHealth[currentPokemon] < pokemonMaxHealth[currentPokemon]){
        if(realPotion !=0){
            for(int i =0;i<4;i++){
                if(i==0 && currentHealth[1] ==0 && currentHealth[2]==0 && currentHealth[3] ==0){
                    return "po1";
                }
                if(i==1 && currentHealth[0] ==0 && currentHealth[2]==0 && currentHealth[3] ==0){
                    return "po2";
                }
                if(i==2 && currentHealth[0] ==0 && currentHealth[1]==0 && currentHealth[3] ==0){
                    return "po3";
                }
                if(i==3 && currentHealth[1] ==0 && currentHealth[2]==0 && currentHealth[0] ==0){
                    return "po4";
                }
            }
        }
    }else if(currentEDD < CreatureType::TYPES[currentPokemon].getHealthRestIncrease() && currentHealth[currentPokemon] < pokemonMaxHealth[currentPokemon]-currentEDD){
        return "r";
        
    }
    else if(currentHealth[currentPokemon] < damageDoneToTeam[currentPokemon]){
        if(realRevive > 0){
            for(int i = 0; i < 4; i++){
                if(currentHealth[i] == 0){
                    if(i==0){
                        return "re1";
                    }
                    if(i==1){
                        return "re2";
                    }
                    if(i==2){
                        return "re3";
                    }
                    if(i==3){
                        return "re4";
                    }

                }
            }
        }
    }
    else{
        response = "a";
    }
    
    
    //cout <<endl<< response << endl;
    response = "a";
    
    if(response == "a"){
        if(currentECH - baseAttack[currentPokemon] < 0){
            currentECH = 0;
            return "a";
        }
        else{
            currentECH -= baseAttack[currentPokemon];
            return "a";
        }
    }
    //cout << endl << baseAttack[currentPokemon] << endl;
    //cout << endl << currentEMH << " " << currentECH << endl;
    
    
    return response;
}


void Trainer::finalSituation(stringstream& situation) {
    cout << situation.str();
    
}



vector<string> Trainer::splitString(string inString, string splitOn) {
    vector<string> elements;
    string substring;
    
    size_t splitIndex = inString.find(splitOn),
    substrStart = 0;
    
    // keep searching until no spaces remain
    while (splitIndex != string::npos) {
        substring = inString.substr(substrStart, splitIndex - substrStart);
        elements.push_back(substring);
        substrStart = splitIndex + 1;
        // start at next character after finding substring
        splitIndex = inString.find(splitOn, substrStart);
    }
    // add last element to vector
    substring = inString.substr(substrStart, inString.length() - substrStart);
    elements.push_back(substring);
    
    return elements;
}