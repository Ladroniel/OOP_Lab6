#pragma once
#include "NPC.h"
class Bear : public NPC {
public:
    Bear(std::string n,int x,int y);
    std::string getType() const override;
    void accept(NPCVisitor &v,NPC &enemy) override;
};
