#include "../include/Orc.h"
#include "../include/Visitor.h"

Orc::Orc(std::string n,int x,int y):NPC(n,x,y){}

std::string Orc::getType()const{return "Orc";}

void Orc::accept(NPCVisitor&v,NPC&e){v.fight(*this,e);}
