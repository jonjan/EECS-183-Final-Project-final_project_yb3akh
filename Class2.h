//
//  Class2.h
//  Class2
//
//  These class heaaders are for use in your Trainer class. If you wish to 
//  write helper classes, write them in these 5 classes. 
//  Use of these classes is optional. You may use none or any or all of them. 
//  You still may NOT #include any.h files we provide you
//  (Battle, Creature, CreatureType, EECSRandom, Party, PrintHelper)
//

#ifndef __CreatureTrainer__Class2__
#define __CreatureTrainer__Class2__
#include <iostream>
using namespace std;


// vvvvvv Your implementations go between this line�


class Enemy{
public:
    string enemyName;
    string enemyType;
    string weakness;
    string strength;
    int enemyDamage;
    int maxHealth;
    Enemy();
};



class DataBase{

public:
    Enemy enemies[1000];
    int currentSize;
    DataBase();
    
    
};




// ^^^^^^ And this line. That's it!

#endif /* defined(__CreatureTrainer__Class2__) */
