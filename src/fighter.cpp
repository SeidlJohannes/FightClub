#include "fighter.h"
#include <string.h>
#include <iostream>
#include <iomanip>
#include "time.h"

using namespace std;

fighter::fighter()
{
    name = "none";
    health = 10;
    attribut1 = "none";
    attribut2 = "none";
    cout << "fighter without parameter constructed" << endl;
    wins = 0;
    losses = 0;
}

fighter::fighter(string name, string attribut1, string attribut2)
{
    this->name = name;
    health = 10;
    this->attribut1 = attribut1;
    this->attribut2 = attribut2;
    action = 'x';
    wins = 0;
    losses = 0;
    computer = true;
    //cout << "fighter constructed" << endl;
}

fighter::~fighter()
{
    //dtor
}

void fighter::getInfo(){
    cout << name << " has " << health << " health" << endl;
    //cout << "Health: " << health << " // Attribut1: " << attribut1 << " // Attribut2: " << attribut2 << endl;
}

void fighter::setComputer(int option){
    computer = option;
}

void fighter::tankAttribute(){
    if(attribut1 == "tank" || attribut2 == "tank"){
        health = 15;
    }
}


std::string fighter::getName(){
    return name;
}
void fighter::setName(std::string newName){
    this->name = newName;
}


int fighter::getHealth(){
    return health;
}
void fighter::setHealth(int newHealth){
    this->health = newHealth;
}


char fighter::getAction(){
    return action;
}
void fighter::setAction(char newAction){
    this->action = newAction;
}


int fighter::getWins(){
    return wins;
}
void fighter::setWins(int newWins){
    this->wins = newWins;
}


int fighter::getLosses(){
    return losses;
}
void fighter::setLosses(int newLosses){
    this->losses = newLosses;
}


char fighter::chooseAction(){
    action = 'x';
    while(action != 'h' && action != 'b' && action != 'p'){
        cout << "Choose your action: [h]hit, [b]block, [p]push" << endl;
        if(computer == true){
            //Choose random for the computer
            int probability = (rand()% 3) + 1; //(rand()% 3) makes number from 0-2
            if(probability == 1){
                action = 'h';
                cout << name << " chose hit" << endl;
            }
            else if(probability == 2){
                action = 'b';
                cout << name << " chose block" << endl;
            }
            else if(probability == 3){
                action = 'p';
                cout << name << " chose push" << endl;
            }
        }
        else{
            cin >> action;
        }
    }
    return action;
}

void fighter::hit(fighter *enemy){
    int dmg = 1;
    int probability = (rand()% 10) + 1; //(rand()% 10) makes number from 0-9
    if(attribut1 == "strong" || attribut2 == "strong"){
        if(probability < 3){
            dmg = 2;
            cout << "You are strong and do double damage" << endl;
        }
    }
    if(enemy->attribut1 == "intimidate" || enemy->attribut2 == "intimidate"){
        probability = (rand()% 10) + 1;
        if(probability < 3){
            dmg = 0;
            cout << "You are intimidated by your enemy and do no damage" << endl;
        }
    }
    if(enemy->attribut1 == "armor" || enemy->attribut2 == "armor"){
        probability = (rand()% 10) + 1;
        if(probability < 3){
            dmg = 0;
            cout << "You hit your enemy on his armor and do no damage" << endl;
        }
    }
    if(enemy->attribut1 == "regenerate" || enemy->attribut2 == "regenerate"){
        probability = (rand()% 10) + 1;
        if(probability < 3){
            health++;
            cout << "You used regenerate and gained one health" << endl;
        }
    }
    if(enemy->attribut1 == "killer" || enemy->attribut2 == "killer"){
        probability = (rand()% 100) + 1;
        if(probability < 3){
            dmg = 100;
            cout << "You just killed your enemy." << endl;
        }
    }
    enemy->setHealth(enemy->getHealth() - dmg);
}
