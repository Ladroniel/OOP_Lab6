#pragma once
#include <vector>
#include <memory>
#include "NPC.h"
#include "Visitor.h"
#include "Observers.h"
#include "Factory.h"
class Game{
private:
    std::vector<std::shared_ptr<NPC>>npcs;
    FightVisitor fightVisitor;
    std::vector<Observer*>observers;
public:
    Game();
    void addNPC();void listNPC();void save();void load();void fight();
    void notify(const std::string&,const std::string&);
    void runMenu();
};