#ifndef MANAGER_H
#define MANAGER_H
#include "fighter.h"

class manager
{
    public:
        manager();
        virtual ~manager();
        void showStats(fighter *allFighters[10]);
        int createNewFighter(fighter *allFighters[10]);
        int chooseFromFighters(fighter *allFighters[10], int first);
        void takeAction(fighter *allFighters[10], int first, int second);
        void startFight(fighter *allFighters[10], int first, int second);
        void startGame();

    protected:

    private:
        int fighterCount;
};

#endif // MANAGER_H
