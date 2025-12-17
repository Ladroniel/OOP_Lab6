#pragma once
#include "NPC.h"
class Orc : public NPC {
public:
    Orc(std::string n,int x,int y);
    std::string getType() const override;
    void accept(NPCVisitor &v,NPC &enemy) override;
};