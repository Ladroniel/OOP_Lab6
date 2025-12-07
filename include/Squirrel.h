#pragma once
#include "NPC.h"
class Squirrel : public NPC {
public:
    Squirrel(std::string n,int x,int y);
    std::string getType() const override;
    void accept(NPCVisitor &v,NPC &enemy) override;
};
