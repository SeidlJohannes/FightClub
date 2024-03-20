#include "manager.h"
#include "fighter.h"
#include "armoredTank.h"
#include "intimidatingKiller.h"
#include "killerTank.h"
#include "strongRegenerator.h"
#include <iostream>
#include <string>
#include "time.h"

using namespace std;

manager::manager()
{
    fighterCount = 2;
}

manager::~manager()
{
    //dtor
}

void manager::showStats(fighter *allFighters[10]){
    for(int i = 0; i < fighterCount; i++){
        cout << i + 1 << ". Fighter: " << allFighters[i]->getName() << endl;
        cout << "    Wins: " << allFighters[i]->getWins() << endl;
        cout << "    Losses: " << allFighters[i]->getLosses() << endl;
    }
}

int manager::createNewFighter(fighter *allFighters[10]){
    string inputName = "";
    int chosenAtt = 0;
    string inputAtt1;
    string inputAtt2;
    while(inputName == ""){
        cout << "Give your new Fighter a name: " << endl;
        cin >> inputName;
    }
    while(chosenAtt < 1 || chosenAtt > 6){
        cout << "Choose your first attribute: " << endl;
        cout << "[1] TANK: gives you 50% more health " << endl;
        cout << "[2] ARMOR: gives you a 20% chance to tank a hit " << endl;
        cout << "[3] STRONG: gives you a 20% chance for enemy to miss " << endl;
        cout << "[4] INTIMIDATE: gives you a 20% chance for enemy to miss " << endl;
        cout << "[5] KILLER: gives you a 2% chance to oneshot your enemy " << endl;
        cout << "[6] REGENERATE: gives you a 20% chance to see the enemy move " << endl;
        cin >> chosenAtt;
    }
    switch(chosenAtt){
        case 1:
            inputAtt1 = "tank";
            break;
        case 2:
            inputAtt1 = "armor";
            break;
        case 3:
            inputAtt1 = "strong";
            break;
        case 4:
            inputAtt1 = "intimidate";
            break;
        case 5:
            inputAtt1 = "killer";
            break;
        case 6:
            inputAtt1 = "regenerate";
            break;
    }
    chosenAtt = 0;
    while(chosenAtt < 1 || chosenAtt > 6){
        cout << "Choose your second attribute: " << endl;
        cout << "[1] TANK: gives you 50% more health " << endl;
        cout << "[2] ARMOR: gives you a 20% chance to tank a hit " << endl;
        cout << "[3] STRONG: gives you a 20% chance for enemy to miss " << endl;
        cout << "[4] INTIMIDATE: gives you a 20% chance for enemy to miss " << endl;
        cout << "[5] KILLER: gives you a 2% chance to oneshot your enemy " << endl;
        cout << "[6] REGENERATE: gives you a 20% chance to see the enemy move " << endl;
        cin >> chosenAtt;
    }
    switch(chosenAtt){
        case 1:
            inputAtt2 = "tank";
            break;
        case 2:
            inputAtt2 = "armor";
            break;
        case 3:
            inputAtt2 = "strong";
            break;
        case 4:
            inputAtt2 = "intimidate";
            break;
        case 5:
            inputAtt2 = "killer";
            break;
        case 6:
            inputAtt2 = "regenerate";
            break;
    }
    allFighters[fighterCount] = new fighter(inputName, inputAtt1, inputAtt2);
    fighterCount++;
    return fighterCount - 1;
}

int manager::chooseFromFighters(fighter *allFighters[10], int first){
    int input = 99;
    for(int i = 0; i < fighterCount; i++){
        cout << i + 1 << ". Fighter: " << allFighters[i]->getName() << endl;
    }
    while(input > fighterCount || input < 1 || input == first + 1){
        cout << "Choose between fighter 1-" << fighterCount << endl;
        cin >> input;
        if(input == first + 1){
            cout << "You already chose this fighter" << endl;
        }
    }
    return input - 1;
}

void manager::takeAction(fighter *allFighters[10], int first, int second){
    if(allFighters[first]->getAction() == 'h' && allFighters[second]->getAction() == 'h'){
        allFighters[first]->hit(allFighters[second]);
        allFighters[second]->hit(allFighters[first]);
        allFighters[first]->getInfo();
        allFighters[second]->getInfo();
    }
    else if(allFighters[first]->getAction() == 'h' && allFighters[second]->getAction() == 'p'){
        allFighters[first]->hit(allFighters[second]);
        allFighters[first]->getInfo();
        allFighters[second]->getInfo();
    }
    else if(allFighters[first]->getAction() == 'h' && allFighters[second]->getAction() == 'b'){
        cout << "Fighter two threw player one off balance and hit him" << endl;
        allFighters[second]->hit(allFighters[first]);
        allFighters[first]->getInfo();
        allFighters[second]->getInfo();
    }
    else if(allFighters[first]->getAction() == 'b' && allFighters[second]->getAction() == 'h'){
        cout << "Fighter one blocked player twos hit and hit him" << endl;
        allFighters[first]->hit(allFighters[second]);
        allFighters[first]->getInfo();
        allFighters[second]->getInfo();
    }
    else if(allFighters[first]->getAction() == 'b' && allFighters[second]->getAction() == 'b'){
        cout << "Nothing happens" << endl;
        allFighters[first]->getInfo();
        allFighters[second]->getInfo();
    }
    else if(allFighters[first]->getAction() == 'b' && allFighters[second]->getAction() == 'p'){
        cout << "Fighter two threw player one off balance and hit him" << endl;
        allFighters[second]->hit(allFighters[first]);
        allFighters[first]->getInfo();
        allFighters[second]->getInfo();
    }
    else if(allFighters[first]->getAction() == 'p' && allFighters[second]->getAction() == 'h'){
        allFighters[second]->hit(allFighters[first]);
        allFighters[first]->getInfo();
        allFighters[second]->getInfo();
    }
    else if(allFighters[first]->getAction() == 'p' && allFighters[second]->getAction() == 'b'){
        cout << "Fighter one threw player two off balance and hit him" << endl;
        allFighters[first]->hit(allFighters[second]);
        allFighters[first]->getInfo();
        allFighters[second]->getInfo();
    }
    else if(allFighters[first]->getAction() == 'p' && allFighters[second]->getAction() == 'p'){
        cout << "Nothing happens" << endl;
        allFighters[first]->getInfo();
        allFighters[second]->getInfo();
    }
}

void manager::startFight(fighter *allFighters[10], int first, int second){
    srand(time(NULL));
    //Reset all fighter health and tank
    for(int i = 0; i < fighterCount; i++){
        allFighters[i]->setHealth(10);
        allFighters[i]->tankAttribute();
    }

    int isComp = 99;
    while(isComp != 1 && isComp != 0){
        cout << "Do you want " << allFighters[first]->getName() << " to be played by the computer? Yes[1] or No[0]?" << endl;
        cin >> isComp;
    }
    if(isComp == 0){
        allFighters[first]->setComputer(isComp);
    }
    isComp = 99;
    while(isComp != 1 && isComp != 0){
        cout << "Do you want " << allFighters[second]->getName() << " to be played by the computer? Yes[1] or No[0]?" << endl;
        cin >> isComp;
    }
    if(isComp == 0){
        allFighters[second]->setComputer(isComp);
    }

    while(allFighters[first]->getHealth() > 0 && allFighters[second]->getHealth() > 0){
        cout << endl << "FIGHTER 1: " << allFighters[first]->getName() << endl;
        allFighters[first]->chooseAction();
        cout << "FIGHTER 2: " << allFighters[second]->getName() << endl;
        allFighters[second]->chooseAction();

        takeAction(allFighters, first, second);
    }
    if(allFighters[first]->getHealth() < 1){
        cout << endl << allFighters[second]->getName() << " WON THE MATCH!" << endl;
        allFighters[second]->setWins(allFighters[second]->getWins() + 1);
        allFighters[first]->setLosses(allFighters[first]->getLosses() + 1);
    }
    else {
        cout << endl << allFighters[first]->getName() << " WON THE MATCH!" << endl;
        allFighters[first]->setWins(allFighters[first]->getWins() + 1);
        allFighters[second]->setLosses(allFighters[second]->getLosses() + 1);
    }
    allFighters[first]->setHealth(15);
    allFighters[second]->setHealth(10);
}

void manager::startGame(){
    //initialize fighter array and 2 fighters
    fighter* allFighters[10];
    allFighters[0] = new armoredTank();
    allFighters[1] = new intimidatingKiller();
    //allFighters[2] = new strongRegenerator();
    //allFighters[3] = new killerTank();
    int firstChosenFighter = 99;
    int secondChosenFighter = 99;
    int input = 99;
    cout << "This is fight club." << endl;
    cout << "The game is based on a rock, paper, scissors system with an addition of different skills" << endl;
    while(input != 1 && input != 0){
        cout << "Press 1 to play the game or press 0 to exit" << endl;
        cout << "You can also press 2 to see the fighters stats" << endl;
        cin >> input;
        if(input == 1){
            input = 0;
            while(input != 1 && input != 2){
                cout << endl << "Choose your first fighter." << endl;
                cout << "Enter 1 if you want to use an existing fighter" << endl;
                cout << "or 2 if you want to create a new fighter" << endl;
                cin >> input;
                if(input == 1){
                    firstChosenFighter = chooseFromFighters(allFighters, firstChosenFighter);
                }
                else if(input == 2){
                    firstChosenFighter = createNewFighter(allFighters);
                }
            }
            input = 99;
            while(input != 1 && input != 2){
                cout << "Choose your second fighter." << endl;
                cout << "Enter 1 if you want to use an existing fighter" << endl;
                cout << "or 2 if you want to create a new fighter" << endl;
                cin >> input;
                if(input == 1){
                    secondChosenFighter = chooseFromFighters(allFighters, firstChosenFighter);
                }
                else if(input == 2){
                    secondChosenFighter = createNewFighter(allFighters);
                }
            }
            startFight(allFighters, firstChosenFighter, secondChosenFighter);
            input = 99;
        }
        else if(input == 2){
            showStats(allFighters);
        }
    }
    for(int i = 0; i < fighterCount; i++){
        delete allFighters[i];
    }
    cout << "Auf Wiedersehen!" << endl;
}
