//
//  Class1.h
//  Class1
//
//  These class heaaders are for use in your Trainer class. If you wish to 
//  write helper classes, write them in these 5 classes. 
//  Use of these classes is optional. You may use none or any or all of them. 
//  You still may NOT #include any.h files we provide you
//  (Battle, Creature, CreatureType, EECSRandom, Party, PrintHelper)
//

#ifndef __CreatureTrainer__Class1__
#define __CreatureTrainer__Class1__
#include <iostream>
using namespace std;

// vvvvvv Your implementations go between this line…


class Pokemon{
    
public:
    Pokemon();
    string getPokemonName(int name);
    int getCurrentHealth(int health);
    int getMaxHealth(int maxHealth);
    int getDamageCreated(int d);
    
    
//private:
    
    string pokemonName;
    int currentHealth;
    int maxPHealth;
    int damageCreated;
    string pokemonType;
    string weakness;
    string strength;
    
    
    
};








// ^^^^^^ And this line. That's it!

#endif /* defined(__CreatureTrainer__Class1__) */
