#pragma once
#include "NPC.h"
class NPCVisitor{public:virtual bool fight(NPC&a,NPC&b)=0;};
class FightVisitor:public NPCVisitor{public:bool fight(NPC&a,NPC&b)override;};
