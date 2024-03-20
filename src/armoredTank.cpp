#include "armoredTank.h"
#include "fighter.h"
#include <iostream>
#include <string>


armoredTank::armoredTank() : fighter("armored Tank", "tank", "armor")
{
    //std::cout << "armoredTank constructed" << std::endl;
}

armoredTank::~armoredTank()
{
    //dtor
}
