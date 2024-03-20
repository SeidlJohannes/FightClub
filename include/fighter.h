#ifndef FIGHTER_H
#define FIGHTER_H
#include <string>


class fighter
{
    public:
        fighter();
        fighter(std::string name, std::string attribut1, std::string attribut2);
        virtual ~fighter();
        void getInfo();
        void setComputer(int option);
        void tankAttribute();
        std::string getName();
        void setName(std::string name);
        int getHealth();
        void setHealth(int health);
        char getAction();
        void setAction(char action);
        int getWins();
        void setWins(int wins);
        int getLosses();
        void setLosses(int losses);
        char chooseAction();
        void hit(fighter* enemy);

    protected:
        std::string name;
        int health;
        std::string attribut1;
        std::string attribut2;
        char action;
        int wins;
        int losses;
        bool computer;

    private:
};

#endif // FIGHTER_H
